#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/* generic, universal, linked List */
typedef struct {
    unsigned int length;
    void *head;
    void *tail;
} List;

/* node of the generic List */
typedef struct {
    void *object;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

/* takes a List and a pointer to object
 * returns 1 if successful
 * returns 0 if malloc was unsuccessful
 */
int add_new_element_to_list(List*, void*);

int remove_element_from_list(List*, void*);

ListNode *find_in_list_the_node_with_object(List*, void*);

#endif /* LIST_H */
