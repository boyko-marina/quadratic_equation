#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "scan_and_print.h"
#include "comparison_num.h"
#include "solve_equation.h"
#include "test.h"

#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_RESET   "\x1b[0m"

int main(int argc, char *argv[])
{
#ifdef DEBUG

    FILE *file;

    if (argc >= 2)
    {
        for(int i = 1; i < argc;  i++)
        {
            file = fopen(argv[i], "r");

            if (file == NULL)
            {
                printf(COLOR_MAGENTA "ERROR. Could not open this file." COLOR_RESET "\n");
            }
            else
            {
                run_tests_from_file(file);
            }
        }
    }
    else
    {
        printf(COLOR_MAGENTA "ERROR. No filename was entered." COLOR_RESET "\n");
    }

#endif


#ifndef DEBUG

    struct equation eq;
    eq = {0};

    print_hello_words();
    scan_symbols(&eq);
    solve_equation(&eq);
    print_result(&eq);

#endif
    return 0;
}
