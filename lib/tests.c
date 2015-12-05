#include "../include/tests.h"


static void create_data();
static void change_some_references();
static void test_filters();
static void print_data();

void create_data()
{
    add_bus("1", "11", "w", "11111111111");
    add_bus("1", "11", "a", "11111111111");
    add_bus("2", "11", "d", "11111111111");
    add_bus("1", "11", "h", "11111111111");
    add_bus("1", "11", "d", "11111231111");
    add_bus("2", "11", "c", "11111111111");
    add_bus("3", "11", "v", "21111551111");
    add_bus("4", "12", "b", "11111111111");
    add_bus("1", "13", "n", "11111116111");
    add_bus("1", "14", "k", "11111111111");
    add_bus("2", "15", "u", "11111111111");
    add_bus("1", "16", "y", "11111111111");
    add_bus("9", "17", "t", "11111111111");
    add_bus("5", "18", "w", "11115411111");
    add_bus("3", "11", "w", "11111111111");
    add_bus("4", "11", "q", "11111111111");
    add_bus("1", "11", "w", "11111111111");
    add_bus("8", "11", "w", "11111111111");
    add_bus("7", "11", "w", "11112111111");
    add_bus("1", "91", "w", "11111111111");
    add_bus("5", "17", "w", "11111111211");
    add_bus("6", "11", "w", "11111131111");
    add_bus("1", "11", "w", "11111141111");
    add_bus("4", "11", "w", "11111111111");
    add_bus("1", "11", "w", "11111111711");

    add_depot("a");
    add_depot("e");
    add_depot("d");
    add_depot("c");
    add_depot("c");
    add_depot("b");
    add_depot("c");
    add_depot("c");
    add_depot("c");
    add_depot("a");
    add_depot("c");
    add_depot("c");
    add_depot("c");

    assign_to("A", 1);
    assign_to("B", 1);
    assign_to("C", 3);
    assign_to("A", 2);
    assign_to("A", 1);
    assign_to("A", 5);
    assign_to("C", 3);
    assign_to("D", 3);
    assign_to("E", 3);
}

void change_some_references()
{
    Bus *the_bus;
    Depot *the_depot;
    int side_no;
    side_no = 1;
    the_bus = find_object_with_item_in(&buses, (void*)(&side_no), get_side_no, side_no_cmp);
    the_depot = find_object_with_item_in(&depots, (void*)("D"), get_depot_name, depots_names_cmp);
    remove_bus(the_bus);
    remove_depot(the_depot);
    the_depot = find_object_with_item_in(&depots, (void*)("B"), get_depot_name, depots_names_cmp);
    remove_depot(the_depot);
}

void test_filters()
{
    int no;
    char txt[256];

    printf("======= FILTERING ==========\n\n");

    printf("--------SIDE NO\n");
    no = 5;
    print_filtered_by(SIDE_NO, (void*)(&no));

    printf("--------LINE NO\n");
    no = 11;
    print_filtered_by(LINE_NO, (void*)(&no));

    printf("--------DRIVER NAME\n");
    strcpy(txt, "W");
    print_filtered_by(DRIVER_NAME, (void*)txt);

    printf("-------- PESEL\n");
    strcpy(txt, "11111111111");
    print_filtered_by(DRIVER_PESEL, (void*)txt);

    printf("-------- DEPOT NAME\n");
    strcpy(txt, "A");
    print_filtered_by(DEPOT_NAME, (void*)txt);

    printf("--------\n");

}

void print_data()
{
    for_each_in(&buses, print_bus_info);
    for_each_in(&depots, print_depot_info);
}
