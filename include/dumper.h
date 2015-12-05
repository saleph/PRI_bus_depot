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
int dump_database_to_file();

/* rename file passed as an
 * argument to <name>.backup
 */
void backup();

#endif /* DUMPER_H_INCLUDED */
