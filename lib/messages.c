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
    }
}
