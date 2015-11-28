#ifndef MANAGEMENT_H_INCLUDED
#define MANAGEMENT_H_INCLUDED

#include "bus.h"
#include "list.h"

static List buses;

/* append new bus to the list */
int add_bus(char*, char*, char*, char*);
int remove_bus(Bus*);

#endif /* MANAGEMENT_H_INCLUDED */
