#include "../include/ui_printer.h"


static void dashes();

void prt(enum PrintType prt_type)
{
    switch(prt_type)
    {
    case WELCOME:
        printf("Witaj w programie do obsługi zajezdni autobusowej!\n");
        dashes();
        break;
    case LOAD_FROM_FILE:
        printf("Chcesz wczytać dane zapisane w pliku Dane.txt? [t/n]: ");
        break;

    }
}

void dashes()
{
    printf("-----------------------------------------\n");
}
