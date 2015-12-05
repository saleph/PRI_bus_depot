#ifndef UI_PRINTER_H_INCLUDED
#define UI_PRINTER_H_INCLUDED

#include <stdio.h>

enum PrintType {
    WELCOME,
    LOAD_FROM_FILE,
    MENU
};

void prt(enum PrintType);

#endif /* UI_PRINTER_H_INCLUDED */
