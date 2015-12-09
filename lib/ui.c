#include "../include/ui.h"

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
static void print_all_buses();
static void print_all_depots();
static void print_all_buses_with_refs();


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
        prt(BLANK_LINE);
        prt(BOLD_LINE);
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
    if (is_agree())
        load_database_from("Dane.txt");
    prt(CLS);
}

void scan_to_buf()
{
    scanf(" %255[^\n]", buffer);
}

int is_agree()
{
    if ((buffer[0] == 't' || buffer[0] == 'T') &&
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
        modified = 0;
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void editing_data_menu()
{
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
    while (1) {
        prt(BUS_OR_DEPOT);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero()) {
            prt(CLS);
            return;
        }
        if (!is_number(buffer)) {
            prt(LINE);
            prt(NOT_A_NUMBER);
            continue;
        }
        else
            break;
    }
    prt(CLS);

    op_type = atoi(buffer);
    switch (op_type)
    {
    case 1:
        add_bus_dialog();
        modified = 1;
        break;
    case 2:
        add_depot_dialog();
        modified = 1;
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
    prt(BOLD_LINE);
    prt(BLANK_LINE);
}

void add_bus_dialog()
{
    char side_no[256], line_no[256], pesel[256];
    print_all_buses();
    prt(TYPE_BUS_SIDE_NO);
    scan_to_buf();
    if (!is_number(buffer)) {
        prt(NOT_A_NUMBER);
        return;
    }
    strcpy(side_no, buffer);

    prt(TYPE_BUS_LINE_NO);
    scan_to_buf();
    if (!is_number(buffer)) {
        prt(NOT_A_NUMBER);
        return;
    }
    strcpy(line_no, buffer);

    prt(TYPE_BUS_DRIVER_PESEL);
    scan_to_buf();
    if (!is_number(buffer)) {
        prt(NOT_A_NUMBER);
        return;
    }
    strcpy(pesel, buffer);

    prt(TYPE_BUS_DRIVER_NAME);
    scan_to_buf();

    add_bus(side_no, line_no, buffer, pesel);
}

void add_depot_dialog()
{
    print_all_depots();
    prt(TYPE_DEPOT_NAME);
    scan_to_buf();
    add_depot(buffer);
}

void edit_bus_or_depot()
{
    int op_type;
    while (1) {
        prt(BUS_OR_DEPOT);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero()) {
            prt(CLS);
            return;
        }
        if (!is_number(buffer)) {
            prt(LINE);
            prt(NOT_A_NUMBER);
            continue;
        }
        else
            break;
    }
    prt(CLS);
    op_type = atoi(buffer);
    switch (op_type)
    {
    case 1:
        edit_bus_dialog();
        modified = 1;
        break;
    case 2:
        edit_depot_dialog();
        modified = 1;
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void edit_bus_dialog()
{
    int side_no, edit_type;
    Bus *the_bus;
    print_all_buses();
    prt(TYPE_BUS_SIDE_NO_TO_EDIT);
    scan_to_buf();
    if (is_zero()) {
        prt(CLS);
        return;
    }
    if (!is_number(buffer)) {
        prt(CLS);
        prt(NOT_A_NUMBER);
        return;
    }
    side_no = atoi(buffer);
    prt(CLS);
    the_bus = find_object_with_item_in(&buses, &side_no, get_side_no, side_no_cmp);
    if (!the_bus)
        return;

    while (1) {
        print_bus_labels();
        print_bus_info(the_bus);
        prt(LINE);
        prt(WHAT_U_WANT_TO_EDIT);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero()) {
            prt(CLS);
            return;
        }
        if (!is_number(buffer)){
            prt(CLS);
            prt(NOT_A_NUMBER);
            continue;
        }
        edit_type = atoi(buffer);

        switch (edit_type)
        {
        case 1:
            prt(CURRENT);
            printf("%04d\n", the_bus->side_no);
            prt(NEW);
            scan_to_buf();
            prt(CLS);
            /* if edited successfully - find new place for side_no name (sort) */
            if (edit_bus_side_no(the_bus, buffer)) {
                remove_from(&buses, the_bus, del_node_only);
                append_to(&buses, the_bus, buses_side_no_cmp);
            }
            break;
        case 2:
            prt(CURRENT);
            printf("%d\n", the_bus->line_no);
            prt(NEW);
            scan_to_buf();
            prt(CLS);
            edit_bus_line_no(the_bus, buffer);
            break;
        case 3:
            prt(CURRENT);
            printf("%s\n", the_bus->driver_pesel);
            prt(NEW);
            scan_to_buf();
            prt(CLS);
            edit_bus_driver_pesel(the_bus, buffer);
            break;
        case 4:
            prt(CURRENT);
            printf("%s\n", the_bus->driver_name);
            prt(NEW);
            scan_to_buf();
            prt(CLS);
            edit_bus_driver_name(the_bus, buffer);
            break;
        default:
            prt(CLS);
            prt(INVALID_OPTION);
            break;
        } /* switch */
        modified = 1;
    } /* while */
}

void edit_depot_dialog()
{
    Depot *the_depot;
    print_all_depots();
    prt(TYPE_DEPOT_NAME_TO_EDIT);
    scan_to_buf();
    if (is_zero()) {
        prt(CLS);
        return;
    }
    prt(CLS);
    the_depot = find_object_with_item_in(&depots, buffer, get_depot_name, names_cmp);
    if (!the_depot)
        return;

    prt(CURRENT);
    printf("%s\n", the_depot->name);
    prt(NEW);
    scan_to_buf();
    prt(CLS);
    /* if edited successfully - find new place for new name (sort) */
    if (edit_depot_name(the_depot, buffer)) {
        remove_from(&depots, the_depot, del_node_only);
        append_to(&depots, the_depot, depots_names_cmp);
    }
    modified = 1;
}

void del_bus_or_depot()
{
    int op_type;
    while (1) {
        prt(BUS_OR_DEPOT);
        prt(CHOOSE_OPT);
        scan_to_buf();
        if (is_zero()) {
            prt(CLS);
            return;
        }
        if (!is_number(buffer)) {
            prt(LINE);
            prt(NOT_A_NUMBER);
            continue;
        }
        else
            break;
    }
    prt(BOLD_LINE);
    prt(BLANK_LINE);

    op_type = atoi(buffer);
    switch (op_type)
    {
    case 1:
        del_bus_dialog();
        modified = 1;
        break;
    case 2:
        del_depot_dialog();
        modified = 1;
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void del_bus_dialog()
{
    int side_no;
    Bus *the_bus;
    print_all_buses();
    prt(TYPE_BUS_SIDE_NO_TO_DEL);
    scan_to_buf();
    if (is_zero()) {
        prt(CLS);
        return;
    }
    if (!is_number(buffer)) {
        prt(CLS);
        prt(NOT_A_NUMBER);
        return;
    }
    side_no = atoi(buffer);
    prt(CLS);
    the_bus = find_object_with_item_in(&buses, &side_no, get_side_no, side_no_cmp);
    if (!the_bus)
        return;
    remove_bus(the_bus);
    modified = 1;
}

void del_depot_dialog()
{
    Depot *the_depot;
    print_all_depots();
    prt(TYPE_DEPOT_NAME_TO_EDIT);
    scan_to_buf();
    if (is_zero()) {
        prt(CLS);
        return;
    }
    prt(CLS);
    the_depot = find_object_with_item_in(&depots, buffer, get_depot_name, names_cmp);
    if (!the_depot)
        return;
    remove_depot(the_depot);
    modified = 1;
}

void add_del_edit_refs_menu()
{
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
    print_bus_labels();
    print_all_buses_with_refs();
    print_all_depots();
    switch (op_type)
    {
    case 1:
        assign_dialog();
        modified = 1;
        break;
    case 2:
        del_assign_dialog();
        modified = 1;
        break;
    case 3:
        move_assign_dialog();
        modified = 1;
        break;
    default:
        prt(INVALID_OPTION);
        prt(LINE);
        break;
    }
}

void assign_dialog()
{
    int side_no;
    prt(ADD_ASSIGNMENT);
    prt(TYPE_BUS_SIDE_NO);
    scan_to_buf();
    if (!is_number(buffer)) {
        prt(NOT_A_NUMBER);
        return;
    }
    side_no = atoi(buffer);

    prt(TYPE_DEPOT_NAME);
    scan_to_buf();
    prt(CLS);
    assign_to(buffer, side_no);
}

void del_assign_dialog()
{
    int side_no;
    prt(DEL_ASSIGNMENT);
    prt(TYPE_BUS_SIDE_NO);
    scan_to_buf();
    if (!is_number(buffer)) {
        prt(NOT_A_NUMBER);
        return;
    }
    side_no = atoi(buffer);

    prt(TYPE_DEPOT_NAME);
    scan_to_buf();
    prt(CLS);
    remove_assignment_from(buffer, side_no);
}

void move_assign_dialog()
{
    int side_no;
    char first_depot[256];
    prt(MV_ASSIGNMENT);
    prt(TYPE_BUS_SIDE_NO);
    scan_to_buf();
    if (!is_number(buffer)) {
        prt(NOT_A_NUMBER);
        return;
    }
    side_no = atoi(buffer);
    prt(FROM_DEPOT);
    scan_to_buf();
    strcpy(first_depot, buffer);
    prt(TO_DEPOT);
    scan_to_buf();
    prt(CLS);
    move_to(first_depot, side_no, buffer);
}

void printing_data_menu()
{
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
        print_all_buses_with_refs();
        break;
    case 2:
        print_all_depots();
        break;
    case 3:
        print_one_chose_depot_dialog();
        prt(LINE);
        break;
    case 4:
        buses_filtering_dialog();
        prt(LINE);
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void print_one_chose_depot_dialog()
{
    print_all_depots();
    prt(CHOOSE_DEPOT_TO_PRINT);
    scan_to_buf();
    prt(BLANK_LINE);
    print_filtered_by(DEPOT_NAME, buffer);
}

void buses_filtering_dialog()
{
    int filter_type, int_val;
    prt(TYPES_OF_BUSES_FILTERING);
    prt(CHOOSE_OPT);
    scan_to_buf();
    if (is_zero())
        return;
    if (!is_number(buffer)) {
        prt(NOT_A_NUMBER);
        return;
    }
    filter_type = atoi(buffer);
    prt(LINE);
    prt(BLANK_LINE);
    print_all_buses();
    prt(TYPE_VALUE_OF_FIELD);
    scan_to_buf();
    prt(BLANK_LINE);

    print_bus_labels();
    switch (filter_type)
    {
    case 1:
        if (!is_number(buffer)) {
            prt(NOT_A_NUMBER);
            return;
        }
        int_val = atoi(buffer);
        print_filtered_by(SIDE_NO, &int_val);
        break;
    case 2:
        if (!is_number(buffer)) {
            prt(NOT_A_NUMBER);
            return;
        }
        int_val = atoi(buffer);
        print_filtered_by(LINE_NO, &int_val);
        break;
    case 3:
        if (!is_number(buffer)) {
            prt(NOT_A_NUMBER);
            return;
        }
        print_filtered_by(DRIVER_PESEL, buffer);
        break;
    case 4:
        print_filtered_by(DRIVER_NAME, buffer);
        break;
    default:
        prt(INVALID_OPTION);
        break;
    }
}

void print_all_buses()
{
    print_bus_labels();
    for_each_in(&buses, print_bus_info);
    prt(LINE);
}

void print_all_buses_with_refs()
{
    print_bus_labels();
    for_each_in(&buses, print_bus_info_with_refs);
    prt(LINE);
}

static void print_all_depots()
{
    prt(DEPOTS_LABEL);
    for_each_in(&depots, print_depot_info);
    prt(LINE);
}
