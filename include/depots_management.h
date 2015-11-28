#ifndef DEPOTS_MANAGEMENT_H_INCLUDED
#define DEPOTS_MANAGEMENT_H_INCLUDED

#include "depot.h"
#include "list.h"

static List depots;

/* append new depot to the list */
int add_depot(char*);

int remove_depot(Depot*);

#endif /* DEPOTS_MANAGEMENT_H_INCLUDED */
