#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "comparison_num.h"

int equal_num(double x, double y)
{
    if (fabs(x - y) < EPS)
    {
        return 1;
    }
    return 0;
}

int compare_num(double x, double y)
{
    if ((x - y) > EPS)
    {
        return 1;
    }
    return 0;
}
