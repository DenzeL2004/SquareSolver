#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "headers\Generals.h"

bool equality_double (double num1, double num2){
    assert (isfinite (num1) && isfinite (num2) && "vals must not be NAN/INF");

    is_error (isfinite (num1));
    is_error (isfinite (num2));

    return fabs (num1-num2) < Eps;
}

bool is_zero (double num){
    assert (isfinite (num) && "vals must not be NAN/INF");

    is_error (isfinite (num));

    return equality_double (num, 0);
}

double fix_zero (double num){
    assert (isfinite (num) && "vals must not be NAN/INF");

    is_error (isfinite (num));

    if (is_zero (num))
        return 0.0;
    return num;
}

void print_colour (const char colour[], const char str[]){
    printf (colour);
    printf ("%s", str);
    printf (RESET);
}
