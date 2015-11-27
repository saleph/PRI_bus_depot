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
    if (strlen(name) > 63) {
        printf("Depot name is too long! (max 63 letters)\n");
        return 0;
    }

    strcpy(a_depot->name, name);
    return 1;
}
