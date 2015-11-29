#include "../include/list.h"


int append_to(List* a_list, void* an_object)
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

int remove_from(List* a_list, void* an_element)
{
    ListNode *a_node;
    ListNode *a_node_temp;

    /* empty list case */
    if (!a_list->length)
        return 0;

    a_node = find_in(a_list, an_element);
    if (!a_node)
        return 0;

    /* if a_node is a tail */
    if (a_node == a_list->tail) {
        a_list->tail = a_node->prev;
        a_node->prev->next = NULL;
    }
    /* if a_node is a head */
    else if (a_node == a_list->head) {
        a_list->head = a_node->next;
        a_node->next->prev = NULL;
    }
    /* if a_node is between head and tail */
    else {
        a_node_temp = a_node;
        a_node->next->prev = a_node_temp->prev;
        a_node->prev->next = a_node_temp->next;
    }

    free(a_node);
    a_list->length--;
    return 1;
}

ListNode *find_in(List* a_list, void* an_object)
{
    ListNode *list_node;
    for (list_node=a_list->head;
         list_node;
         list_node=list_node->next)
             if (list_node->object == an_object)
                return list_node;

    /* if the node has not been found */
    return NULL;
}

void delete_list(List* the_list)
{
    ListNode *list_node;
    ListNode *temp_node;

    list_node = the_list->head;
    while (list_node) {
        temp_node = list_node->next;
        free(list_node);
        list_node = temp_node;
    }
    the_list->head = the_list->tail = NULL;
}

List find_occurrences(List* the_list, void* item,
                       void* (*get)(ListNode*), int (*cmp)(const void*, const void*))
{
    static List occurrences;
    ListNode *list_node;
    void *node_item;

    for (list_node=the_list->head;
         list_node;
         list_node=list_node->next)
         {
             node_item = (*get)(list_node);
             /* if the item is the same as
              * its equivalent in ListNode */
             if (!((*cmp)(node_item, item)))
                append_to(&occurrences, list_node);
         }
    return occurrences;
}
