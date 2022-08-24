#ifndef _TESTF_H_
#define _TESTF_H_

typedef struct Parameters_equation {
    double a, b, c;
    int count_roots;
    double x1, x2;
} Parameters;

void unit_test();
bool check_equality (double cur_x1, double cur_x2, char cur_count_roots, double ans_x1, double ans_x2, char ans_count_roots);
void print_result (int count_roots);

#endif
