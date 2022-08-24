#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include "headers\Generals.h"

bool equality_double (double num1, double num2){
    is_error (isfinite (num1));
    is_error (isfinite (num2));

    return fabs (num1-num2) < Eps;
}

bool is_zero (double num){
    is_error (isfinite (num));

    return equality_double (num, 0);
}

double fix_zero (double num){
    is_error (isfinite (num));

    if (is_zero (num))
        return 0.0;
    return num;
}

void print_colour (char const colour[], char const *fmt, ...){
    printf (colour);

    va_list arg_ptr;

    va_start (arg_ptr, fmt);
    vprintf (fmt, arg_ptr);
    va_end (arg_ptr);

    printf (RESET);
}

char parsing (int argc, char *argv[]){
    while (--argc > 0 && (*++argv)[0] == '-'){
        char ch = 0;
        ch = *++argv[0];

        switch (ch){
            case 't':
                return TEST_FLAG;

            default:
                return NOTHING;
        }
    }
}
