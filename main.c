#include <TXLib.h>
#include <stdio.h>
#include <math.h>

typedef enum{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
} solutions_count_t;

void clean_buffer();
int compare_num(double x, double y);
int equal_num(double x, double y);
int solve_equation(struct equation* eq);
int linear_equation(struct equation* eq);
int quadratic_equation(struct equation* eq);
int one_test(double a1, double b1, double c1, double x1_ref, double x2_ref, solutions_count_t n_roots_ref);
int run_test();


//typedef struct equation* eq_ptr_t;

const double EPS = 0.00001;

struct equation{
    double a, b, c;
    double x1, x2;
    solutions_count_t n_roots;
};

int main( )
{
    if (run_test())
    {
        printf("OK");
    }
    else
    {
        printf("ERROR");
    }
    return 0;
//    struct equation eq;

//    eq = {0};

//    printf("This program solves a quadratic equation of the type: ax^2+bx+c=0.\n");
//    printf("Enter the coefficients (a, b, c) of the equation separated by space:\n");

//    while (scanf("%lg %lg %lg", &eq.a, &eq.b, &eq.c) != 3)
//    {
//        clean_buffer();
//        printf("Error, were entered wrong symbols. Try again.\n");
//    }

//    solve_equation(&eq);

//    switch(eq.n_roots)
//    {
//    case NO_ROOTS: printf("This equation has no roots that are real numbers.\n");
//                   break;
//    case ONE_ROOT: printf("The number of roots: 1. The meaning of root: x=%lg.\n", eq.x1);
//                    break;
//    case TWO_ROOTS: printf("The number of roots: 2. The meaning of roots: x1=%lg, x2=%lg.\n", eq.x1, eq.x2);
//                    break;
//    case INF_ROOTS: printf("This equation has an infinite number of roots. The root can be any real number.\n");
//                    break;
//    default: break;
//    }
//    return 0;
}

void clean_buffer()
{
    int symbol = 0;
    while ((symbol = getchar()) != '\n'){}
}

int equal_num(double x, double y)
{
    if (fabs(x-y)<EPS)
    {
        return 1;
    }
    return 0;
}

int compare_num(double x, double y)
{
    if ((x-y)>EPS)
    {
        return 1;
    }
    return 0;
}

//strtod

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
        return eq->n_roots = TWO_ROOTS;
    }
    else if (equal_num(d, 0))
    {
        eq->x1 = (-eq->b)/(2*eq->a);
        return eq->n_roots = ONE_ROOT;
    }
    return eq->n_roots = NO_ROOTS;
}

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
    if (passed == i)
    {
        return 1;
    }
    return 0;
}
