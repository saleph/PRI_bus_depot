#include <stdio.h>
#include "include/tests.h"


int main()
{
    create_data();
    print_data();
    change_some_references();
    printf("\n\n");
    print_data();
    delete_data();
    return 0;
}
