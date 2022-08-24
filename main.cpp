
#include <stdio.h>
#include <math.h>
#include "headers\Squaref.h"
#include "headers\Testf.h"
#include "headers\Generals.h"

int main(int argc, char *argv[]){

    int flag_test = 0;
    while (--argc > 0 && (*++argv)[0] == '-'){
        char ch = 0;
        ch = *++argv[0];
        switch (ch){
            case 't':
                flag_test = 1;
                break;

            default:
                break;
        }
    }

    if (flag_test)
        unit_test();
    else{
        printf ("Enter the coefficients a, b, c of the second degree equation ax^2+bx+c = 0\n");

        double a = NAN, b = NAN, c = NAN;

        if (!read_arguments (&a, &b, &c))
            return -1;

        double x1 = NAN, x2 = NAN;
        char count_roots = 0;
        count_roots = solve_square (a, b, c, &x1, &x2);
        write_result (count_roots, x1, x2);
    }

    return 0;
}
