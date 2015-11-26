#ifndef LIST_H
#define LIST_H

/* generic, universal List */
typedef struct {
    unsigned int length;
    void *head;
    void *tail;
} List;

/* node of the generic List */
struct ListNode {
    void *object;
    struct ListNode *next;
    struct ListNode *prev;
};

#endif /* LIST_H */
