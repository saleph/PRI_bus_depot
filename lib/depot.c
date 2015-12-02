#include "../include/depot.h"


Depot *new_depot(char* a_string)
{
    Depot *the_depot;

    the_depot = malloc(sizeof (struct Depot));
    if (!the_depot) {
        printf("MEMORY ALLOCATION ERROR! (new depot)\n");
        return NULL;
    }

    if(!set_depot_name(the_depot, a_string)) {
        free(the_depot);
        return NULL;
    }

    return the_depot;
}

int set_depot_name(Depot* a_depot, char* name)
{
    if (!is_depot_name_valid(name))
        return 0;

    strcpy(a_depot->name, name);
    return 1;
}

void print_depot_info(void* the_depot_pointer)
{
    Depot *the_depot;
    the_depot = (Depot*)the_depot_pointer;
    printf("Depot: %s Buses inner: ", the_depot->name);

    print_all(&(the_depot->members), print_depot_members);

    printf("\n");
}

void print_depot_members(void* the_bus_pointer)
{
    Bus *the_bus;
    the_bus = (Bus*)the_bus_pointer;
    printf("%04d ", the_bus->side_no);
}
