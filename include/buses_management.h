#ifndef MANAGEMENT_H_INCLUDED
#define MANAGEMENT_H_INCLUDED

#include "bus.h"
#include "list.h"

static List buses;

/* append new bus to the list */
int add_bus(char*, char*, char*, char*);

/* removes passed bus from the list */
int remove_bus(Bus*);

int edit_bus_side_no(Bus*, char*);
int edit_bus_line_no(Bus*, char*);
int edit_bus_driver_name(Bus*, char*);
int edit_bus_driver_pesel(Bus*, char*);

#endif /* MANAGEMENT_H_INCLUDED */
