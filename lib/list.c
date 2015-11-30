#include "../include/list.h"


int append_to(List* a_list, void* an_object, int (*cmp)(const void*, const void*))
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
    temp_node = find_place_for_new_node(temp_node, a_list, an_object, cmp);
    if (!temp_node)
        return 0;

    a_list->length++;
    return 1;
}

ListNode *find_place_for_new_node(ListNode* new_node, List* a_list, void* an_object, int (*cmp)(void*, void*))
{
    ListNode *list_node;
    ListNode *next_node, *prev_node;
    int ret_val;

    for (list_node=a_list->head;
         list_node;
         list_node=list_node->next)
         {
             /* if an_object already exist */
             ret_val = (*cmp)(an_object, list_node->object);
             if (!ret_val) {
                free(new_node);
                return NULL;
             }
             /* if new object is greater than list_node object */
             if (ret_val > 0) { /* insert new_node after list_node */
                 if (list_node == a_list->tail) {
                    new_node->object = an_object;
                    new_node->prev = list_node;
                    new_node->next = NULL;

                    a_list->tail = new_node;
                    list_node->next = new_node;
                    return new_node;
                 }

                 next_node = list_node->next;
                 new_node->object = an_object;
                 new_node->prev = list_node;
                 new_node->next = next_node;

                 list_node->next = new_node;
                 next_node->prev = new_node;
                 return new_node;
             }
             /* if an_object is less than list_node object */
             if (ret_val < 0) { /* inserts new_node before list_node */
                 if (list_node == a_list->head) {
                    new_node->object = an_object;
                    new_node->prev = NULL;
                    new_node->next = list_node;

                    a_list->head = new_node;
                    list_node->prev = new_node;
                    return new_node;
                 }

                 prev_node = list_node->prev;
                 new_node->object = an_object;
                 new_node->next = list_node;
                 new_node->prev = prev_node;

                 list_node->prev = new_node;
                 prev_node->next = new_node;
                 return new_node;
             }
         }
    /* only for debug purposes, func never get there*/
    return NULL;
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
                append_to(&occurrences, list_node, cmp);
         }
    return occurrences;
}

void delete_array(void* arr)
{
    free(arr);
}
