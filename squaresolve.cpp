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

double dis(double a, double b, double c){ //����� �������������
    return b*b - 4*a*c;
}

void search_solves(double a, double b, double D, double *x1, double *x2){ //����� ������ ����������� ��������� x1, x2
    *x1 = (-b + sqrt(D))/(2*a);
    *x2 = (-b - sqrt(D))/(2*a);
}

void solve1(double a, double b, double c){  // ������� ���������� ���������

    double D = dis(a, b, c);

    if(D < 0.0)
        printf("������� ���\n");

    if(D == 0.0){
        printf("��������� ����� ����� ���� ������\n");
        double x1, x2;
        search_solves(a, b, D, &x1, &x2);
        printf("x = %.6lf", x1);
    }

    if(D > 0.0){
        printf("��������� ����� ��� �����\n");
        double x1, x2;
        search_solves(a, b, D, &x1, &x2);
        printf("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
    }
}

void solve2(double a, double b){ // ������� ��������� ���������
    double x;
    x = 0.0;
    x = -b/a;
    printf("��������� ����� ����� ���� ������\n");
    printf("x = %.6lf", x);
}

int main(){
    printf("������� ����������� a, b, c ����������� ��������� ax^2+bx+c = 0\n");

    double a, b, c;
    a = b = c = 0.0;

    if(scanf("%lf%lf%lf", &a, &b, &c) != 3){
        printf("�������� ���� ��������\n");
        getchar();
        return 0;
    }

    switch(type(a, b, c)){
        case 0: //����������� ���������
            printf("����������� ��������� �������\n");
            break;
        case 1: //���������� ���������
            solve1(a, b, c);
            break;
        case 2: //�������� ���������
            solve2(b, c);
            break;
        case 3: //������� ���
            printf("������� ���\n");
            break;
        default:
            printf("ERROR\n");
            break;

    }

    getchar();
    return 0;
}

