#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>

enum state {INF_ROOTS = 0, LINE = 1, SQUARE = 2, NO_ROOTS = 3, ANOTHER = 4};

void check_arguments_pointer (double *a, double *b, double *c){
    assert (*a != NULL);
    assert (*b != NULL);
    assert (*c != NULL);
}

void check_arguments_val (double a, double b, double c){
    assert (!isnan(a));
    assert (!isnan(b));
    assert (!isnan(c));
}

int read_arguments (double *a, double *b, double *c){
    check_arguments_pointer (a, b, c);

    if (scanf ("%lf%lf%lf", a, b, c) != 3){
        printf ("�������� ���� ��������\n");
        getchar();
        return 0;
    }

    return 1;
}

char type (double a, double b, double c){
    check_arguments_val (a, b, c);

    if (a == 0.0)
        if (b == 0.0)
            if (c == 0.0)
                return INF_ROOTS;
            else
                return NO_ROOTS;
        else
            return LINE;
    else
        return SQUARE;

    return ANOTHER;
}

double discriminant (double a, double b, double c){ //����� �������������
    check_arguments_val (a, b, c);
    return b*b - 4*a*c;
}

void square_solve (double a, double b, double c, double *x1, double *x2){  // ������� ���������� ���������
    check_arguments_val (a, b, c);
    double D = discriminant (a, b, c);

    if (D == 0.0){
        *x1 = -b/(2*a);
        *x2 = NAN;
    }

    if (D > 0.0){
        *x1 = (-b + sqrt(D))/(2*a);
        *x2 = (-b - sqrt(D))/(2*a);
    }
}

void line_solve (double a, double b, double *x){ // ������� ��������� ���������
    assert (!isnan(a));
    assert (!isnan(b));

    *x = -b/a;
}

void square_solution (double a, double b, double c, double *x1, double *x2, char *T){
    *T = type (a, b, c);
    switch (*T){
        case SQUARE: //���������� ���������
            square_solve (a, b, c, x1, x2);
            break;

        case LINE: //�������� ���������
            line_solve (b, c, x1);
            break;

        default:
            break;
    }
}

void write_result (char T, double x1, double x2){
    switch (T){
        case INF_ROOTS:
            printf ("����������� ��������� �������\n");
            break;

        case SQUARE:
            if (isnan(x1) && isnan(x2))
                printf ("������� ���\n");

            if (!isnan(x1) && isnan(x2)){
                printf ("��������� ����� ����� ���� �������\n");
                printf ("x = %.6lf\n", x1);
            }

            if (!isnan(x1) && !isnan(x2) ){
                printf ("��������� ����� ��� ��������� �������\n");
                printf ("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
            }
            break;

        case LINE:
            printf ("��������� ����� ����� ���� ������\n");
            printf ("x = %.6lf\n", x1);
            break;

        case NO_ROOTS:
            printf ("������� ���\n");
            break;

        default:
            printf ("ERROR\n");
            break;
    }

}

int main(){
    printf ("������� ����������� a, b, c ����������� ��������� ax^2+bx+c = 0\n");

    double a = NAN, b = NAN, c = NAN;

    if (!read_arguments (&a, &b, &c))
        return 0;

    check_arguments_val (a, b, c);

    double x1 = NAN, x2 = NAN;
    char T = ANOTHER;
    square_solution (a, b, c, &x1, &x2, &T);
    write_result (T, x1, x2);

    getchar();
    return 0;
}

