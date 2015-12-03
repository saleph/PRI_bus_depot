#include <stdio.h>
#include "include/tests.h"
#include "include/cleanup.h"


int main()
{
    create_data();
    print_data();
    change_some_references();
    printf("\n\n");
    print_data();
    clean_up_mem();
    printf("\n\n\nCLEANUP ENDED\n\n\n");
    return 0;
}
