#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "scan_and_print.h"
#include "comparison_num.h"
#include "solve_equation.h"
#include "test.h"

int one_test(double a1, double b1, double c1, double x1_ref, double x2_ref, solutions_count_t n_roots_ref)
{
    struct equation eq;
    eq.a = a1;
    eq.b = b1;
    eq.c = c1;
    eq.x1 = 0;
    eq.x2 = 0;
    eq.n_roots = NO_ROOTS;
    solve_equation(&eq);
    if (!(eq.n_roots == n_roots_ref) || !((equal_num(eq.x1, x1_ref) && equal_num(eq.x2, x2_ref)) || (equal_num(eq.x1, x2_ref) && equal_num(eq.x2, x1_ref))))
    {
        printf("FAILED: solve_equation (%lf, %lf, %lf), x1=%lf, x2=%lf (should be: x1=%lf, x2=%lf)\n", a1, b1, c1, eq.x1, eq.x2, x1_ref, x2_ref);
        return 0;
    }
    return 1;
}

int run_test()
{
    int passed = 0, i = 0;
    passed += one_test(1, -5, 6, 2, 3, TWO_ROOTS);
    ++i;
    passed += one_test(0.014, -5, 0.9, 0.180091, 356.96277, TWO_ROOTS);
    ++i;
    passed += one_test(-55, 0.0012, 0.065, -0.0343667, 0.0343885, TWO_ROOTS);
    ++i;
    passed += one_test(1, 0, 0, 0, 0, ONE_ROOT);
    ++i;
    if (passed == i)
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
