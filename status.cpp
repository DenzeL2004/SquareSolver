#include <stdio.h>
#include <math.h>
#include "headers\Squaref.h"
#include "headers\Status_codef.h"

char check_finite (double n){
    if (!isfinite (n)){
        fprintf (stderr, "Variable value is INF/NAN\n"
        "ERROR STATUS = %d", FINITE_ERR);

        return FINITE_ERR;
    }
    return CORRECT;
}

char check_pointer (double *p){
    if (p == NULL){
        fprintf (stderr, "Pointer is NULL \n"
        "ERROR STATUS = %d", POINTER_ERR);

        return POINTER_ERR;

    }
    return CORRECT;
}

char check_zero (double n){
    if (is_zero (n)){
         fprintf (stderr, "Variable value is INF/NAN\n"
         "ERROR STATUS = %d", ZERO_ERR);

         return ZERO_ERR;
    }
    return CORRECT;
}
