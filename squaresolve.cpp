#include <stdio.h>
#include <math.h>
#include <TXLib.h>

void read_arguments(double *a, double *b, double *c){

    if(scanf("%lf%lf%lf", a, b, c) != 3){
        printf("�������� ���� ��������\n");
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

double dis(double a, double b, double c){ //����� �������������
    return b*b - 4*a*c;
}

void search_solves(double a, double b, double D, double *x1, double *x2){ //����� ������ ����������� ��������� x1, x2
    *x1 = (-b + sqrt(D))/(2*a);
    *x2 = (-b - sqrt(D))/(2*a);
}

void solve1(double a, double b, double c, double *x1, double *x2){  // ������� ���������� ���������

    double D = dis(a, b, c);

    if(D == 0.0){
        search_solves(a, b, D, x1, x2);
        *x2 = NAN;
    }

    if(D > 0.0)
        search_solves(a, b, D, x1, x2);

}

void solve2(double a, double b, double *x){ // ������� ��������� ���������
    *x = -b/a;
}

void write_result(char T, double x1, double x2){

    switch(T){
        case 0:
            printf("����������� ��������� �������\n");
            break;
        case 1:
            if(isnan(x1) == 1 && isnan(x2) == 1)
                printf("������� ���\n");

            if(isnan(x1) != 1 && isnan(x2) == 1){
                printf("��������� ����� ����� ���� �������\n");
                printf("x = %.6lf\n", x1);
            }

            if(isnan(x1) != 1 && isnan(x2) != 1){
                printf("��������� ����� ��� ��������� �������\n");
                printf("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
            }

            break;
        case 2:
            printf("��������� ����� ����� ���� ������\n");
            printf("x = %.6lf\n", x1);
            break;
        case 3:
            printf("������� ���\n");
            break;
        default:
            printf("ERROR\n");
            break;
    }

}

int main(){
    printf("������� ����������� a, b, c ����������� ��������� ax^2+bx+c = 0\n");

    double a = NAN, b = NAN, c = NAN;
    read_arguments(&a, &b, &c);

    char T = type(a, b, c);
    double x1 = NAN, x2 = NAN;

    switch(T){
        case 1: //���������� ���������
            solve1(a, b, c, &x1, &x2);
            break;
        case 2: //�������� ���������
            solve2(b, c, &x1);
            break;
        default:
            break;

    }

    write_result(T, x1, x2);

    getchar();
    return 0;
}

