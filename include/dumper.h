#ifndef DUMPER_H_INCLUDED
#define DUMPER_H_INCLUDED

#include <stdio.h>
#include "buses_management.h"
#include "depots_management.h"
#include "list.h"
#include "extracting.h"
#include "messages.h"

/* dumps data to file named
 * as the passed parameter
 */
int dump_data_to(const char*);

/* rename file passed as an
 * argument to <name>.backup
 */
int backup(const char*);

#endif /* DUMPER_H_INCLUDED */
