#ifndef MANAGEMENT_H_INCLUDED
#define MANAGEMENT_H_INCLUDED

#include "bus.h"
#include "depot.h"
#include "list.h"
#include "sorting.h"

/* append new bus to the list */
int add_bus(char*, char*, char*, char*);

int is_bus_unique(Bus*);

/* removes passed bus from the list */
int remove_bus(Bus*);

int edit_bus_side_no(Bus*, char*);
int edit_bus_line_no(Bus*, char*);
int edit_bus_driver_name(Bus*, char*);
int edit_bus_driver_pesel(Bus*, char*);

Bus *get_the_all_buses_in_array();
Bus *get_buses_array_from(List*);

#endif /* MANAGEMENT_H_INCLUDED */
