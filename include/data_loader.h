#ifndef DATA_LOADER_H_INCLUDED
#define DATA_LOADER_H_INCLUDED

#define BUFFER_SIZE 512
#include <stdio.h>
#include "buses_management.h"
#include "depots_management.h"
#include "list.h"
#include "messages.h"

/* loads the all data from passed file */
void load_database_from(const char*);

#endif /* DATA_LOADER_H_INCLUDED */
