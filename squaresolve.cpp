#include <stdio.h>
#include <TXLib.h>
float dis(float a, float b, float c){ // Расчет дескрименанта
    return b*b - 4*a*c;
}
void solves(float a, float b, float D, float &x1, float &x2) { //Поиск корней
    x1 = (-b + sqrt(D))/(2*a);
    x2 = (-b - sqrt(D))/(2*a);
}
int main(){
    printf("������� ����������� a, b, c ����������� ��������� ax^2+bx+c = 0\n");
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);

    float D = dis(a, b, c);
    if(D < 0.0)
        printf("������� ���\n");
    if(D == 0.0){
        printf("��������� ����� ����� ���� ������\n");
        float x1, x2;
        solves(a, b, D, x1, x2);
        printf("x = %.6f", x1);
    }
    if(D > 0.0){
        printf("��������� ����� ��� �����\n");
        float x1, x2;
        solves(a, b, D, x1, x2);
        printf("x1 = %.6f\nx2 = %.6f\n", x1, x2);
    }
    getchar();
    return 0;
}
