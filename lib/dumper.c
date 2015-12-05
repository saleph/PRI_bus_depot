#include "../include/dumper.h"


static FILE *file_hook;
static void dump_bus(void*);
static void dump_depot(void*);
static void dump_bus_as_ref(void*);

static void start_comments();
static void buses_now_comment();
static void depots_now_comment();


int dump_data_to(const char* filename)
{
    file_hook = fopen(filename, "w");
    if (!file_hook) {
        msg(FILE_OPEN_FAILED);
        return 0;
    }
    start_comments();

    buses_now_comment();
    do_for_each_in(&buses, dump_bus);

    depots_now_comment();
    do_for_each_in(&depots, dump_depot);

    fclose(file_hook);
    return 1;
}

void buses_now_comment()
{
    fprintf(file_hook, "# ================== Buses ==================\n");
    fprintf(file_hook, "# b: <side no>, <line no>, <driver name>, <driver pesel>;\n");
    fprintf(file_hook, "\n");
}

void dump_bus(void* the_bus_ptr)
{
    Bus *the_bus;
    the_bus = (Bus*)the_bus_ptr;
    fprintf(file_hook, "b: %d, %d, %s, %s;\n", the_bus->side_no,
            the_bus->line_no, the_bus->driver_name, the_bus->driver_pesel);
}

void depots_now_comment()
{
    fprintf(file_hook, "\n");
    fprintf(file_hook, "# ================== Depots =================\n");
    fprintf(file_hook, "# d: <depot name>, <side no of bus 1>,..., <side no of bus n>;\n");
    fprintf(file_hook, "\n");
}

void dump_depot(void* the_depot_ptr)
{
    Depot *the_depot;
    the_depot = (Depot*)the_depot_ptr;
    fprintf(file_hook, "d: %s", the_depot->name);
    do_for_each_in(&(the_depot->members), dump_bus_as_ref);
    fprintf(file_hook, ";\n");
}

void dump_bus_as_ref(void* the_bus_ptr)
{
    Bus *the_bus;
    the_bus = (Bus*)the_bus_ptr;
    fprintf(file_hook, ", %d", the_bus->side_no);
}

void start_comments()
{
    fprintf(file_hook, "# This is the comment line. Comments will be ignored during parsing\n");
    fprintf(file_hook, "# Record with a BUS starts with 'b:'\n");
    fprintf(file_hook, "# Record with a DEPOT starts with 'd:'\n");
    fprintf(file_hook, "# Fields in each record has to be separated by ',' (comma) and ends with ';' (semicolon)\n");
    fprintf(file_hook, "\n\n");
}

void backup(const char* filename)
{
    char new_filename[128];
    strcpy(new_filename, filename);
    strcat(new_filename, ".backup");
    rename(filename, new_filename);
}
