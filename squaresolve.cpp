#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>
#include "Squaref.h"

char solve (double a, double b, double c, double *x1, double *x2, char *T){
    assert (!isnan(a) && !isnan(b) && !isnan(c) && "vals must not be NAN");
    assert (&a != NULL && &b != NULL && &c != NULL && "ptrs must not be NULL");

    *T = get_type (a, b, c);
    switch (*T){
        case INF_ROOTS:
            return -1;

        case SQUARE: //���������� ���������
            return square_solve (a, b, c, x1, x2);

        case ONE_ROOT: //�������� ���������
            return line_solve (b, c, x1);

        case NO_ROOTS:
            return 0;

        default:
            return ANOTHER;
    }
}

char get_type (double a, double b, double c){
    assert (!isnan(a) && !isnan(b) && !isnan(c) && "vals must not be NAN");
    assert (&a != NULL && &b != NULL && &c != NULL && "ptrs must not be NULL");

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

char square_solve (double a, double b, double c, double *x1, double *x2){  // ������� ���������� ���������
    assert (!isnan(a) && !isnan(b) && !isnan(c) && "vals must not be NAN");
    assert (&a != NULL && &b != NULL && &c != NULL && "ptrs must not be NULL");
    assert(!is_zero(a) && "must not be zero");

    double D = discriminant (a, b, c);

    if (is_zero(D)){
        *x1 = -b / (2 * a);
        return 1;
    }

    if(D < 0.0)
        return 0;

    if (D > 0.0){
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return 2;
    }

    return ANOTHER;
}

double discriminant (double a, double b, double c){ //����� �������������
    assert (!isnan(a) && !isnan(b) && !isnan(c) && "vals must not be NAN");
    assert (&a != NULL && &b != NULL && &c != NULL && "ptrs must not be NULL");

    return b * b - 4 * a * c;
}

char line_solve (double a, double b, double *x){ // ������� ��������� ���������
    assert (!isnan(a) && !isnan(b) && "vals must not be NAN");
    assert (&a != NULL && &b != NULL && "ptrs must not be NULL");
    assert(!is_zero(a) && "must not be zero");

    *x = -b / a;

    return 1;
}

bool is_zero (double n){
    return fabs(n) < EPS;
}

int read_arguments (double *a, double *b, double *c){ //���������� ��������
    assert (a != NULL && b != NULL && c != NULL && "ptrs must not be NULL");

    if (scanf ("%lf%lf%lf", a, b, c) != 3){
        printf ("�������� ���� ��������\n");
        return 0;
    }

    return 1;
}

void write_result (char count_roots, double x1, double x2){
    switch (count_roots){
        case INF_ROOTS:
            printf ("����������� ��������� �������\n");
            break;

        case SQUARE:
            printf ("��������� ����� ��� ��������� �������\n");
            printf ("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
            break;

        case ONE_ROOT:
            printf ("��������� ����� ����� ���� �������\n");

            if (is_zero(x1))
                x1 = -x1;

            printf ("x = %.6lf\n", x1);
            break;

        case NO_ROOTS:
            printf ("������� ���\n");
            break;

        default:
            printf ("ERROR\n");
            break;
    }

    return;
}
