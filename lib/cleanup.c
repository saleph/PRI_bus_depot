#include "../include/cleanup.h"


void clean_up_mem()
{
    delete_list(&buses, clean_bus);
    delete_list(&depots, clean_depot);
}

void clean_bus(void *the_bus_pointer)
{
    Bus *the_bus;
    the_bus = (Bus*)the_bus_pointer;
    delete_list(&(the_bus->memberships), clean_membership);
    free(the_bus);
}

void clean_depot(void *the_depot_pointer)
{
    Depot *the_depot;
    the_depot = (Depot*)the_depot_pointer;
    delete_list(&(the_depot->members), clean_membership);
    free(the_depot);
}

void clean_membership(void *membership)
{
    del_node_only(membership);
}
