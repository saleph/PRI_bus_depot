#ifndef MESSAGES_H_INCLUDED
#define MESSAGES_H_INCLUDED

#include <stdio.h>

enum Message {
    MALLOC_ERR,
    ALREADY_EXIST,
    NOT_FOUND
};

void msg(enum Message);

#endif /* MESSAGES_H_INCLUDED */
