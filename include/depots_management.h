#ifndef DEPOTS_MANAGEMENT_H_INCLUDED
#define DEPOTS_MANAGEMENT_H_INCLUDED

#include "depot.h"
#include "bus.h"
#include "list.h"
#include "sorting.h"
#include "messages.h"

extern List depots;

/* append new depot to the list */
int add_depot(char*);

/* removed passed depot from the list */
int remove_depot(Depot*);

void delete_depot_references(Depot*);

int edit_depot_name(Depot*, char*);

#endif /* DEPOTS_MANAGEMENT_H_INCLUDED */
