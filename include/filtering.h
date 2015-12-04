#ifndef FILTERING_H_INCLUDED
#define FILTERING_H_INCLUDED

#include "list.h"
#include "buses_management.h"
#include "depots_management.h"
#include "messages.h"
#include "extracting.h"

enum FilterType {
    SIDE_NO,
    LINE_NO,
    DRIVER_NAME,
    DRIVER_PESEL,
    DEPOT_NAME
};

void print_filtered_by(enum FilterType, void*);

#endif /* FILTERING_H_INCLUDED */
