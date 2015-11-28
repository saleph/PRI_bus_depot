#include "../include/depots_management.h"


int add_depot(char* depot_name)
{
    Depot *the_depot;
    the_depot = new_depot(depot_name);

    /* if setting up new depot failed */
    if (!the_depot)
        return 0;

    append_to(&depots, the_depot);
    return 1;
}
