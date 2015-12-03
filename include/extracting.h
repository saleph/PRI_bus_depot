#ifndef EXTRACTING_H_INCLUDED
#define EXTRACTING_H_INCLUDED

#include "list.h"
#include "buses_management.h"
#include "depots_management.h"

void *get_side_no(ListNode*);
void *get_line_no(ListNode*);
void *get_driver_name(ListNode*);
void *get_driver_pesel(ListNode*);
void *get_depot_name(ListNode*);

#endif /* EXTRACTING_H_INCLUDED */
