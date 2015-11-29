#include "../include/depots_management.h"

static List depots;


int add_depot(char* depot_name)
{
    Depot *the_depot;
    the_depot = new_depot(depot_name);

    /* if setting up new depot failed */
    if (!the_depot)
        return 0;

    if (!is_depot_unique(the_depot))
        return 0;

    append_to(&depots, the_depot);
    return 1;
}

int is_depot_unique(Depot* the_depot)
{
    unsigned int occurrs_no;
    List occurrences;
    occurrences = find_occurrences(&depots,
                                   the_depot->name,
                                   get_depot_name,
                                   depots_names_cmp);
    occurrs_no = occurrences.length;
    delete_list(&occurrences);
    if (occurrs_no) {
        printf("This depot already exist!\n");
        return 0;
    }
    return 1;
}

int remove_depot(Depot* the_depot)
{
    /* removes list of buses' pointers */
    delete_list(&(the_depot->members));
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
