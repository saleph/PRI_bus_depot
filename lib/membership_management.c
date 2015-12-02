#include "../include/membership_management.h"


void assign_to(char* depot_name, int side_no)
{
    Bus *the_bus;
    Depot *the_depot;
    the_bus = find_object_with_item_in(&buses, (void*)(&side_no), get_side_no, side_no_cmp);
    the_depot = find_object_with_item_in(&depots, (void*)depot_name, get_depot_name, depots_names_cmp);
    if (!the_bus || !the_depot) {
        msg(NOT_FOUND);
        return;
    }

    append_to(&(the_bus->memberships), the_depot, depots_names_cmp);
    append_to(&(the_depot->members), the_bus, buses_side_no_cmp);
}

void remove_assignment_from(char* depot_name, int side_no)
{
    Bus *the_bus;
    Depot *the_depot;
    the_bus = find_object_with_item_in(&buses, (void*)(&side_no), get_side_no, side_no_cmp);
    the_depot = find_object_with_item_in(&depots, (void*)depot_name, get_depot_name, depots_names_cmp);
    if (!the_bus || !the_depot) {
        msg(NOT_FOUND);
        return;
    }

    remove_from(&(the_depot->members), the_bus);
    remove_from(&(the_bus->memberships), the_depot);
}

void move_to(char *depot_name, int side_no)
{
    Bus *the_bus;
    Depot *the_depot;
    the_bus = find_object_with_item_in(&buses, (void*)(&side_no), get_side_no, side_no_cmp);
    the_depot = find_object_with_item_in(&depots, (void*)depot_name, get_depot_name, depots_names_cmp);
    if (!the_bus || !the_depot) {
        msg(NOT_FOUND);
        return;
    }
}
