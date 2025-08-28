//! @file
#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "comparison_num.h"


//! Compare first numbers for equality
//!
//! @param [in] x the 1st double number
//! @param [in] y the 2nd double number
//!
//! @return True or False
//!
//! @note In case of x is equal to y,
//!       returns True
//! @note In case of x is not equal to y,
//!       returns False

int equal_num(double x, double y)
{
    if (fabs(x - y) < EPS)
    {
        return 1;
    }
    return 0;
}

//! Compare first number with second number
//!
//! @param [in] x the 1st double number that is being compared
//! @param [in] y the 2nd double number to which the 1st is being compared
//!
//! @return True or False
//!
//! @note In case of x is more than y,
//!       returns True
//! @note In case of x is less than y,
//!       returns False

int compare_num(double x, double y)
{
    if ((x - y) > EPS)
    {
        return 1;
    }
    return 0;
}
