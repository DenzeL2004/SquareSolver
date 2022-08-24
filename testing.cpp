#include <stdio.h>
#include <math.h>
#include "headers\Squaref.h"
#include "headers\Testf.h"

Parameters paramet[6] = {{1,  2, 3,  NO_ROOTS,          NAN, NAN},
                         {1, -2, 1,  ONE_ROOT,            1, NAN},
                         {0,  0, 0, INF_ROOTS,          NAN, NAN},
                         {0,  3, 1,  ONE_ROOT, -0.3333333334, NAN},
                         {0,  0, 3,  NO_ROOTS,          NAN, NAN},
                         {1,  3, 2,    SQUARE,           -1,  -2}};


void unit_test(){
    for (int i = 0; i < 6; i++){
        double a = paramet[i].a, b = paramet[i].b, c = paramet[i].c;

        double x1 = NAN, x2 = NAN;
        char count_roots = 0;
        count_roots = solve_square (a, b, c, &x1, &x2);
        check_equality (x1, x2, count_roots, paramet[i].x1, paramet[i].x2, paramet[i].count_roots);
    }

    return;
}

bool check_equality (double cur_x1, double cur_x2, char cur_count_roots, double ans_x1, double ans_x2, char ans_count_roots){
    if (cur_count_roots != ans_count_roots){
        printf ("FAILED: Waiting ");
        print_result (cur_count_roots);

        printf ("Received ");
        print_result (ans_count_roots);

        return false;
    }

    switch (cur_count_roots){
        case NO_ROOTS:
            printf ("OK not roots\n");
            return true;

        case INF_ROOTS:
            printf ("OK inf roots\n");
            return true;

        case SQUARE:
            if (is_zero (cur_x1))
                cur_x1 = fix_zero (cur_x1);

            if (is_zero (cur_x2))
                cur_x2 = fix_zero (cur_x2);

            if (is_zero (cur_x1-ans_x1) && is_zero (cur_x2-ans_x2)){
                printf ("OK two roots\nx1 = %.6lf\nx2 = %.6lf\n", cur_x1, cur_x2);
                return true;
            }
            else{
                printf ("WRONG\ncur_x1 = %.6lf cur_x2 = %.6lf\n", cur_x1, cur_x2);
                printf ("ans_x1 = %.6lf ans_x2 = %.6lf\n", ans_x1, ans_x2);
                return false;
            }

        case ONE_ROOT:
            if (is_zero (cur_x1))
                cur_x1 = fix_zero (cur_x1);

            if (is_zero (cur_x1-ans_x1)){
                printf ("OK one root\nx = %.6lf\n", cur_x1);
                return true;
            }
            else{
                printf ("WRONG\ncur_x = %.6lf\n", cur_x1);
                printf ("ans_x = %.6lf\n", ans_x1);
                return false;
            }

        case ANOTHER: [[fallthrough]]
        default:
            printf ("ERROR\n");
            return false;
    }
}

void print_result (int count_roots){
    switch (count_roots){
        case NO_ROOTS:
            printf ("not roots\n");
            break;

        case INF_ROOTS:
            printf ("inf roots\n");
            break;

        case SQUARE:
            printf ("two roots\n");
            break;

        case ONE_ROOT:
            printf ("one roots\n");
            break;

        case ANOTHER: [[fallthrough]]
        default:
            printf ("ERROR\n");
            break;
    }
}

