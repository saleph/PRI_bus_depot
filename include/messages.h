#ifndef MESSAGES_H_INCLUDED
#define MESSAGES_H_INCLUDED

#include <stdio.h>

enum Message {
    MALLOC_ERR,
    ALREADY_EXIST,
    NOT_FOUND,
    DEPOT_REMOVING_FAILED,
    BUS_REMOVING_FAILED
};

void msg(enum Message);

#endif /* MESSAGES_H_INCLUDED */
