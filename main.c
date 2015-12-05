#include <stdio.h>
#include "include/tests.h"
#include "include/cleanup.h"
#include "include/dumper.h"
#include "include/data_loader.h"


int main()
{
    load_database_from("data.txt");
    /*create_data();
    dump_database_to("data.txt");*/
    print_data();
    change_some_references();
    printf("\n\n");
    test_filters();
    clean_up_mem();
    printf("\n\n\nCLEANUP ENDED\n\n\n");
    return 0;
}
