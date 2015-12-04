#include <stdio.h>
#include "include/tests.h"
#include "include/cleanup.h"
#include "include/dumper.h"


int main()
{
    create_data();
    dump_data_to("data.txt");
    print_data();
    change_some_references();
    printf("\n\n");
    test_filters();
    clean_up_mem();
    printf("\n\n\nCLEANUP ENDED\n\n\n");
    return 0;
}
