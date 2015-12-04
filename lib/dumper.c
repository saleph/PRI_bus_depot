#include "../include/dumper.h"


static FILE *file_hook;
static void dump_comments();
static void dump_bus(void*);
static void dump_depot(void*);


int dump_data_to(const char* filename)
{
    file_hook = fopen(filename, 'w');
    if (file_hook) {
        msg(FILE_OPEN_FAILED);
        return 0;
    }
    dump_comments();
    do_for_each_in(&buses, dump_bus);
    do_for_each_in(&depots, dump_depot);
    fclose(file_hook);
    return 1;
}

void dump_comments()
{
    fprintf(file_hook, "# This is the comment line. Comments will be ignored during parsing\n");
    fprintf(file_hook, "# Record with a BUS starts with 'B' letter\n");
    fprintf(file_hook, "# Record with a DEPOT starts with 'D' letter\n");
    fprintf(file_hook, "# Each field in each record has to be separated by ';' (semicolon)\n");
}

void dump_bus(void* the_bus_ptr)
{
    Bus *the_bus;
    the_bus = (Bus*)the_bus_ptr;

}
