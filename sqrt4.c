#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int compare_num(double x, double y);
int equal_num(double x, double y);
int solve_equation(double a, double b, double c, double *x1, double *x2);
int linear_equation(double b, double c, double *x1);
int quadratic_equation(double a, double b, double c, double *x1, double *x2);



int main( )
{
    double a, b, c;
    double x1, x2;
    a = b = c = 0;
    x1 = x2 = 0;

    printf("This program solves a quadratic equation of the type: ax^2+bx+c=0.\n");
    printf("Enter the coefficients (a, b, c) of the equation separated by space:\n");

    scanf("%lg %lg %lg", &a, &b, &c);

    int eq=solve_equation(a, b, c, &x1, &x2);

    if (eq == 0)
    {
        printf("This equation has no roots that are real numbers.\n");
    }
    else if (eq == 1)
    {
        printf("The number of roots: 1. The meaning of roots: x=%lg.\n", x1);
    }
    else if (eq == 2)
    {
        printf("The number of roots: 2. The meaning of roots: x=%lg, x=%lg.\n", x1, x2);
    }
    else if (eq == 3)
    {
        printf("This equation has an infinite number of roots. The root can be any real number.\n");
    }
    return 0;
}

int equal_num(double x, double y)
{
    double eps=0.00001;
    if (fabs(x-y)<eps)
    {
        return 1;
    }
    return 0;
}

int compare_num(double x, double y)
{
    double eps=0.00001;
    if ((x-y)>eps)
    {
        return 1;
    }
    return 0;
}


int solve_equation(double a, double b, double c, double *x1, double *x2)
{
    if (equal_num(a, 0))
    {
        return linear_equation(b, c, x1);
    }
    return quadratic_equation(a, b, c, x1, x2);
}


int linear_equation(double b, double c, double *x1)
{
    if (equal_num(b, 0))
    {
        if (equal_num(c, 0))
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (equal_num(c, 0))
        {
            *x1 = 0;
            return 1;
        }
        else
        {
            *x1 = (-c)/b;
            return 1;
        }
    }
}


int quadratic_equation(double a, double b, double c, double *x1, double *x2)
{
    double d = b*b-4*a*c;
    if (compare_num(d, 0))
    {
        *x1 = (-b+sqrt(d))/(2*a);
        *x2 = (-b-sqrt(d))/(2*a);
        return 2;
    }
    else if (equal_num(d, 0))
    {
        *x1 = (-b)/2*a;
        return 1;
    }
    return 0;
}
