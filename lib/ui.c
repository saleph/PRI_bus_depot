#include "../include/ui.h"

static void print_bus_info_wo_refs();
static void print_depot_info_wo_refs();

static int modified;
static char buffer[256];

static int is_agree();
static int is_zero();
static void scan_to_buf();
static void load_prev_data();
static void choose_type_of_procedure();
static void editing_data_menu();
static void add_del_edit_refs_menu();
static void printing_data_menu();
static void choose_type_of_data_edit();
static void choose_type_of_refs_edit();
static void add_bus_or_depot();
static void edit_bus_or_depot();
static void del_bus_or_depot();
static void add_bus_dialog();
static void add_depot_dialog();
static void assign_dialog();
static void del_assign_dialog();
static void move_assign_dialog();
static void choose_type_of_printing();
static void print_one_chose_depot_dialog();
static void buses_filtering_dialog();
static void edit_depot_dialog();
static void edit_bus_dialog();
static void del_bus_dialog();
static void del_depot_dialog();


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
        editing_data_menu();
        break;
    case 2:
        add_del_edit_refs_menu();
        break;
    case 3:
        printing_data_menu();
        break;
    case 4:
        dump_database_to("Dane.txt");
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void editing_data_menu()
{
    prt(BOLD_LINE);
    while (1) {
        prt(MODIFYING_DATA_MENU);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero())
            break;
        choose_type_of_data_edit();
    }
    prt(CLS);
}

void choose_type_of_data_edit()
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
        add_bus_or_depot();
        break;
    case 2:
        edit_bus_or_depot();
        break;
    case 3:
        del_bus_or_depot();
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void add_bus_or_depot()
{
    int op_type;
    prt(BOLD_LINE);
    while (1) {
        prt(BUS_OR_DEPOT);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero())
            return;
        if (!is_number(buffer)) {
            prt(LINE);
            prt(NOT_A_NUMBER);
            continue;
        }
    }

    op_type = atoi(buffer);
    switch (op_type)
    {
    case 1:
        add_bus_dialog();
        break;
    case 2:
        add_depot_dialog();
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void edit_bus_or_depot()
{
    int op_type;
    prt(BOLD_LINE);
    while (1) {
        prt(BUS_OR_DEPOT);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero())
            return;
        if (!is_number(buffer)) {
            prt(LINE);
            prt(NOT_A_NUMBER);
            continue;
        }
    }

    op_type = atoi(buffer);
    switch (op_type)
    {
    case 1:
        edit_bus_dialog();
        break;
    case 2:
        edit_depot_dialog();
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void del_bus_or_depot()
{
    int op_type;
    prt(BOLD_LINE);
    while (1) {
        prt(BUS_OR_DEPOT);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero())
            return;
        if (!is_number(buffer)) {
            prt(LINE);
            prt(NOT_A_NUMBER);
            continue;
        }
    }

    op_type = atoi(buffer);
    switch (op_type)
    {
    case 1:
        del_bus_dialog();
        break;
    case 2:
        del_depot_dialog();
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void add_del_edit_refs_menu()
{
    prt(BOLD_LINE);
    while (1) {
        prt(MODIFYING_REFERENCES_MENU);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero())
            break;
        choose_type_of_refs_edit();
    }
    prt(CLS);
}

void choose_type_of_refs_edit()
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
        assign_dialog();
        break;
    case 2:
        del_assign_dialog();
        break;
    case 3:
        move_assign_dialog();
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void printing_data_menu()
{
    prt(BOLD_LINE);
    while (1) {
        prt(PRINT_DATA_MENU);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero())
            break;
        choose_type_of_printing();
    }
    prt(CLS);
}

void choose_type_of_printing()
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
        for_each_in(&buses, print_bus_info_wo_refs);
        break;
    case 2:
        for_each_in(&depots, print_depot_info_wo_refs);
        break;
    case 3:
        print_one_chose_depot_dialog();
        break;
    case 4:
        buses_filtering_dialog();
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}
