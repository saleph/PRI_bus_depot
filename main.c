#include <stdio.h>
#include "include/tests.h"
#include "include/cleanup.h"
#include "include/dumper.h"
#include "include/data_loader.h"


int main()
{
    load_database_from("data.txt");
    /*dump_database_to_file("data.txt");*/
    /*do_tests();*/
    clean_up_mem();
    printf("Bus: %d Depot: %d List: %d\n", sizeof(Bus), sizeof(Depot), sizeof(List));
    printf("CLEANUP...\n");
    return 0;
}
