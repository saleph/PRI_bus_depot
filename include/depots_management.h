#ifndef DEPOTS_MANAGEMENT_H_INCLUDED
#define DEPOTS_MANAGEMENT_H_INCLUDED

#include "depot.h"
#include "bus.h"
#include "list.h"
#include "comparing.h"
#include "messages.h"

extern List depots;

/* append new depot to the list */
int add_depot(char*);

/* removed passed depot from the list */
int remove_depot(Depot*);
void reappend_depot_assignments(Depot*);

int edit_depot_name(Depot*, char*);

#endif /* DEPOTS_MANAGEMENT_H_INCLUDED */
