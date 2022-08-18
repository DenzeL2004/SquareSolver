#ifndef _SQUARE_H_
#define _SQUARE_H_

extern const long double EPS; ///< Global constant equal to \f$\ 10^{-9}\f$

enum state {
    INF_ROOTS = -1, ///< The equation has an infinite number of solutions
    NO_ROOTS = 0, ///< The equation has no solutions
    ONE_ROOT = 1, ///< The equation has a maximum of one solutions
    SQUARE = 2, ///< The equation has a maximum of two solutions
    ANOTHER = 3 ///< Another case
};

/** \brief Solution of the original equation
    \version 1.0.0
    \note The function returns one of the enum state's values
    \param a, b, c input parameters of equation
    \param x1, x2 roots of equation
    \param T type of equation
    \return Number of solutions to the original equation
*/
char count_solves (double a, double b, double c, double *x1, double *x2, char *T);

/** \brief Determines the type of equation
    \version 1.0.0
    \note The function returns one of the enum state's values
    \param a, b, c input parameters of equation
    \return Type of equation
*/
char type (double a, double b, double c);

/** \brief Finding the discriminant of second degree equation
    \version 1.0.0
    \param a, b, c input parameters of equation
    \return Value of discriminant
*/
double discriminant (double a, double b, double c);

/** \brief Solution of a second degree equation
    \version 1.0.0
    \param a, b, c input parameters of equation
    \param x1, x2 roots of equation
    \return Number of roots
    \note if D = 0, x1 is assigned the value of the root, x2 does not change
    \note if D < 0, x1 and x2 do not change
    \note if D > 0, x1 and x2 are assigned the value of the root
    \code
        if (is_zero (D)){
            *x1 = -b/(2*a);
            return 1;
        }

        if(D < 0.0)
            return 0;

        if (D > 0.0){
            *x1 = (-b + sqrt(D))/(2*a);
            *x2 = (-b - sqrt(D))/(2*a);
            return 2;
        }

    \endcode
*/
char square_solve (double a, double b, double c, double *x1, double *x2);

/** \brief Solution of a linear equation
    \note The function finds the root when the parameter a is zero
    \version 1.0.0
    \param a, b input parameters of equation
    \param x root of equation
    \return Number of roots
*/
char line_solve (double a, double b, double *x);

/** \brief Comparing a number to zero
    \version 1.0.0
    \param n input parameter
    \return False - number is not zero, true - number is zero
*/
bool is_zero (double n);

/** \brief Reading input parameters
    \version 1.0.0
    \param a, b, c input parameters of equation
    \return 0 - data entered incorrectly, 1 - data entered correctly
*/
int read_arguments (double *a, double *b, double *c);

/** \brief Output of the number of roots and their values
    \version 1.0.0
    \param count_roots - number of roots of the equation
    \param x1, x2 roots of equation
*/
void write_result (char T, double x1, double x2);

#endif
