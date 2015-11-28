#include "../include/bus_validator.h"

static List buses;

int is_side_no_valid(char* a_string)
{
    if (strlen(a_string) > 4) {
        printf("Side no is too long! (max 4 digits)\n");
        return 0;
    }
    if (!is_number(a_string)) {
        printf("Side no has to be number!\n");
        return 0;
    }
    /* now a_string is up to 4-digit long */
    return 1;
}

int is_line_no_valid(char* a_string)
{
    if (strlen(a_string) > 3) {
        printf("Line no is too long! (max 3 digits)\n");
        return 0;
    }
    if (!is_number(a_string)) {
        printf("Line no has to be number!\n");
        return 0;
    }
    /* now a_string is up to 3-digit long */
    return 1;
}

int is_driver_name_valid(char* a_string)
{
    unsigned int i;

    if (strlen(a_string) > 63) {
        printf("Name is too long! (max 63 letters)\n");
        return 0;
    }

    for (i=0; i<strlen(a_string); i++) {
        if (isspace(a_string[i]))
            continue;

        /* check/make the beginnings of word capital */
        if (i == 0 || (i >= 1 && isspace(a_string[i-1]))) {
            if (isupper(a_string[i]))
                continue;

            if (islower(a_string[i])) {
                a_string[i] = toupper(a_string[i]);
                continue;
            }
        }
        /* for the rest check/make the letters lower */
        else {
            if (islower(a_string[i]))
                continue;

            if (isupper(a_string[i])) {
                a_string[i] = tolower(a_string[i]);
                continue;
            }
        }

        /* if a_string[i] is not a letter */
        return 0;
    }

    /* if everything gone properly */
    return 1;
}

int is_driver_pesel_valid(char* a_string)
{
    if (strlen(a_string) != 11) {
        printf("PESEL has to be 11-digit long!\n");
        return 0;
    }
    if (!is_number(a_string)) {
        printf("PESEL has to be number!\n");
        return 0;
    }
    /* now a_string is 11-digit long */
    return 1;
}

int is_number(char* a_string)
{
    unsigned int i;

    for (i=0; i<strlen(a_string); i++)
        if (!isdigit(a_string[i])) return 0;

    return 1;
}
