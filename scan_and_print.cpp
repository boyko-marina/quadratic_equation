#include <TXLib.h>
#include <stdio.h>

#include "scan_and_print.h"


void print_hello_words()
{
    printf("This program solves a quadratic equation of the type: ax^2+bx+c=0.\n");
    printf("Enter the coefficients (a, b, c) of the equation separated by space:\n");
}

void scan_symbols(struct equation* eq)
{
    while (scanf("%lg %lg %lg", &eq->a, &eq->b, &eq->c) != 3)
    {
        clean_buffer();
        printf("Error, were entered wrong symbols. Try again.\n");
    }
}

void clean_buffer()
{
    int symbol = 0;
    while ((symbol = getchar()) != '\n')
    {
        // do nothing;
    }
}

void print_result(struct equation* eq)
{
    switch(eq->n_roots)
    {
        case NO_ROOTS:
        {
            printf("This equation has no roots that are real numbers.\n");
            break;
        }
        case ONE_ROOT:
        {
            printf("The number of roots: 1. The meaning of root: x=%lg.\n", eq->x1);
            break;
        }
        case TWO_ROOTS:
        {
            printf("The number of roots: 2. The meaning of roots: x1=%lg, x2=%lg.\n", eq->x1, eq->x2);
            break;
        }
        case INF_ROOTS:
        {
            printf("This equation has an infinite number of roots. The root can be any real number.\n");
            break;
        }
        default:
        {
            break;
        }
    }
}
