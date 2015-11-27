#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "bus_validator.h"
#include "list.h"

typedef struct Bus {
    unsigned int side_no;
    unsigned int line_no;
    char driver_name[64];
    char pesel[12];
} Bus;

Bus *new_bus(char*, char*, char*, char*);

int set_side_no(Bus*, char*);
int set_line_no(Bus*, char*);
int set_driver_name(Bus*, char*);
int set_pesel(Bus*, char*);

#endif /* BUS_H_INCLUDED */
