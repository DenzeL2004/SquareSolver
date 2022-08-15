#include <stdio.h>
#include <math.h>
#include <TXLib.h>

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

void solve1(double a, double b, double c){  // Решение квдратного уравнения

    double D = dis(a, b, c);

    if(D < 0.0)
        printf("Решений нет\n");

    if(D == 0.0){
        printf("Уравнение имеет ровно один корень\n");
        double x1, x2;
        search_solves(a, b, D, &x1, &x2);
        printf("x = %.6lf", x1);
    }

    if(D > 0.0){
        printf("Уравнение имеет два корня\n");
        double x1, x2;
        search_solves(a, b, D, &x1, &x2);
        printf("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
    }
}

void solve2(double a, double b){ // решение линейного уравнения
    double x;
    x = 0.0;
    x = -b/a;
    printf("Уравнение имеет ровно один корень\n");
    printf("x = %.6lf", x);
}

int main(){
    printf("Введите коэффиценты a, b, c квадратного уравнения ax^2+bx+c = 0\n");

    double a, b, c;
    a = b = c = 0.0;

    if(scanf("%lf%lf%lf", &a, &b, &c) != 3){
        printf("Неверный ввод значений\n");
        getchar();
        return 0;
    }

    switch(type(a, b, c)){
        case 0: //Тривиальное уравнение
            printf("Бесконечное множество решений\n");
            break;
        case 1: //Квадратное уравнение
            solve1(a, b, c);
            break;
        case 2: //Линейное уравнение
            solve2(b, c);
            break;
        case 3: //Решений нет
            printf("Решение нет\n");
            break;
        default:
            printf("ERROR\n");
            break;

    }

    getchar();
    return 0;
}

