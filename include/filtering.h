#ifndef FILTERING_H_INCLUDED
#define FILTERING_H_INCLUDED

#include "list.h"
#include "buses_management.h"
#include "depots_management.h"
#include "messages.h"

/* filtering returns a pointer to static List variable
 * which contains matching records. Passed list can be
 * also previously filtered List
 */
List filter_buses_by_side_no(List*, int);
List filter_buses_by_line_no(List*, int);
List filter_buses_by_driver_name(List*, char*);
List filter_buses_by_driver_pesel(List*, char*);
List filter_depots_by_name(List*, char*);

#endif /* FILTERING_H_INCLUDED */
