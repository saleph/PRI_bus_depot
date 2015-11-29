#include "../include/buses_management.h"

static List buses;


int add_bus(char* side_no, char* line_no, char* name, char* pesel)
{
    Bus *the_bus;
    the_bus = new_bus(side_no, line_no, name, pesel);

    /* if setting up new bus failed */
    if (!the_bus)
        return 0;

    append_to(&buses, the_bus);
    return 1;
}

int is_bus_unique(Bus* the_bus)
{
    unsigned int occurrs_no;
    List occurrences;
    occurrences = find_occurrences(&buses, the_bus->side_no,
                                   get_side_no(), side_no_cmp());
    occurrs_no = occurrences.length;
    delete_list(&occurrences);
    if (occurrs_no) {
        printf("This side no already exist!\n");
        return 0;
    }
    return 1;
}

int remove_bus(Bus* the_bus)
{
    /* removes list of depots' pointers */
    delete_list(&(the_bus->memberships));
    if(!remove_from(&buses, the_bus)) {
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
