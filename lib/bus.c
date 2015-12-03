#include "../include/bus.h"


Bus *new_bus(char* side_no, char* line_no, char* name, char* driver_pesel)
{
    Bus *the_bus;

    the_bus = calloc(1, sizeof (struct Bus));
    if (!the_bus) {
        printf("MEMORY ALLOCATION ERROR! (new bus)\n");
        return NULL;
    }

    /* if any set fail */
    if(!set_side_no(the_bus, side_no) ||
       !set_line_no(the_bus, line_no) ||
       !set_driver_name(the_bus, name) ||
       !set_driver_pesel(the_bus, driver_pesel))
       {
           free(the_bus);
           return NULL;
       }

    return the_bus;
}

int set_side_no(Bus* a_bus, char* side_no)
{
    if (!is_side_no_valid(side_no))
        return 0;

    a_bus->side_no = atoi(side_no);
    return 1;
}
int set_line_no(Bus* a_bus, char* line_no)
{
    if (!is_line_no_valid(line_no))
        return 0;

    a_bus->line_no = atoi(line_no);
    return 1;
}

int set_driver_name(Bus* a_bus, char* name)
{
    char *correct_name;
    if (!(correct_name = is_driver_name_valid(name)))
        return 0;

    strcpy(a_bus->driver_name, correct_name);
    return 1;
}

int set_driver_pesel(Bus* a_bus, char* driver_pesel)
{
    if (!is_driver_pesel_valid(driver_pesel))
        return 0;

    strcpy(a_bus->driver_pesel, driver_pesel);
    return 1;
}

void print_bus_info(void* the_bus_ptr)
{
    Bus* the_bus;
    the_bus = (Bus*)the_bus_ptr;
    printf("Bus: %04d %d %s %s Depots: ", the_bus->side_no,
           the_bus->line_no, the_bus->driver_name, the_bus->driver_pesel);

    do_for_each_in(&(the_bus->memberships), print_bus_memberships);

    printf("\n");
}

void print_bus_memberships(void* the_depot_pointer)
{
    Depot *the_depot;
    the_depot = (Depot*)the_depot_pointer;
    printf("%s ", the_depot->name);
}

void del_bus(void* the_bus_pointer)
{
    Bus *the_bus;
    the_bus = (Bus*)the_bus_pointer;

    /* deletes nodes only! */
    delete_list(&(the_bus->memberships), del_node_only);
    free(the_bus);
}
