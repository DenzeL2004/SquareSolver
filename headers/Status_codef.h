#ifndef _STATUS_CODE_H_
#define _STATUS_CODE_H_

enum errors {
    FINITE_ERR = -1,
    ZERO_ERR = -2,
    POINTER_ERR = -3,
    CORRECT = 0
};

char check_finite (double n);
char check_pointer (double *p);
char check_zero (double n);

#endif
