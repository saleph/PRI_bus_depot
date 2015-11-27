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

int remove_from(List* a_list, ListNode* a_node)
{
    ListNode *a_node_temp;

    /* empty list case */
    if (!a_list->length)
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
