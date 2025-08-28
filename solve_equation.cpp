//! @file
#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "scan_and_print.h"
#include "comparison_num.h"
#include "solve_equation.h"

//! Defines the type of equation
//!
//! @param [in] a Pointer to the a-coefficient
//! @param [in] b Pointer to the b-coefficient
//! @param [in] c Pointer to the c-coefficient
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//! @param [out] n_roots Pointer to the number of roots
//!
//! @return the type of equation
//!
//! @note In case of linear equation bx + c = 0,
//!       returns function for solving linear equation
//! @note In case of quadratic equation ax^2 + bx + c = 0,
//!       returns function for solving quadratic equation


int solve_equation(struct equation* eq)
{
    if (equal_num(eq->a, 0))
    {
        return linear_equation(eq);
    }
    return quadratic_equation(eq);
}

//! Solves a linear equation bx + c = 0
//!
//! @param [in] b Pointer to the b-coefficient
//! @param [in] c Pointer to the c-coefficient
//! @param [out] x1 Pointer to the root
//! @param [out] n_roots Pointer to the number of roots
//!
//! @return Number of roots
//!
//! @note In case of 0 number of roots,
//!       returns NO_ROOTS
//! @note In case of 1 root,
//!       returns ONE_ROOTS
//! @note In case of infinite number of roots,
//!       returns INF_ROOTS

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
            eq->x1 = (-eq->c) / eq->b;
            return eq->n_roots = ONE_ROOT;
        }
    }
}

//! Solves a quadratic equation ax^2 + bx + c = 0
//!
//! @param [in] a Pointer to the a-coefficient
//! @param [in] b Pointer to the b-coefficient
//! @param [in] c Pointer to the c-coefficient
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

int quadratic_equation(struct equation* eq)
{
    double d = (eq->b * eq->b) - (4 * eq->a * eq->c);
    if (compare_num(d, 0))
    {
        eq->x1 = (-(eq->b) + sqrt(d)) / (2 * eq->a);
        eq->x2 = (-(eq->b) - sqrt(d)) / (2 * eq->a);
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
        eq->x1 = (-(eq->b)) / (2 * eq->a);
        if (equal_num(fabs(eq->x1), 0))
        {
            eq->x1 = 0;
        }
        return eq->n_roots = ONE_ROOT;
    }
    return eq->n_roots = NO_ROOTS;
}
