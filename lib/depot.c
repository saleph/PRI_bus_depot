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

void print_depot_info(Depot* the_depot)
{
    int side_no;
    ListNode *node;
    printf("Depot: %s Buses inner: ", the_depot->name);
    for (node=the_depot->members.head; node; node=node->next) {
        side_no = ((Bus*)(node->object))->side_no;
        printf("%04d ", side_no);
    }
    printf("\n");
}
