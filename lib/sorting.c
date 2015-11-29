#include "../include/sorting.h"

int side_no_cmp(const void* first, const void* second)
{
    return integers_cmp( *(int*)first, *(int*)second);
}

void *get_side_no(ListNode* the_node)
{
    /* casts void *object to Bus* and gets side_no
     * of the bus and then gets address of int side_no
     * and casts it into void* */
    return (void*)(&(((Bus*)(the_node->object))->side_no));
}

int depots_names_cmp(const void* first, const void* second)
{
    return strings_cmp( (char*)first, (char*)second);
}

void *get_depot_name(ListNode* the_node)
{
    /* casting void *object to Depot* and getting
     * name of the depot */
    return (void*)(((Depot*)(the_node->object))->name);
}

int integers_cmp(int first, int second)
{
    return (first - second);
}

int strings_cmp(char* first, char* second)
{
    return strcmp(first, second);
}
