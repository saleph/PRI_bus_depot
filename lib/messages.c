#include "../include/messages.h"


void msg(enum Message message)
{
    switch(message)
    {
    case MALLOC_ERR:
        printf("MEMORY OVERFLOW!!!\n");
        break;
    case ALREADY_EXIST:
        printf("This element already exist!\n");
        break;
    case NOT_FOUND:
        printf("This element doesn't exist!\n");
        break;
    case DEPOT_REMOVE_FAILED:
        printf("Removing depot from list failed!\n");
        break;
    case BUS_REMOVE_FAILED:
        printf("Removing bus from list failed!\n");
        break;
    case SAVING_FAILED:
        printf("OPEN NEW FILE TO SAVE DATA FAILED!\n");
        break;
    case OPENING_FILE_FAILED:
        printf("Loading database from file FAILED!\n");
        break;
    case FILE_DAMAGED:
        printf("Syntax of the file is incorrect! No data has been load!\n");
        break;
    }
}
