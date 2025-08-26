#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "scan_and_print.h"
#include "comparison_num.h"
#include "solve_equation.h"
#include "test.h"

int main(int argc, char *argv[])
{
#ifdef DEBUG

    FILE *file;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");

        if (file == 0)
        {
            printf("ERROR. Could not open this file.\n");
        }
        else
        {
            run_tests_from_file(file);
        }
    }
    else
    {
        printf("ERROR. No filename was entered.\n");
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
