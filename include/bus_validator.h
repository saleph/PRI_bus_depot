#ifndef BUS_VALIDATOR_H_INCLUDED
#define BUS_VALIDATOR_H_INCLUDED

#include <ctype.h>
#include <string.h>
#include "bus.h"
#include "messages.h"

int is_side_no_valid(char*);
int is_line_no_valid(char*);

/* returns valid copy of arguement
 * NULL if it was incorrect
 */
char *is_driver_name_valid(char*);

int is_driver_pesel_valid(char*);
int is_number(char*);

#endif /* BUS_VALIDATOR_H_INCLUDED */
