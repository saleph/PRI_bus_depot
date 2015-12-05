#include "../include/depots_management.h"


List depots;
static void delete_depot_references(Depot*);

int add_depot(char* depot_name)
{
    Depot *the_depot;
    the_depot = new_depot(depot_name);

    /* if setting up new depot failed */
    if (!the_depot)
        return 0;

    if(!append_to(&depots, the_depot, depots_names_cmp))
        free(the_depot);
    return 1;
}

int remove_depot(Depot* the_depot)
{
    /* removes list of buses' pointers */
    delete_depot_references(the_depot);
    if (!remove_from(&depots, the_depot, del_depot)) {
        msg(DEPOT_REMOVE_FAILED);
        return 0;
    }
    return 1;
}

void delete_depot_references(Depot* the_depot)
{
    /* for each depot in memberships list
     * delete reference to removed bus
     */
    ListNode *list_node, *tmp_node;
    Bus *the_bus;

    for (list_node=the_depot->members.head;
         list_node;
         )
         {
             tmp_node = list_node->next;
             the_bus = (Bus*)(list_node->object);
             /* here list_node may be freed! so use of tmp_node is necessary */
             /* I love you VALGRIND */
             remove_assignment_from(the_depot->name, the_bus->side_no);
             list_node = tmp_node;
         }
}

int edit_depot_name(Depot* the_depot, char* depot_name)
{
    if (!set_depot_name(the_depot, depot_name))
        return 0;
    return 1;
}
