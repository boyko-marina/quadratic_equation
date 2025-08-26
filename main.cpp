#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "scan_and_print.h"
#include "comparison_num.h"
#include "solve_equation.h"
#include "test.h"

//! Solves a quadratic equation ax^2 + bx + c = 0
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//! @param [out] n_roots Pointer to the number of roots
//!
//! @return Number of roots
//!
//! @note In case of 0 number of roots,
//!       returns NO_ROOTS
//! @note In case of 1 root,
//!       returns ONE_ROOTS
//! @note In case of 2 roots,
//!       returns TWO_ROOTS
//! @note In case of infinite number of roots,
//!       returns INF_ROOTS



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
                printf("ERROR. Could not open this file.\n");
            }
            else
            {
                run_tests_from_file(file);
            }
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
