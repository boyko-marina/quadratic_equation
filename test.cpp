#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "scan_and_print.h"
#include "comparison_num.h"
#include "solve_equation.h"
#include "test.h"

int validate_solution(struct test_eq* tests)
{
    struct equation eq = { .a = tests->a, .b = tests->b, .c = tests->c, .x1 = 0, .x2 = 0, .n_roots = NO_ROOTS};

    solve_equation(&eq);
    if (!(eq.n_roots == tests->n_roots) ||
        !((equal_num(eq.x1, tests->x1) && equal_num(eq.x2, tests->x2)) ||
        (equal_num(eq.x1, tests->x2) && equal_num(eq.x2, tests->x1))))
    {
        printf("FAILED: solve_equation (%lf, %lf, %lf), -> %d, x1=%lf, x2=%lf (should be: x1=%lf, x2=%lf)\n", tests->a, tests->b, tests->c, eq.n_roots, eq.x1, eq.x2, tests->x1, tests->x2);
        return 0;
    }
    return 1;
}

int run_test()
{
    int passed = 0;
    struct test_eq tests[] = { { .a = 1, .b = -5, .c = 6, .x1 = 2, .x2 = 3, .n_roots = TWO_ROOTS},
                               { .a = 0.014, .b = -5, .c = 0.9, .x1 = 0.180091, .x2 = 356.96277, .n_roots = TWO_ROOTS},
                               { .a = -55, .b = 0.0012, .c = 0.065, .x1 = -0.0343667, .x2 = 0.0343885, .n_roots = TWO_ROOTS},
                               { .a = 1, .b = 0, .c = 0, .x1 = 0, .x2 = 0, .n_roots = ONE_ROOT}
                             };

    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        passed += validate_solution(&tests[i]);
    }

    if (passed == size)
    {
        return 1;
    }
    return 0;
}

void test_solve_equation()
{
    if (run_test())
    {
        printf("OK");
    }
    else
    {
        printf("ERROR");
    }
}
