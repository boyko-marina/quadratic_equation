#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "scan_and_print.h"
#include "comparison_num.h"
#include "solve_equation.h"
#include "test.h"

void scan_test_data(struct test_eq* test, char *argv[])
{
    FILE *file = fopen(argv[1], "r");

    int k = 0, i = 1;
    while (fscanf(file, "%lf %lf %lf %lf %lf %d", &test->a, &test->b, &test->c, &test->x1, &test->x2, (int*) &test->n_roots) == 6)
    {
        k += validate_solution(test);
        i++;
    }

    if (0 < fscanf(file, "%lf %lf %lf %lf %lf %d", &test->a, &test->b, &test->c, &test->x1, &test->x2, (int*) &test->n_roots) && fscanf(file, "%lf %lf %lf %lf %lf %d", &test->a, &test->b, &test->c, &test->x1, &test->x2, (int*) &test->n_roots) < 6)
    {
        printf("Error. Wrong symbols in line %d.\n", i);
    }

    fclose(file);
}

int validate_solution(struct test_eq* test)
{
    struct equation eq = { .a = test->a, .b = test->b, .c = test->c, .x1 = 0, .x2 = 0, .n_roots = NO_ROOTS};

    solve_equation(&eq);
    if (!(eq.n_roots == test->n_roots) ||
        !((equal_num(eq.x1, test->x1) && equal_num(eq.x2, test->x2)) ||
        (equal_num(eq.x1, test->x2) && equal_num(eq.x2, test->x1))))
    {
        printf("FAILED: solve_equation (%lf, %lf, %lf), -> %d, x1=%lf, x2=%lf (should be: x1=%lf, x2=%lf)\n", test->a, test->b, test->c, eq.n_roots, eq.x1, eq.x2, test->x1, test->x2);
        return 0;
    }
    return 1;
}


