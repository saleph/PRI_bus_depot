#include "../include/bus.h"


Bus *new_bus(char* side_no, char* line_no, char* name, char* pesel)
{
    Bus *the_bus;

    the_bus = malloc(sizeof (struct Bus));
    if (!the_bus) {
        printf("MEMORY ALLOCATION ERROR!\n");
        return NULL;
    }

    /* if any set fail */
    if(!set_side_no(the_bus, side_no) ||
       !set_line_no(the_bus, line_no) ||
       !set_driver_name(the_bus, name) ||
       !set_pesel(the_bus, pesel))
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
    if (!is_driver_name_valid(name))
        return 0;

    strcpy(a_bus->driver_name, name);
    return 1;
}

int set_pesel(Bus* a_bus, char* pesel)
{
    if (!is_pesel_valid(pesel))
        return 0;

    strcpy(a_bus->pesel, pesel);
    return 1;
}
