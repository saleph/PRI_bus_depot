#include "../include/buses_management.h"

List buses;


int add_bus(char* side_no, char* line_no, char* name, char* pesel)
{
    Bus *the_bus;
    the_bus = new_bus(side_no, line_no, name, pesel);

    /* if setting up new bus failed */
    if (!the_bus)
        return 0;

    append_to(&buses, the_bus, buses_side_no_cmp);
    return 1;
}

int remove_bus(Bus* the_bus)
{
    /* removes list of depots' pointers */
    delete_list(&(the_bus->memberships));
    if(!remove_from(&buses, the_bus, del_bus)) {
        printf("Removing bus from list failed!\n");
        return 0;
    }
    return 1;
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

Bus *get_the_all_buses_in_array()
{
    return get_buses_array_from(&buses);
}

Bus *get_buses_array_from(List* the_list)
{
    ListNode *list_node;
    Bus *buses_array;
    unsigned int i, list_size;
    list_size = the_list->length;

    buses_array = calloc(list_size, sizeof(Bus));

    for (i=0, list_node=the_list->head;
         i<list_size && list_node;
         i++, list_node=list_node->next)
         {
             buses_array[i] = *(Bus*)(list_node->object);
         }
    return buses_array;
}
