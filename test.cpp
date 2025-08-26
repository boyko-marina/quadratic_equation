//! @file
#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "scan_and_print.h"
#include "comparison_num.h"
#include "solve_equation.h"
#include "test.h"

#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_RESET   "\x1b[0m"

//! Runs tests from file
//!
//! @param [in] file Pointer to the file with tests
//! @param [in] a Pointer to the a-coefficient
//! @param [in] b Pointer to the b-coefficient
//! @param [in] c Pointer to the c-coefficient
//! @param [in] x1 Pointer to the 1st root
//! @param [in] x2 Pointer to the 2nd root
//! @param [in] n_roots Pointer to the number of roots
//!
//!
//! @note In case of symbols in file, which are numbers,
//!       validates the solution from program
//! @note In case of symbols in file, which are not numbers,
//!       prints error.
//! @note In case of the end of the file,
//!       exit the function

void run_tests_from_file(FILE *file)
{
    struct equation test;
    test = {0};

    int i = 1;

    for (;;)
    {
        int n = fscanf(file, "%lf %lf %lf %lf %lf %d", &test.a, &test.b, &test.c, &test.x1, &test.x2, (int*) &test.n_roots);

        if (n == 6)
        {
            validate_solution(&test);
            i++;
        }
        else if (0 < n && n < 6)
        {
            printf(COLOR_MAGENTA "ERROR. Wrong symbol in line %d." COLOR_RESET "\n", i);
            break;
        }
        else
        {
            break;
        }
    }
}

//! Validates the solution from program
//!
//! @param [in] test Structure with the reference data
//! @param [in] a Pointer to the a-coefficient
//! @param [in] b Pointer to the b-coefficient
//! @param [in] c Pointer to the c-coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//! @param [out] n_roots Pointer to the number of roots
//!
//! @return match of the reference data the reference data and program solution
//!
//! @note In case of mismatch,
//!       prints error with the reference data and program solution
//! @note In case of match,
//!       moves on.


int validate_solution(struct equation* test)
{
    struct equation eq = { .a = test->a, .b = test->b, .c = test->c, .x1 = 0, .x2 = 0, .n_roots = NO_ROOTS};

    solve_equation(&eq);
    if (!(eq.n_roots == test->n_roots) ||
        !((equal_num(eq.x1, test->x1) && equal_num(eq.x2, test->x2)) ||
        (equal_num(eq.x1, test->x2) && equal_num(eq.x2, test->x1))))
    {
        printf(COLOR_MAGENTA "FAILED: solve_equation (%lf, %lf, %lf), -> %d, x1=%lf, x2=%lf (should be: x1=%lf, x2=%lf)." COLOR_RESET "\n", test->a, test->b, test->c, eq.n_roots, eq.x1, eq.x2, test->x1, test->x2);
        return 0;
    }
    return 1;
}


