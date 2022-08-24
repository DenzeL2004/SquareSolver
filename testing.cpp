#include <stdio.h>
#include <math.h>
#include "headers\Squaref.h"
#include "headers\Testf.h"
#include "headers\Generals.h"

const int Cnt_test = 6;

Parameters paramet[Cnt_test] = {{1,  2, 3,  NO_ROOTS,           NAN, NAN},
                                {1, -2, 1,  ONE_ROOT,             1, NAN},
                                {0,  0, 0, INF_ROOTS,           NAN, NAN},
                                {0,  3, 1,  ONE_ROOT, -0.3333333334, NAN},
                                {0,  0, 3,  NO_ROOTS,           NAN, NAN},
                                {1,  3, 2,    SQUARE,            -1,  -2}};

void unit_test(){
    for (int current_test = 0; current_test < Cnt_test; current_test++){
        double a = paramet[current_test].a,
               b = paramet[current_test].b,
               c = paramet[current_test].c;

        double x1 = NAN, x2 = NAN;
        char count_roots = 0;
        count_roots = solve_square (a, b, c, &x1, &x2);
        check_equality (x1, x2, count_roots, paramet[current_test], current_test+1);
        putchar ('\n');
    }


    return;
}

bool check_equality (double cur_x1, double cur_x2, char cur_count_roots, Parameters ans_param, int test_number){
    print_colour (YELLOW, "TEST NUMBER %d\n", test_number);
    print_colour (BLUE, "Input arguments:\n");
    printf ("a = %lf\nb = %lf\nc = %lf\n", ans_param.a, ans_param.b, ans_param.c);
    putchar ('\n');

    if (cur_count_roots != ans_param.count_roots){
        print_colour (RED, "FAILED:\n");
        print_colour (YELLOW, "Waiting ");
        print_result (GREEN, ans_param.count_roots);
        printf ("count roots = %d\nx1 = %lf\nx2 = %lf\n", ans_param.count_roots, ans_param.x1, ans_param.x2);

        putchar ('\n');

        print_colour (YELLOW, "Received ");
        print_result (RED, cur_count_roots);
        printf ("count roots = %d\nx1 = %lf\nx2 = %lf\n", cur_count_roots, cur_x1, cur_x2);

        return false;
    }

    switch (cur_count_roots){
        case NO_ROOTS:
            print_colour (GREEN, "OK not roots\n");
            return true;

        case INF_ROOTS:
            print_colour (GREEN, "OK inf roots\n");
            return true;

        case SQUARE:
            if (is_zero (cur_x1))
                cur_x1 = fix_zero (cur_x1);

            if (is_zero (cur_x2))
                cur_x2 = fix_zero (cur_x2);

            if (equality_double (cur_x1, ans_param.x1) && equality_double (cur_x2, ans_param.x2)){
                print_colour (GREEN, "OK two roots\n");
                printf ("x1 = %.6lf\nx2 = %.6lf\n", cur_x1, cur_x2);
                return true;
            }
            else{
                print_colour (RED, "WRONG\n");
                printf ("cur_x1 = %.6lf cur_x2 = %.6lf\n", cur_x1, cur_x2);
                printf ("ans_x1 = %.6lf ans_x2 = %.6lf\n", ans_param.x1, ans_param.x2);
                return false;
            }

        case ONE_ROOT:
            if (is_zero (cur_x1))
                cur_x1 = fix_zero (cur_x1);

            if (equality_double (cur_x1, ans_param.x1)){
                print_colour (GREEN, "OK one root\n");
                printf ("x = %.6lf\n", cur_x1);
                return true;
            }
            else{
                print_colour (RED, "WRONG\n");
                printf ("cur_x = %.6lf\n", cur_x1);
                printf ("ans_x = %.6lf\n", ans_param.x1);
                return false;
            }

        case ANOTHER: [[fallthrough]]
        default:
            print_colour (RED, "ERROR\n");
            return false;
    }
}

void print_result (const char colour[], int count_roots){
    switch (count_roots){
        case NO_ROOTS:
            print_colour (colour, "not roots\n");
            break;

        case INF_ROOTS:
            print_colour (colour, "inf roots\n");
            break;

        case SQUARE:
            print_colour (colour, "two roots\n");
            break;

        case ONE_ROOT:
            print_colour (colour, "one roots\n");
            break;

        case ANOTHER: [[fallthrough]]
        default:
            print_colour (RED, "ERROR\n");
            break;
    }
}
