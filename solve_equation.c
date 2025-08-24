#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "scan_and_print.h"
#include "comparison_num.h"
#include "solve_equation.h"

int solve_equation(struct equation* eq)
{
    if (equal_num(eq->a, 0))
    {
        return linear_equation(eq);
    }
    return quadratic_equation(eq);
}


int linear_equation(struct equation* eq)
{
    if (equal_num(eq->b, 0))
    {
        if (equal_num(eq->c, 0))
        {
            return eq->n_roots = INF_ROOTS;
        }
        else
        {
            return eq->n_roots = NO_ROOTS;
        }
    }
    else
    {
        if (equal_num(eq->c, 0))
        {
            eq->x1 = 0;
            return eq->n_roots = ONE_ROOT;
        }
        else
        {
            eq->x1 = (-eq->c)/eq->b;
            return eq->n_roots = ONE_ROOT;
        }
    }
}


int quadratic_equation(struct equation* eq)
{
    double d = eq->b*eq->b-4*eq->a*eq->c;
    if (compare_num(d, 0))
    {
        eq->x1 = (-eq->b+sqrt(d))/(2*eq->a);
        eq->x2 = (-eq->b-sqrt(d))/(2*eq->a);
        if (equal_num(fabs(eq->x1), 0))
        {
            eq->x1 = 0;
        }
        else if (equal_num(fabs(eq->x2), 0))
        {
            eq->x2 = 0;
        }
        return eq->n_roots = TWO_ROOTS;
    }
    else if (equal_num(d, 0))
    {
        eq->x1 = (-eq->b)/(2*eq->a);
        if (equal_num(fabs(eq->x1), 0))
        {
            eq->x1 = 0;
        }
        return eq->n_roots = ONE_ROOT;
    }
    return eq->n_roots = NO_ROOTS;
}
