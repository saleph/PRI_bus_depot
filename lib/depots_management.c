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

int remove_depot(Depot* the_depot)
{
    if (!remove_from(&depots, the_depot)) {
        printf("Removing depot from list failed!\n");
        return 0;
    }
    return 1;
}

int edit_depot_name(Depot* the_depot, char* depot_name)
{
    if (!set_depot_name(the_depot, depot_name))
        return 0;
    return 1;
}
