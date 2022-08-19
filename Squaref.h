#ifndef _SQUARE_H_
#define _SQUARE_H_

const long double EPS = 1e-9; ///< Global constant equal to \f$\ 10^{-9}\f$

/**
    \enum state
    \brief Represents the number of roots of the equation
*/
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
    \param a input parameters of equation
    \param b input parameters of equatio
    \param c input parameters of equatio
    \param x1 roots of equation
    \param x2 roots of equation
    \param T type of equation
    \return Number of solutions to the original equation
*/
char solve (double a, double b, double c, double *x1, double *x2, char *T);

/** \brief Determines the type of equation
    \version 1.0.0
    \note The function returns one of the enum state's values
    \param a input parameters of equation
    \param b input parameters of equation
    \param c input parameters of equation
    \return Type of equation
*/
char get_type (double a, double b, double c);

/** \brief Finding the discriminant of second degree equation
    \version 1.0.0
    \param a input parameters of equation
    \param b input parameters of equation
    \param c input parameters of equation
    \return Value of discriminant
*/
double discriminant (double a, double b, double c);

/** \brief Solution of a second degree equation
    \version 1.0.0
    \param a input parameters of equation
    \param b input parameters of equation
    \param c input parameters of equation
    \param x1 roots of equation
    \param x2 roots of equation
    \return Number of roots
    \note if D = 0, x1 is assigned the value of the root, x2 does not change
    \note if D < 0, x1 and x2 do not change
    \note if D > 0, x1 and x2 are assigned the value of the root
    \code
        if (is_zero(D)){
            *x1 = -b / (2*a);
            return ONE_ROOT;
        }

        if(D < 0.0)
            return NO_ROOT;

        D = sqrt(D);
        a *= 2;

        if (D > 0.0){
            *x1 = (-b + D) / a;
            *x2 = (-b - D) / a;
            return SQUARE;
        }
    \endcode
*/
char square_solve (double a, double b, double c, double *x1, double *x2);

/** \brief Solution of a linear equation
    \note The function finds the root when the parameter a is zero
    \version 1.0.0
    \param a input parameters of equation
    \param b input parameters of equation
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

/** \brief Ñorrect zero value
    \version 1.0.0
    \param n input parameter
    \note if the value is zero the program must not return -0.00
    \return returns zero if the number is zero, otherwise returns the number itself
*/
double fix_zero (double n);

/** \brief Reading input parameters
    \version 1.0.0
    \param a input parameters of equation
    \param b input parameters of equation
    \param c input parameters of equation
    \return False - data entered incorrectly, True - data entered correctly
*/
bool read_arguments (double *a, double *b, double *c);

/** \brief Output of the number of roots and their values
    \version 1.1.0
    \param count_roots - number of roots of the equation
    \param x1 roots of equation
    \param x2 roots of equation
*/
void write_result (char T, double x1, double x2);

#endif
