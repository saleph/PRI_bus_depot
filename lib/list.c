#include "../include/list.h"


int add_new_element_to_list(List* a_list, void* an_object)
{
    ListNode *temp_node;

    temp_node = malloc(sizeof (ListNode));
    if (!temp_node)
        return 0;

    /* empty list case */
    if (!a_list->length) {
        temp_node->object = an_object;
        temp_node->next = NULL;
        temp_node->prev = NULL;

        a_list->head = temp_node;
        a_list->tail = temp_node;
        a_list->length++;
        return 1;
    }

    /* add the temp_node at the end of a_list */
    temp_node->object = an_object;
    temp_node->prev = a_list->tail;
    temp_node->next = NULL;

    a_list->tail = temp_node;
    a_list->length++;
    return 1;
}

int remove_element_from_list(List* a_list, void* an_object)
{
    ListNode *the_node;
    ListNode *temp_node;

    the_node = find_in_list_the_node_with_object(a_list, an_object);
    if (!temp_node)
        return 0;

    /* even if the_node is the last element of a_list
     * its next and prev are NULLs, so everything
     * still works properly */
    if (the_node == a_list->tail)
        a_list->tail = the_node->prev;

    if (the_node == a_list->head)
        a_list->head = the_node->next;

    temp_node = the_node;
    the_node->next->prev = temp_node->prev;
    the_node->prev->next = temp_node->next->prev;

}

/* TODO: taking a comparing function into arguements */
ListNode *find_in_list_the_node_with_object(List* a_list, void* an_object)
{
    ListNode *temp_node;

    /* find passing an_object in a_list */
    for (temp_node=a_list->head;
         temp_node;
         temp_node=temp_node->next)
        if (temp_node->object == an_object) return temp_node;

    /* if the object hasn't been found */
    return NULL;
}

