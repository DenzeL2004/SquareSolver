#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>
#include "Squaref.h"

const long double EPS = 1e-9;

char count_solves (double a, double b, double c, double *x1, double *x2, char *T){
    assert (!isnan(a) && !isnan(b) && !isnan(c) && "vals must not be NAN");

    *T = type (a, b, c);
    switch (*T){
        case INF_ROOTS:
            return -1;

        case SQUARE: //Квадратное уравнение
            return square_solve (a, b, c, x1, x2);

        case ONE_ROOT: //Линейное уравнение
            return line_solve (b, c, x1);

        case NO_ROOTS:
            return 0;

        default:
            return ANOTHER;
    }
}

char type (double a, double b, double c){
    assert (!isnan(a) && !isnan(b) && !isnan(c) && "vals must not be NAN");

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

char square_solve (double a, double b, double c, double *x1, double *x2){  // Решение квдратного уравнения
    assert (!isnan(a) && !isnan(b) && !isnan(c) && "vals must not be NAN");

    double D = discriminant (a, b, c);

    if (is_zero (D)){
        *x1 = -b/(2*a);
        return 1;
    }

    if(D < 0.0)
        return 0;

    if (D > 0.0){
        *x1 = (-b + sqrt(D))/(2*a);
        *x2 = (-b - sqrt(D))/(2*a);
        return 2;
    }
}

double discriminant (double a, double b, double c){ //поиск дескрименанта
    assert (!isnan(a) && !isnan(b) && !isnan(c) && "vals must not be NAN");

    return b*b - 4*a*c;
}

char line_solve (double a, double b, double *x){ // решение линейного уравнения
    assert (!isnan(a) && !isnan(b) && "vals must not be NAN");

    *x = -b/a;

    return 1;
}

bool is_zero (double n){
    return (n == 0.0) || (fabs(n) < EPS);
}

int read_arguments (double *a, double *b, double *c){ //считывание значений
    assert (a != NULL && b != NULL && c != NULL && "ptrs must not be NULL");

    if (scanf ("%lf%lf%lf", a, b, c) != 3){
        printf ("Неверный ввод значений\n");
        return 0;
    }

    return 1;
}

void write_result (char count_roots, double x1, double x2){ //Вывод кол-ва корней
    if (count_roots == INF_ROOTS){
        printf ("Бесконечное множество решений\n");
        return;
    }

    if (count_roots == NO_ROOTS){
        printf ("Решений нет\n");
        return;
    }

    if (count_roots == ONE_ROOT){
        printf ("Уравнение имеет ровно одно решение\n");

        if (is_zero(x1))
            x1 = -x1;

        printf ("x = %.6lf\n", x1);
        return;
    }

    if (count_roots == SQUARE){
        printf ("Уравнение имеет два различных решения\n");
        printf ("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
        return;
    }

    printf ("ERROR\n");
    return;
}
