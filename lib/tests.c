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
    delete_list(&buses);
    delete_list(&depots);
}
