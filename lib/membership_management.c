#include "../include/membership_management.h"


void assign_to(char* depot_name, int side_no)
{
    Bus *the_bus;
    Depot *the_depot;
    the_bus = find_object_with_item_in(&buses, (void*)(&side_no), get_side_no, side_no_cmp);
    the_depot = find_object_with_item_in(&depots, (void*)depot_name, get_depot_name, names_cmp);
    assign_structs_to(the_depot, the_bus);
}

void assign_structs_to(Depot* the_depot, Bus* the_bus)
{
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
    the_depot = find_object_with_item_in(&depots, (void*)depot_name, get_depot_name, names_cmp);
    remove_assignment_structs_from(the_depot, the_bus);
}

void remove_assignment_structs_from(Depot* the_depot, Bus* the_bus)
{
    if (!the_bus || !the_depot) {
        msg(NOT_FOUND);
        return;
    }
    remove_from(&(the_depot->members), the_bus, del_node_only);
    remove_from(&(the_bus->memberships), the_depot, del_node_only);
}

void move_to(char *from_depot_name, int side_no, char *to_depot_name)
{
    Bus *the_bus;
    Depot *from_depot, *to_depot;
    the_bus = find_object_with_item_in(&buses, (void*)(&side_no), get_side_no, side_no_cmp);
    from_depot = find_object_with_item_in(&depots, (void*)from_depot_name, get_depot_name, names_cmp);
    to_depot = find_object_with_item_in(&depots, (void*)to_depot_name, get_depot_name, names_cmp);
    if (!the_bus || !from_depot || !to_depot) {
        msg(NOT_FOUND);
        return;
    }
    remove_assignment_structs_from(from_depot, the_bus);
    assign_structs_to(to_depot, the_bus);
}
