#include "../include/comparing.h"

/* buses sorting */
int buses_side_no_cmp(const void *first, const void *second)
{
    /* gets two void* to buses and extracts their side_no */
    return side_no_cmp( (void*)(&(((Bus*)first)->side_no)),
                        (void*)(&(((Bus*)second)->side_no)) );
}

int side_no_cmp(const void* first, const void* second)
{
    return integers_cmp(*(int*)first, *(int*)second);
}

int buses_line_no_cmp(const void *first, const void *second)
{
    /* gets two void* to buses and extracts their line_no */
    return line_no_cmp( (void*)(&(((Bus*)first)->line_no)),
                        (void*)(&(((Bus*)second)->line_no)) );
}

int line_no_cmp(const void* first, const void* second)
{
    return integers_cmp(*(int*)first, *(int*)second);
}

int buses_drivers_names_cmp(const void* first, const void* second)
{
    /* gets driver name from void* to Bus and then casts char* to void* */
    return drivers_names_cmp( (void*)(((Bus*)first)->driver_name),
                              (void*)(((Bus*)second)->driver_name) );
}

int drivers_names_cmp(const void* first, const void* second)
{
    return strings_cmp((char*)first, (char*)second);
}

int buses_drivers_pesels_cmp(const void* first, const void* second)
{
    /* gets driver pesel from void* to Bus and then casts char* to void* */
    return drivers_pesels_cmp( (void*)(((Bus*)first)->driver_name),
                               (void*)(((Bus*)second)->driver_name) );
}

int drivers_pesels_cmp(const void* first, const void* second)
{
    return strings_cmp((char*)first, (char*)second);
}

/* depots sorting */
int depots_names_cmp(const void* first, const void* second)
{
    return strings_cmp((void*)(((Depot*)first)->name),
                       (void*)(((Depot*)second)->name));
}

int names_cmp(const void* first, const void* second)
{
    return strings_cmp((char*)first, (char*)second);
}

int integers_cmp(int first, int second)
{
    return (first - second);
}

int strings_cmp(char* first, char* second)
{
    return strcmp(first, second);
}
