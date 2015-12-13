#include "include/ui.h"
#include "include/tests.h"
#define DEBUG_MODE 0

int main()
{
    if (DEBUG_MODE)
        do_tests();
    else
        start_program();
    return 0;
}
