#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>
#include "Squaref.h"

char solve_square (double a, double b, double c, double *x1, double *x2){
    assert (isfinite (a) && isfinite (b) && isfinite (c) && "vals must not be NAN/INF");
    assert (x1 != NULL && x2 != NULL && "ptrs must not be NULL");

    char type_equation = get_Type (a, b, c);
    switch (type_equation){
        case INF_ROOTS:
            return INF_ROOTS;

        case SQUARE:
            return square_equation (a, b, c, x1, x2);

        case ONE_ROOT:
            return liner_equation (b, c, x1);

        case NO_ROOTS:
            return NO_ROOTS;

        default:
            return ANOTHER;
    }
}

char get_Type (double a, double b, double c){
    assert (isfinite (a) && isfinite (b) && isfinite (c) && "vals must not be NAN/INF");

    if (is_zero (a))
        if (is_zero (b))
            if (is_zero (c))
                return INF_ROOTS;
            else
                return NO_ROOTS;
        else
            return ONE_ROOT;
    else
        return SQUARE;

    return ANOTHER;
}

char square_equation (double a, double b, double c, double *x1, double *x2){
    assert (isfinite (a) && isfinite (b) && isfinite (c) && "vals must not be NAN/INF");
    assert (x1 != NULL && x2 != NULL && "ptrs must not be NULL");
    assert(!is_zero (a) && "must not be zero");

    double D = Discriminant (a, b, c);

    a *= 2;

    if (is_zero (D)){
        *x1 = -b / a;
        return ONE_ROOT;
    }

    if (D < 0.0)
        return NO_ROOTS;

    double sqrt_D = sqrt (D);

    if (D > 0.0){
        *x1 = (-b + sqrt_D) / a;
        *x2 = (-b - sqrt_D) / a;
        return SQUARE;
    }

    return ANOTHER;
}

double Discriminant (double a, double b, double c){
    assert (isfinite (a) && isfinite (b) && isfinite (c) && "vals must not be NAN/INF");

    return b*b - 4*a*c;
}

char liner_equation (double a, double b, double *x){
    assert (isfinite (a) && isfinite (b) && "vals must not be NAN/INF");
    assert (x != NULL && "ptrs must not be NULL");
    assert (!is_zero (a) && "must not be zero");

    *x = -b / a;

    return ONE_ROOT;
}

bool is_zero (double n){
    assert (isfinite (n) && "vals must not be NAN/INF");

    return fabs (n) < Eps;
}

double fix_zero (double n){
    assert (isfinite (n) && "vals must not be NAN/INF");

    if (is_zero (n))
        return 0.0;
    return n;
}

bool read_arguments (double *a, double *b, double *c){
    assert (a != NULL && b != NULL && c != NULL && "ptrs must not be NULL");

    if (scanf ("%lf%lf%lf", a, b, c) != 3){
        printf ("Invalid value entry\n");
        return false;
    }

    char ch = 0;
    while ((ch = (char)getchar()) != '\n'){
        if (ch == ' ' || ch == '\t')
            continue;
        else{
            printf("Too many values\n");
            return false;
        }

    }

    return true;
}

void write_result (char count_roots, double x1, double x2){
    switch (count_roots){
        case INF_ROOTS:
            printf ("Equation has an infinite number of solutions\n");
            break;

        case SQUARE:
            if (is_zero(x1))
                x1 = fix_zero(x1);

            if (is_zero(x2))
                x2 = fix_zero(x2);

            printf ("Equation has two different solutions\n");
            printf ("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
            break;

        case ONE_ROOT:
            printf ("Equation has exactly one solution\n");

            if (is_zero(x1))
                x1 = fix_zero(x1);

            printf ("x = %.6lf\n", x1);
            break;

        case NO_ROOTS:
            printf ("Equation has no solution\n");
            break;

        case ANOTHER: [[fallthrough]]
        default:
            printf ("ERROR\n");
            break;
    }

    return;
}
