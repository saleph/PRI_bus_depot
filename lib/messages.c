#include "../include/messages.h"


void msg(enum Message message)
{
    switch(message)
    {
    case MALLOC_ERR:
        printf("PRZEPELNIENIE PAMIECI!!!\n");
        break;
    case ALREADY_EXIST:
        printf("Taki rekord juz istnieje!\n");
        break;
    case NOT_FOUND:
        printf("Ten rekord nie istnieje!\n");
        break;
    case DEPOT_REMOVE_FAILED:
        printf("Usuwanie zajezdni z lisy NIE POWIODLO SIE!\n");
        break;
    case BUS_REMOVE_FAILED:
        printf("Usuwanie autobusu z listy NIE POWIODLO SIE!\n");
        break;
    case SAVING_FAILED:
        printf("OTWARCIE PLIKU DO ZAPISU NIE POWIODLO SIE!\n");
        printf("Program musi byc uruchomiony w katalogu, do ktorego masz dostep!\n");
        break;
    case OPENING_FILE_FAILED:
        printf("Ladowanie bazy z pliku NIE POWIODLO SIE!\n");
        break;
    case FILE_DAMAGED:
        printf("Skladnia wczytywanych danych jest nieprawidlowa! Zadne dane nie zostaly wczytane.\n");
        break;
    case LOAD_SUCCESSFUL:
        printf("Wczytywanie zakonczone.\n");
    }
}
