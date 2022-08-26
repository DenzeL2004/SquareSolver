#include <stdio.h>
#include <math.h>

#include "headers\Squaref.h"
#include "headers\Testf.h"
#include "headers\Generals.h"

int main(int argc, char *argv[]){

    int unit_test_flag = parsing (argc, argv);

    if (unit_test_flag == TEST_FLAG)
        unit_test();

    printf ("Enter the coefficients a, b, c of the second degree equation ax^2+bx+c = 0\n");

    double a = NAN, b = NAN, c = NAN;

    if (!read_arguments (&a, &b, &c))
        return -1;

    double x1 = NAN, x2 = NAN;
    char count_roots = 0;
    count_roots = solve_square (a, b, c, &x1, &x1);
    write_result (count_roots, x1, x2);

    return 0;
}
