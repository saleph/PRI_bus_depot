#include "../include/buses_management.h"


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

int remove_bus(Bus* the_bus)
{
    if(!remove_from(&buses, the_bus)) {
        printf("Removing bus from list failed!\n");
        return 0;
    }
    return 1;
}
