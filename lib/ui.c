#include "../include/ui.h"


static int modified;
static char buffer[256];
static void scan_to_buf();
static void load_prev_data();
static int is_agree();
static int is_zero();
static void choose_type_of_procedure();
static void add_del_edit_data();
static void add_del_edit_refs();
static void printing_data();

void start_program()
{
    prt(CLS);
    prt(WELCOME);
    load_prev_data();
    while (1) { /* main loop */
        prt(MAIN_MENU);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero())
            break;
        choose_type_of_procedure();
    }

    if (modified) {
        prt(DATA_HAS_BEEN_MODIFIED);
        scan_to_buf();
        if (is_agree())
            dump_database_to("Dane.txt");
    }
    clean_up_mem();
    prt(EXITING);
}

void load_prev_data()
{
    prt(LOAD_FROM_FILE);
    scan_to_buf();
    prt(CLS);
    if (is_agree())
        load_database_from("Dane.txt");
}

void scan_to_buf()
{
    scanf(" %255[^\n]", buffer);
}

int is_agree()
{
    if ((buffer[0] == 'y' || buffer[0] == 'Y') &&
        strlen(buffer) == 1)
        return 1;
    return 0;
}

int is_zero()
{
    if (buffer[0] == '0' && strlen(buffer) == 1)
        return 1;
    return 0;
}

void choose_type_of_procedure()
{
    int op_type;
    if (!is_number(buffer)) {
        prt(NOT_A_NUMBER);
        return;
    }
    prt(CLS);
    op_type = atoi(buffer);
    switch (op_type)
    {
    case 1:
        add_del_edit_data();
        break;
    case 2:
        add_del_edit_refs();
        break;
    case 3:
        printing_data();
        break;
    case 4:
        dump_database_to("Dane.txt");
        break;
    case default:
        prt(INVALID_OPTION);
        break;
    }
}

void add_del_edit_data()
{
    prt(BOLD_LINE);
    prt(MODIFYING_DATA_MENU);
    prt(CHOOSE_OPT);
    scan_to_buf();
}
