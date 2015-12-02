#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "messages.h"

/* node of the generic List */
typedef struct ListNode {
    void *object;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

/* generic, universal, linked List */
typedef struct List {
    unsigned int length;
    ListNode *head;
    ListNode *tail;
} List;


/* takes a List and a pointer to object
 * returns 1 if successful
 * returns 0 if malloc was unsuccessful
 */
int append_to(List*, void*, int ());

ListNode *find_place_for_new_node(ListNode*, List*, void*, int ());

/* removes given ListNode
 * returns 1 if successful
 * returns 0 if list is empty
 */
int remove_from(List*, void*, void ());

/* returns pointer to ListNode
 * which  "object" is the same as
 * passed element
 */
ListNode *find_node_in(List*, void*);

/* returns a pointer to object (eg. struct)
 * which contains passed item (a key)
 */
void *find_object_with_item_in(List*, void*, void*(), int ());

/* removes the all nodes from list
 * but WITHOUT touching the object in
 * the removing node */
void delete_list(List*);

/* removes node only - WITHOUT
 * modifying the object in node
 */
void del_node_only(void*);

/* returns pointer to list with
 * all occurrences of passed value
 * in passed list. Requires extracting
 * function (to get value form ListNode)
 * and comparing fuction */
List find_occurrences(List*, void*, void *(ListNode*), int (const void*, const void*));

/* print content of the list
 * require printing procedure
 */
void do_for_each_in(List*, void ());

#endif /* LIST_H */
