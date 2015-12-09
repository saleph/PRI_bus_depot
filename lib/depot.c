#include "../include/depot.h"


static void print_depot_members(void*);

Depot *new_depot(char* a_string)
{
    Depot *the_depot;

    the_depot = calloc(1, sizeof (struct Depot));
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

void del_depot(void* the_depot_pointer)
{
    Depot *the_depot;
    the_depot = (Depot*)the_depot_pointer;

    /* deletes nodes only! */
    delete_list(&(the_depot->members), del_node_only);
    free(the_depot);
}

int set_depot_name(Depot* a_depot, char* name)
{
    char *correct_name;
    if (!(correct_name = is_depot_name_valid(name)))
        return 0;

    strcpy(a_depot->name, correct_name);
    return 1;
}

void print_depot_info(void* the_depot_pointer)
{
    Depot *the_depot;
    the_depot = (Depot*)the_depot_pointer;
    printf("- %s\n", the_depot->name);
}

void print_depot_info_with_refs(void* the_depot_pointer)
{
    Depot *the_depot;
    the_depot = (Depot*)the_depot_pointer;
    printf("- %s\n", the_depot->name);
    printf("--- Przypisane autobusy:\n");
    if (the_depot->members.length > 0) {
        print_bus_labels();
        for_each_in(&(the_depot->members), print_bus_info);
    }
    else
        printf("   == BRAK ==");
    printf("\n");
}

void print_depot_members(void* the_bus_pointer)
{
    Bus *the_bus;
    the_bus = (Bus*)the_bus_pointer;
    printf("   - %04d\n", the_bus->side_no);
}
