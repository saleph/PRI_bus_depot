#include "../include/data_loader.h"


static FILE *file_hook;
static int is_blank(char*);
static int is_comment(char*);
static int has_bus(char*);
static int has_depot(char*);
static void parse_bus(char*);
static void parse_depot(char*);
static void del_loaded_data();

static char *parse_side_no(char*);
static char *parse_line_no(char*);
static char *parse_driver_name(char*);
static char *parse_driver_pesel(char*);
static char *parse_depot_name(char*);
static char *parse_bus_as_ref(char*);


void load_database_from(const char* filename)
{
    char *line, buffer[BUFFER_SIZE];
    file_hook = fopen(filename, "r");
    if (!file_hook) {
        msg(OPENING_FILE_FAILED);
        return;
    }

    while (!feof(file_hook)) {
        line = fgets(buffer, BUFFER_SIZE, file_hook);
        if (!line)
            continue;
        else if (is_blank(line) || is_comment(line))
            continue;
        else if (has_bus(line))
            parse_bus(line);
        else if (has_depot(line))
            parse_depot(line);
        else {
            msg(FILE_DAMAGED);
            del_loaded_data();
            break;
        }
    }
    msg(LOAD_SUCCESSFUL);
    fclose(file_hook);
}

int is_blank(char* line)
{
    if (*line == '\n')
        return 1;
    return 0;
}

int is_comment(char* line)
{
    if (line[0] == '#')
        return 1;
    return 0;
}

int has_bus(char* line)
{
    if (line[0] == 'b')
        return 1;
    return 0;
}

int has_depot(char* line)
{
    if (line[0] == 'd')
        return 1;
    return 0;
}

void parse_bus(char* line)
{
    char *token, *side_no, *line_no, *driver_name, *driver_pesel;
    char delim[2] = ",";

    token = strtok(line, delim);
    side_no = parse_side_no(token);
    token = strtok(NULL, delim);
    line_no = parse_line_no(token);
    token = strtok(NULL, delim);
    driver_name = parse_driver_name(token);
    token = strtok(NULL, delim);
    driver_pesel = parse_driver_pesel(token);

    add_bus(side_no, line_no, driver_name, driver_pesel);
}

char *parse_side_no(char* token)
{
    unsigned int i;
    for (i=0; i<strlen(token); i++) {
        if (token[i] != 'b' && token[i] != ':' && token[i] != ' ') {
            if (token[strlen(token)-1] == ' ')
                token[strlen(token)-1] = '\0';
            /* skip first spaces, b and colon */
            return (token + i);
        }
    }
    return NULL;
}

char *parse_line_no(char* token)
{
    unsigned int i;
    for (i=0; i<strlen(token); i++) {
        if (token[i] != ' ') {
            if (token[strlen(token)-1] == ' ')
                token[strlen(token)-1] = '\0';
            /* skip first spaces */
            return (token + i);
        }
    }
    return NULL;
}

char *parse_driver_name(char* token)
{
    unsigned int i;
    for (i=0; i<strlen(token); i++) {
        if (token[i] != ' ') {
            if (token[strlen(token)-1] == ' ')
                token[strlen(token)-1] = '\0';
            /* skip first spaces */
            return (token + i);
        }
    }
    return NULL;
}

char *parse_driver_pesel(char* token)
{
    unsigned int i;
    for (i=0; i<strlen(token); i++) {
        if (token[i] != ' ') {
            if (token[strlen(token)-1] == '\n')
                token[strlen(token)-1] = '\0';
            /* skip first spaces */
            return (token + i);
        }
    }
    return NULL;
}

void parse_depot(char* line)
{
    char *token, *depot_name;
    char delim[2] = ",";
    int bus_no;

    token = strtok(line, delim);
    depot_name = parse_depot_name(token);
    add_depot(depot_name);

    /* create assignments */
    token = strtok(NULL, delim);
    while (token){
        bus_no = atoi(parse_bus_as_ref(token));
        assign_to(depot_name, bus_no);
        token = strtok(NULL, delim);
    }
}

char *parse_depot_name(char* token)
{
    unsigned int i;
    for (i=0; i<strlen(token); i++) {
        if (token[i] != 'd' && token[i] != ':' && token[i] != ' ') {
            if (token[strlen(token)-1] == ' ')
                token[strlen(token)-1] = '\0';
            /* skip first spaces, b and colon */
            return (token + i);
        }
    }
    return NULL;
}

char *parse_bus_as_ref(char* token)
{
    unsigned int i;
    for (i=0; i<strlen(token); i++) {
        if (token[i] != ' ') {
            if (token[strlen(token)-1] == ' ' || token[strlen(token)-1] == '\n')
                token[strlen(token)-1] = '\0';
            /* skip first spaces */
            return (token + i);
        }
    }
    return NULL;
}

void del_loaded_data()
{
    delete_list(&buses, del_bus);
    delete_list(&depots, del_depot);
}
