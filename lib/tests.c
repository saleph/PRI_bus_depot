#include "../include/tests.h"

void create_data()
{
    add_bus("1", "11", "w", "11111111111");
    add_bus("2", "11", "w", "11111111111");
    add_bus("1", "11", "w", "11111111111");
    add_bus("1", "11", "w", "11111111111");
    add_bus("2", "11", "w", "11111111111");
    add_bus("3", "11", "w", "11111111111");
    add_bus("4", "11", "w", "11111111111");
    add_bus("1", "11", "w", "11111111111");
    add_bus("1", "11", "w", "11111111111");
    add_bus("2", "11", "w", "11111111111");
    add_bus("1", "11", "w", "11111111111");
    add_bus("12", "11", "w", "11111111111");
    add_bus("5", "11", "w", "11111111111");
    add_bus("3", "11", "w", "11111111111");
    add_bus("4", "11", "w", "11111111111");
    add_bus("1", "11", "w", "11111111111");
    add_bus("8", "11", "w", "11111111111");
    add_bus("7", "11", "w", "11111111111");
    add_bus("1", "11", "w", "11111111111");
    add_bus("15", "11", "w", "11111111111");
    add_bus("6", "11", "w", "11111111111");
    add_bus("13", "11", "w", "11111111111");
    add_bus("4", "11", "w", "11111111111");
    add_bus("1", "11", "w", "11111111111");

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

    assign_to("a", 7);
    assign_to("b", 15);
    assign_to("a", 3);
    assign_to("a", 2);
    assign_to("a", 1);
    assign_to("a", 5);
    assign_to("c", 3);
    assign_to("d", 3);
    assign_to("e", 3);
}

void change_some_references()
{
    Bus *the_bus;
    int side_no;
    side_no = 3;
    the_bus = find_object_with_item_in(&buses, (void*)(&side_no), get_side_no, side_no_cmp);
    remove_bus(the_bus);
}

void print_data()
{
    ListNode *node;
    for (node=buses.head; node; node=node->next)
        print_bus_info((Bus*)(node->object));

    for (node=depots.head; node; node=node->next)
        print_depot_info((Depot*)(node->object));
}

void delete_data()
{
    /*
    delete_list(&buses, del_bus);
    delete_list(&depots, del_depot);*/
}
