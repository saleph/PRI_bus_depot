#include "../include/ui.h"


static char buffer[128];
static void load_prev_data();

void start_program()
{
    prt(WELCOME);
    load_prev_data();
    prt(LOAD_FROM_FILE);
}

void load_prev_data()
{
    prt(LOAD_FROM_FILE);

    load_database_from("Dane.txt");
}
