#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>
#include "Squaref.h"

const long double eps = 1e-9;
enum state {INF_ROOTS = 0, LINE = 1, SQUARE = 2, NO_ROOTS = 3, ANOTHER = 4};

int read_arguments (double *a, double *b, double *c){
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    if (scanf ("%lf%lf%lf", a, b, c) != 3){
        printf ("Неверный ввод значений\n");
        getchar();
        return 0;
    }

    return 1;
}

char type (double a, double b, double c){
    assert (!isnan(a));
    assert (!isnan(b));
    assert (!isnan(c));

    if (fabs(a) < eps)
        if (fabs(b) < eps)
            if (fabs(c) < eps)
                return INF_ROOTS;
            else
                return NO_ROOTS;
        else
            return LINE;
    else
        return SQUARE;

    return ANOTHER;
}

double discriminant (double a, double b, double c){ //поиск дескрименанта
    assert (!isnan(a));
    assert (!isnan(b));
    assert (!isnan(c));

    return b*b - 4*a*c;
}

char square_solve (double a, double b, double c, double *x1, double *x2){  // Решение квдратного уравнения
    assert (!isnan(a));
    assert (!isnan(b));
    assert (!isnan(c));

    double D = discriminant (a, b, c);

    if(D < -eps)
        return 0;

    if (fabs(D) < eps){
        *x1 = -b/(2*a);
        return 1;
    }

    if (D > eps){
        *x1 = (-b + sqrt(D))/(2*a);
        *x2 = (-b - sqrt(D))/(2*a);
        return 2;
    }
}

char line_solve (double a, double b, double *x){ // решение линейного уравнения
    assert (!isnan(a));
    assert (!isnan(b));

    *x = -b/a;

    return 1;
}

char count_solves (double a, double b, double c, double *x1, double *x2, char *T){
    assert (!isnan(a));
    assert (!isnan(b));
    assert (!isnan(c));

    *T = type (a, b, c);
    switch (*T){
        case INF_ROOTS:
            return -1;

        case SQUARE: //Квадратное уравнение
            return square_solve (a, b, c, x1, x2);

        case LINE: //Линейное уравнение
            return line_solve (b, c, x1);

        case NO_ROOTS:
            return 0;

        default:
            return CHAR_MIN;
    }
}

void write_result (char cnt, double x1, double x2){
    if (cnt == -1){
        printf ("Бесконечное множество решений\n");
        return;
    }

    if (cnt == 0){
        printf ("Решений нет\n");
        return;
    }

    if (cnt == 1){
        printf ("Уравнение имеет роано одно решение\n");

        if(fabs(x1) < eps)
            x1 = -x1;

        printf ("x = %.6lf\n", x1);
        return;
    }

    if(cnt == 2){
        printf ("Уравнение имеет два различных решения\n");
        printf ("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
        return;
    }

    printf("ERROR\n");
    return;

}

int main(){
    printf ("Введите коэффиценты a, b, c квадратного уравнения ax^2+bx+c = 0\n");

    double a = NAN, b = NAN, c = NAN;

    if (!read_arguments (&a, &b, &c))
        return 0;

    double x1 = NAN, x2 = NAN;
    char T = ANOTHER, cnt = 0;
    cnt = count_solves (a, b, c, &x1, &x2, &T);
    write_result (cnt, x1, x2);

    getchar();
    return 0;
}

