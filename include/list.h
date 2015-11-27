#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/* generic, universal, linked List */
typedef struct List {
    unsigned int length;
    void *head;
    void *tail;
} List;

/* node of the generic List */
typedef struct ListNode {
    void *object;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

/* takes a List and a pointer to object
 * returns 1 if successful
 * returns 0 if malloc was unsuccessful
 */
int append_to(List*, void*);

/* removes given ListNode
 * returns 1 if successful
 * returns 0 if list is empty
 */
int remove_from(List*, ListNode*);

#endif /* LIST_H */
