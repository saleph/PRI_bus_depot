#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "buses_management.h"
#include "depots_management.h"

/* buses comparing */
int buses_side_no_cmp(const void*, const void*);
int side_no_cmp(const void*, const void*);
int buses_line_no_cmp(const void*, const void*);
int line_no_cmp(const void*, const void*);
int buses_drivers_names_cmp(const void*, const void*);
int drivers_names_cmp(const void*, const void*);
int buses_drivers_pesels_cmp(const void*, const void*);
int drivers_pesels_cmp(const void*, const void*);

/* depots comparing */
int depots_names_cmp(const void*, const void*);
int names_cmp(const void*, const void*);

#endif /* SORTING_H_INCLUDED */
