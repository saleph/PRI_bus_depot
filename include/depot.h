#ifndef DEPOT_H_INCLUDED
#define DEPOT_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "list.h"
#include "bus.h"
#include "depot_validator.h"
#include "messages.h"

typedef struct Depot {
    char name[64];
    List members; /* List of the depot's members */
} Depot;

Depot *new_depot(char*);
void del_depot(void* the_depot_pointer);

int set_depot_name(Depot*, char*);

void print_depot_info(void*);

#endif /* DEPOT_H_INCLUDED */
