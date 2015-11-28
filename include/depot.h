#ifndef DEPOT_H_INCLUDED
#define DEPOT_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "list.h"
#include "depot_validator.h"

typedef struct Depot {
    char name[64];
    List members; /* List of the depot's members */
} Depot;

Depot *new_depot(char*);

int set_depot_name(Depot*, char*);

#endif /* DEPOT_H_INCLUDED */
