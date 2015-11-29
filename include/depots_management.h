#ifndef DEPOTS_MANAGEMENT_H_INCLUDED
#define DEPOTS_MANAGEMENT_H_INCLUDED

#include "depot.h"
#include "bus.h"
#include "list.h"
#include "sorting.h"

/* append new depot to the list */
int add_depot(char*);

int is_depot_unique(Depot*);

/* removed passed depot from the list */
int remove_depot(Depot*);

int edit_depot_name(Depot*, char*);

Depot *get_the_all_depots_in_array();
Depot *get_depots_array_from(List*);

#endif /* DEPOTS_MANAGEMENT_H_INCLUDED */
