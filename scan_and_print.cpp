//! @file
#include <TXLib.h>
#include <stdio.h>
#include <assert.h>

#include "scan_and_print.h"

#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

//! Prints words for user to understand what the program does

void print_hello_words()
{
    printf(COLOR_GREEN "This program solves a quadratic equation of the type: ax^2 + bx + c = 0.\n");
    printf("Enter the coefficients (a, b, c) of the equation separated by space:" COLOR_RESET "\n");
}

//! Scans the enter symbols from user
//!
//! @param [in] a Pointer to the a-coefficient
//! @param [in] b Pointer to the b-coefficient
//! @param [in] c Pointer to the c-coefficient
//!
//! @note In case of entering symbols, which are not numbers
//!       clears buffer (ignores line) and prints error
//! @note In case of entering symbols, which are numbers,
//!       moves on

void scan_symbols(struct equation* eq)
{
    printf(COLOR_YELLOW);
    while (scanf("%lg %lg %lg", &eq->a, &eq->b, &eq->c) != 3)
    {
        printf(COLOR_RESET);
        clean_buffer();
        printf(COLOR_MAGENTA "Error, were entered wrong symbols. Try again." COLOR_RESET "\n");
    }
    printf(COLOR_RESET);
}

//! Clears buffer (ignores line)

void clean_buffer()
{
    int symbol = 0;
    while ((symbol = getchar()) != '\n')
    {
        // do nothing;
    }
}

//! Prints result of solving the equation
//!
//! @param [in] n_roots Pointer to the roots number
//!
//! @note In case of 0 number of roots,
//!       n_roots is equal to NO_ROOTS
//! @note In case of 1 root,
//!       n_roots is equal to ONE_ROOT
//! @note In case of 2 roots,
//!       n_roots is equal to TWO_ROOTS
//! @note In case of infinite number of roots,
//!       n_roots is equal to INF_ROOTS

void print_result(struct equation* eq)
{
    printf(COLOR_CYAN);

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
    printf(COLOR_RESET);
}
