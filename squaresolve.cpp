#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <assert.h>

enum state {INF_ROOTS = 0, LINE = 1, SQUARE = 2, NO_ROOTS = 3, ANOTHER = 4};

int read_arguments (double *a, double *b, double *c){
    assert (*a != NULL);
    assert (*b != NULL);
    assert (*c != NULL);

    if (scanf ("%lf%lf%lf", a, b, c) != 3){
        printf ("Неверный ввод значений\n");
        getchar();
        return 0;
    }

    return 1;
}

char type (double a, double b, double c){
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

double discriminant (double a, double b, double c){ //поиск дескрименанта
    return b*b - 4*a*c;
}

void square_solve (double a, double b, double c, double *x1, double *x2){  // Решение квдратного уравнения
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

void line_solve (double a, double b, double *x){ // решение линейного уравнения
    *x = -b/a;
}

void square_solution (double a, double b, double c, double *x1, double *x2, char *T){
    *T = type (a, b, c);
    switch (*T){
        case SQUARE: //Квадратное уравнение
            square_solve (a, b, c, x1, x2);
            break;

        case LINE: //Линейное уравнение
            line_solve (b, c, x1);
            break;

        default:
            break;
    }
}

void write_result (char T, double x1, double x2){
    switch (T){
        case INF_ROOTS:
            printf ("Бесконечное множество решений\n");
            break;

        case SQUARE:
            if (isnan(x1) && isnan(x2))
                printf ("Решений нет\n");

            if (!isnan(x1) && isnan(x2)){
                printf ("Уравнение имеет роано одно решение\n");
                printf ("x = %.6lf\n", x1);
            }

            if (!isnan(x1) && !isnan(x2) ){
                printf ("Уравнение имеет два различных решения\n");
                printf ("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
            }
            break;

        case LINE:
            printf ("Уравнение имеет ровно один корень\n");
            printf ("x = %.6lf\n", x1);
            break;

        case NO_ROOTS:
            printf ("Решений нет\n");
            break;

        default:
            printf ("ERROR\n");
            break;
    }

}

int main(){
    printf ("Введите коэффиценты a, b, c квадратного уравнения ax^2+bx+c = 0\n");

    double a = NAN, b = NAN, c = NAN;

    if (!read_arguments (&a, &b, &c))
        return 0;

    if (isnan(a) || isnan(b) || isnan(c)){
        printf("Один из аргументов равен NAN\n");
        return 0;
    }

    double x1 = NAN, x2 = NAN;
    char T = ANOTHER;
    square_solution (a, b, c, &x1, &x2, &T);
    write_result (T, x1, x2);

    getchar();
    return 0;
}

