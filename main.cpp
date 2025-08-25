#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "scan_and_print.h"
#include "comparison_num.h"
#include "solve_equation.h"
#include "test.h"

int main(void)
{
#ifdef DEBUG

    test_solve_equation();

#endif


#ifndef DEBUG

    struct equation eq;
    eq = {0};

    print_hello_words();
    scan_symbols(&eq);
    solve_equation(&eq);
    print_result(&eq);

#endif
}
