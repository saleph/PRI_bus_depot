#ifndef CLEANUP_H_INCLUDED
#define CLEANUP_H_INCLUDED

#include "bus.h"
#include "buses_management.h"
#include "depot.h"
#include "depots_management.h"
#include "membership_management.h"
#include "messages.h"

void clean_up_mem();
void clean_bus(void*);
void clean_depot(void*);
void clean_membership(void*);

#endif /* CLEANUP_H_INCLUDED */
