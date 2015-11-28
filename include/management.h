#ifndef MANAGEMENT_H_INCLUDED
#define MANAGEMENT_H_INCLUDED

#include "depot.h"
#include "bus.h"
#include "list.h"

static List buses;
static List depots;

/* append new bus to the list */
int add_bus(char*, char*, char*, char*);

/* append new depot to the list */
int add_depot(char*);

#endif /* MANAGEMENT_H_INCLUDED */
