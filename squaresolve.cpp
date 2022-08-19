#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>
#include "Squaref.h"

char solve (double a, double b, double c, double *x1, double *x2, char *T){
    assert (isfinite(a) && isfinite(b) && isfinite(c) && "vals must not be NAN/INF");
    assert (x1 != NULL && x2 != NULL && "ptrs must not be NULL");
    assert (T && "ptrs must not be NULL");

    *T = get_type (a, b, c);
    switch (*T){
        case INF_ROOTS:
            return -1;

        case SQUARE: //second degree equation
            return square_solve (a, b, c, x1, x2);

        case ONE_ROOT: //liner equation
            return line_solve (b, c, x1);

        case NO_ROOTS:
            return 0;

        default:
            return ANOTHER;
    }
}

char get_type (double a, double b, double c){
    assert (isfinite(a) && isfinite(b) && isfinite(c) && "vals must not be NAN/INF");

    if (is_zero(a))
        if (is_zero(b))
            if (is_zero(c))
                return INF_ROOTS;
            else
                return NO_ROOTS;
        else
            return ONE_ROOT;
    else
        return SQUARE;

    return ANOTHER;
}

char square_solve (double a, double b, double c, double *x1, double *x2){  // solve second degree equation
    assert (isfinite(a) && isfinite(b) && isfinite(c) && "vals must not be NAN/INF");
    assert (x1 != NULL && x2 != NULL && "ptrs must not be NULL");
    assert(!is_zero(a) && "must not be zero");

    double D = discriminant (a, b, c);

    if (is_zero(D)){
        *x1 = -b / (2*a);
        return ONE_ROOT;
    }

    if(D < 0.0)
        return NO_ROOTS;

    D = sqrt(D);
    a *= 2;

    if (D > 0.0){
        *x1 = (-b + D) / a;
        *x2 = (-b - D) / a;
        return SQUARE;
    }

    return ANOTHER;
}

double discriminant (double a, double b, double c){ //searcing discriminant
    assert (isfinite(a) && isfinite(b) && isfinite(c) && "vals must not be NAN/INF");

    return b*b - 4*a*c;
}

char line_solve (double a, double b, double *x){ // solve liner equation
    assert (isfinite(a) && isfinite(b) && "vals must not be NAN/INF");
    assert (x != NULL && "ptrs must not be NULL");
    assert (!is_zero(a) && "must not be zero");

    *x = -b / a;

    return ONE_ROOT;
}

bool is_zero (double n){
    assert (isfinite(n) && "vals must not be NAN/INF");

    return fabs(n) < EPS;
}

double fix_zero (double n){
    assert (isfinite(n) && "vals must not be NAN/INF");

    if (is_zero(n))
        return 0.0;
    return n;
}

bool read_arguments (double *a, double *b, double *c){ //reading arguments
    assert (a != NULL && b != NULL && c != NULL && "ptrs must not be NULL");

    if (scanf ("%lf%lf%lf", a, b, c) != 3){
        printf ("Invalid value entry\n");
        return false;
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

        default:
            printf ("ERROR\n");
            break;
    }

    return;
}
