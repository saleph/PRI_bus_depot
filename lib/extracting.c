#include "../include/extracting.h"


void *get_side_no(ListNode* the_node)
{
    /* casts void *object to Bus* and gets side_no
     * of the bus and then gets address of int side_no
     * and casts it into void* */
    return (void*)(&(((Bus*)(the_node->object))->side_no));
}

void *get_line_no(ListNode* the_node)
{
    return (void*)(&(((Bus*)(the_node->object))->line_no));
}

void *get_driver_name(ListNode* the_node)
{
    return (void*)(((Bus*)(the_node->object))->driver_name);
}

void *get_driver_pesel(ListNode* the_node)
{
    return (void*)(((Bus*)(the_node->object))->driver_pesel);
}

void *get_depot_name(ListNode* the_node)
{
    /* casting void *object to Depot* and getting
     * name of the depot */
    return (void*)(((Depot*)(the_node->object))->name);
}
