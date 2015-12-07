#include "../include/ui_printer.h"


void prt(enum PrintType prt_type)
{
    switch(prt_type)
    {
    case CLS:
        printf("\033[2J\033[1;1H");
        break;
    case WELCOME:
        printf("Witaj w programie do obslugi zajezdni autobusowej!\n");
        prt(LINE);
        break;
    case LOAD_FROM_FILE:
        printf("Chcesz wczytac dane zapisane w pliku Dane.txt? [t/n]: ");
        break;
    case MAIN_MENU:
        printf("MENU\n");
        printf("1. Dodaj/usun/edytuj dane\n");
        printf("2. Dodaj/usun/przenies dowiazania\n");
        printf("3. Wyswietlanie danych\n");
        printf("4. Zapis bazy danych do pliku\n");
        prt(SHORT_LINE);
        printf("0. ZAMKNIECIE PROGRAMU\n\n");
        break;
    case MODIFYING_DATA_MENU:
        printf("1. Dodaj nowy autobus/zajezdnie\n");
        printf("2. Edytuj istniejacy autobus/zajezdnie\n");
        printf("3. Usun autobus/zajezdnie\n");
        prt(SHORT_LINE);
        printf("0. Cofnij\n\n");
        break;
    case MODIFYING_REFERENCES_MENU:
        printf("1. Przypisz autobus do zajezdni\n");
        printf("2. Usun przypisanie\n");
        printf("3. Przenies autobus do innej zajezdni\n");
        prt(SHORT_LINE);
        printf("0. Cofnij\n\n");
        break;
    case BUS_OR_DEPOT:
        printf("1. Autobus\n");
        printf("2. Zajezdnia\n");
        prt(SHORT_LINE);
        printf("0. Cofnij\n\n");
        break;
    case CHOOSE_OPT:
        printf("Podaj numer opcji: ");
        break;
    case DATA_HAS_BEEN_MODIFIED:
        printf("Dane zostaly zmodyfikowane.\n");
        printf("Czy chcialbys zapisac dane przed wyjsciem? [t/n]: ");
        break;
    case EXITING:
        prt(BOLD_LINE);
        printf("Wyjscie z programu...\n\n");
        break;
    case NOT_A_NUMBER:
        printf("To nie jest liczba!\n");
        break;
    case INVALID_OPTION:
        printf("Opcja o takim numerze nie istnieje!\n");
        break;
    case LINE:
        printf("------------------------------\n");
        break;
    case SHORT_LINE:
        printf("----------\n");
        break;
    case BOLD_LINE:
        printf("==============================================\n\n");
        break;
    case PRINT_DATA_MENU:
        printf("1. Wyswietl wszystkie autobusy\n");
        printf("2. Wyswietl wszystkie zajezdnie\n");
        printf("3. Wyswietl autobusy przypisane do wybranej zajezdni\n");
        printf("4. Filtruj autobusy\n");
        prt(SHORT_LINE);
        printf("0. Cofnij\n\n");
        break;
    case TYPE_DEPOT_NAME:
        printf("Podaj nazwe zajezdni: ");
        break;
    case TYPE_BUS_SIDE_NO:
        printf("Podaj numer boczny autobusu: ");
        break;
    case ADD_ASSIGNMENT:
        printf("Przypisywanie autobusu do zajezdni\n");
        break;
    case DEL_ASSIGNMENT:
        printf("Usuwanie przypisania autobusu do zajezdni\n");
        break;
    case MV_ASSIGNMENT:
        printf("Przenoszenie autobusu z jednej zajezdni do drugiej\n");
        break;
    case FROM_DEPOT:
        printf("Z zajezdni: ");
        break;
    case TO_DEPOT:
        printf("Do zajezdni: ");
        break;
    case CHOOSE_DEPOT_TO_PRINT:
        printf("Podaj nazwe zajezdni, aby wyswietlic zawarte w niej autobusy: ");
        break;
    case TYPES_OF_BUSES_FILTERING:
        printf("Wzgledem jakiego pola chcesz przeprowadzic filtrowanie?\n");
        printf("1. Numer boczny\n");
        printf("2. Numer linii\n");
        printf("3. Numer pesel\n");
        printf("4. Imie i nazwisko\n");
        break;
    case TYPE_VALUE_OF_FIELD:
        printf("Podaj wartosc, po ktorej ma nastapic filtrowanie: ");
        break;
    case TYPE_BUS_LINE_NO:
        printf("Podaj numer linii: ");
        break;
    case TYPE_BUS_DRIVER_PESEL:
        printf("Podaj numer PESEL kierowcy: ");
        break;
    case TYPE_BUS_DRIVER_NAME:
        printf("Podaj nazwisko i imie kierowcy: ");
        break;
    }
}
