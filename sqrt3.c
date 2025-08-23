#include <TXLib.h>
#include <stdio.h>
#include <math.h>

void clean_buffer();
int compare_num(double x, double y);
int equal_num(double x, double y);
int solve_equation(struct equation* eq);
int linear_equation(struct equation* eq);
int quadratic_equation(struct equation* eq);


//typedef struct equation* eq_ptr_t;

const double EPS = 0.00001;

typedef enum{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3,
} solutions_count_t;


struct equation{
    double a, b, c;
    double x1, x2;
    solutions_count_t n_roots;
};

int main( )
{
    struct equation eq;

    eq = {0};

    printf("This program solves a quadratic equation of the type: ax^2+bx+c=0.\n");
    printf("Enter the coefficients (a, b, c) of the equation separated by space:\n");

    while (scanf("%lg %lg %lg", &eq.a, &eq.b, &eq.c) != 3)
    {
        clean_buffer();
        printf("Error, were entered wrong symbols. Try again.\n";
    }

    //scanf("%lg %lg %lg", &eq.a, &eq.b, &eq.c);

    solve_equation(&eq);

    //if (n_roots == WRONG)
    //{
    //    printf("Error, were entered wrong symbols. Try again")
    //}
    if (eq.n_roots == NO_ROOTS)
    {
        printf("This equation has no roots that are real numbers.\n");
    }
    else if (eq.n_roots == ONE_ROOT)
    {
        printf("The number of roots: 1. The meaning of root: x=%lg.\n", eq.x1);
    }
    else if (eq.n_roots == TWO_ROOTS)
    {
        printf("The number of roots: 2. The meaning of roots: x1=%lg, x2=%lg.\n", eq.x1, eq.x2);
    }
    else if (eq.n_roots == INF_ROOTS)
    {
        printf("This equation has an infinite number of roots. The root can be any real number.\n");
    }
    return 0;
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


