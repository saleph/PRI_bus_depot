#include "../include/buses_management.h"

List buses;


int add_bus(char* side_no, char* line_no, char* name, char* pesel)
{
    Bus *the_bus;
    the_bus = new_bus(side_no, line_no, name, pesel);

    /* if setting up new bus failed */
    if (!the_bus)
        return 0;

    if(!append_to(&buses, the_bus, buses_side_no_cmp))
        free(the_bus);
    return 1;
}

int remove_bus(Bus* the_bus)
{
    /* removes list of depots' pointers */
    delete_bus_references(the_bus);
    if(!remove_from(&buses, the_bus, del_bus)) {
        msg(BUS_REMOVING_FAILED);
        return 0;
    }
    return 1;
}

/*TODO!!!*/
void delete_bus_references(Bus* the_bus)
{
    /* for each depot in memberships list
     * delete reference to removed bus
     */
    ListNode *list_node;
    Depot *the_depot;

    for (list_node=the_bus->memberships.head;
         list_node;
         list_node=list_node->next)
         {
             the_depot = (Depot*)(list_node->object);
             remove_assignment_from(the_depot->name, the_bus->side_no);
         }
}

int edit_bus_side_no(Bus* the_bus, char* side_no)
{
    if (!set_side_no(the_bus, side_no))
        return 0;
    return 1;
}

int edit_bus_line_no(Bus* the_bus, char* line_no)
{
    if (!set_line_no(the_bus, line_no))
        return 0;
    return 1;
}

int edit_bus_driver_name(Bus* the_bus, char* driver_name)
{
    if (!set_driver_name(the_bus, driver_name))
        return 0;
    return 1;
}

int edit_bus_driver_pesel(Bus* the_bus, char* driver_pesel)
{
    if (!set_driver_pesel(the_bus, driver_pesel))
        return 0;
    return 1;
}
