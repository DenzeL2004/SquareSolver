#include <stdio.h>
#include <math.h>
#include <TXLib.h>

void read_arguments(double *a, double *b, double *c){

    if(scanf("%lf%lf%lf", a, b, c) != 3){
        printf("Неверный ввод значений\n");
        getchar();
        exit(0);
    }
}

char type(double a, double b, double c){
    if(a == 0.0)

        if(b == 0.0)

            if(c == 0.0)
                return 0;
            else
                return 3;
        else
            return 2;
    else
        return 1;
}

double dis(double a, double b, double c){ //поиск дескрименанта
    return b*b - 4*a*c;
}

void search_solves(double a, double b, double D, double *x1, double *x2){ //поиск корней квадратного уравнения x1, x2
    *x1 = (-b + sqrt(D))/(2*a);
    *x2 = (-b - sqrt(D))/(2*a);
}

void solve1(double a, double b, double c, double *x1, double *x2){  // Решение квдратного уравнения

    double D = dis(a, b, c);

    if(D == 0.0){
        search_solves(a, b, D, x1, x2);
        *x2 = NAN;
    }

    if(D > 0.0)
        search_solves(a, b, D, x1, x2);

}

void solve2(double a, double b, double *x){ // решение линейного уравнения
    *x = -b/a;
}

void write_result(char T, double x1, double x2){

    switch(T){
        case 0:
            printf("Бесконечное множество решений\n");
            break;
        case 1:
            if(isnan(x1) == 1 && isnan(x2) == 1)
                printf("Решений нет\n");

            if(isnan(x1) != 1 && isnan(x2) == 1){
                printf("Уравнение имеет роано одно решение\n");
                printf("x = %.6lf\n", x1);
            }

            if(isnan(x1) != 1 && isnan(x2) != 1){
                printf("Уравнение имеет два различных решения\n");
                printf("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
            }

            break;
        case 2:
            printf("Уравнение имеет ровно один корень\n");
            printf("x = %.6lf\n", x1);
            break;
        case 3:
            printf("Решений нет\n");
            break;
        default:
            printf("ERROR\n");
            break;
    }

}

int main(){
    printf("Введите коэффиценты a, b, c квадратного уравнения ax^2+bx+c = 0\n");

    double a = NAN, b = NAN, c = NAN;
    read_arguments(&a, &b, &c);

    char T = type(a, b, c);
    double x1 = NAN, x2 = NAN;

    switch(T){
        case 1: //Квадратное уравнение
            solve1(a, b, c, &x1, &x2);
            break;
        case 2: //Линейное уравнение
            solve2(b, c, &x1);
            break;
        default:
            break;

    }

    write_result(T, x1, x2);

    getchar();
    return 0;
}

