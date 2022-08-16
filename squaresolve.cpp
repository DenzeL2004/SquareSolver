#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>
#include "Squaref.h"

const long double EPS = 1e-9;
enum state {INF_ROOTS = -1, NO_ROOTS = 0, ONE_ROOT = 1, SQUARE = 2, ANOTHER = 3};

/** \brief сравнивает нецелочисленные типы с 0
    \param число, которое нужно проверить
    \code
    bool is_zero (double n){
        return (n == 0.0) || (fabs(n) < EPS);
    }
    \endcode
*/
bool is_zero (double n);

int main(){
    printf ("Введите коэффиценты a, b, c квадратного уравнения ax^2+bx+c = 0\n");

    double a = NAN, b = NAN, c = NAN;

    if (!read_arguments (&a, &b, &c))
        return 0;

    double x1 = NAN, x2 = NAN;
    char T = ANOTHER, count_roots = 0;
    count_roots = count_solves (a, b, c, &x1, &x2, &T);
    write_result (count_roots, x1, x2);

    getchar();
    return 0;
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

        case ONE_ROOT: //Линейное уравнение
            return line_solve (b, c, x1);

        case NO_ROOTS:
            return 0;

        default:
            return ANOTHER;
    }
}

char type (double a, double b, double c){
    assert (!isnan(a));
    assert (!isnan(b));
    assert (!isnan(c));

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
    assert (!isnan(a));
    assert (!isnan(b));
    assert (!isnan(c));

    double D = discriminant (a, b, c);

    if (is_zero(D)){
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
    assert (!isnan(a));
    assert (!isnan(b));
    assert (!isnan(c));

    return b*b - 4*a*c;
}

char line_solve (double a, double b, double *x){ // решение линейного уравнения
    assert (!isnan(a));
    assert (!isnan(b));

    *x = -b/a;

    return 1;
}

int read_arguments (double *a, double *b, double *c){ //считывание значений
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
        printf ("Уравнение имеет роано одно решение\n");

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

bool is_zero (double n){
    return (n == 0.0) || (fabs(n) < EPS);
}
