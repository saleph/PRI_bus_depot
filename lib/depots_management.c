#include "../include/depots_management.h"

List depots;


int add_depot(char* depot_name)
{
    Depot *the_depot;
    the_depot = new_depot(depot_name);

    /* if setting up new depot failed */
    if (!the_depot)
        return 0;

    append_to(&depots, the_depot, depots_names_cmp);
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

Depot *get_the_all_depots_in_array()
{
    return get_depots_array_from(&depots);
}

Depot *get_depots_array_from(List* the_list)
{
    ListNode *list_node;
    Depot *depots_array;
    unsigned int i, list_size;
    list_size = the_list->length;

    depots_array = calloc(list_size, sizeof(Depot));

    for (i=0, list_node=the_list->head;
         i<list_size && list_node;
         i++, list_node=list_node->next)
         {
             depots_array[i] = *(Depot*)(list_node->object);
         }
    return depots_array;
}
