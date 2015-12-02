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
    case DEPOT_REMOVING_FAILED:
        printf("Removing depot from list failed!\n");
        break;
    case BUS_REMOVING_FAILED:
        printf("Removing bus from list failed!\n");
        break;
    }
}
