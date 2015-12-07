#ifndef UI_PRINTER_H_INCLUDED
#define UI_PRINTER_H_INCLUDED

#include <stdio.h>

enum PrintType {
    CLS,
    WELCOME,
    LOAD_FROM_FILE,
    MAIN_MENU,
    CHOOSE_OPT,
    DATA_HAS_BEEN_MODIFIED,
    EXITING,
    MODIFYING_DATA_MENU,
    MODIFYING_REFERENCES_MENU,
    BUS_OR_DEPOT,
    NOT_A_NUMBER,
    INVALID_OPTION,
    LINE,
    SHORT_LINE,
    BOLD_LINE,
    PRINT_DATA_MENU,
    TYPE_DEPOT_NAME,
    TYPE_BUS_SIDE_NO,
    ADD_ASSIGNMENT,
    DEL_ASSIGNMENT,
    MV_ASSIGNMENT,
    FROM_DEPOT,
    TO_DEPOT
};

void prt(enum PrintType);

#endif /* UI_PRINTER_H_INCLUDED */
