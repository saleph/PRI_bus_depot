#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "bus_validator.h"
#include "depot.h"
#include "list.h"
#include "messages.h"

typedef struct Bus {
    int side_no;
    int line_no;
    char driver_name[64];
    char driver_pesel[12];
    List memberships; /* list of depots which include the bus */
} Bus;

Bus *new_bus(char*, char*, char*, char*);
void del_bus(void*);

int set_side_no(Bus*, char*);
int set_line_no(Bus*, char*);
int set_driver_name(Bus*, char*);
int set_driver_pesel(Bus*, char*);

void print_bus_info(void*);
void print_bus_memberships(void*);

#endif /* BUS_H_INCLUDED */
