#ifndef _GENERALS_H_
#define _GENERALS_H_

const char RESET[]  =     "\033[0m";
const char RED[]    =  "\033[1;31m";
const char GREEN[]  =  "\033[1;32m";
const char YELLOW[] =  "\033[1;33m";

#define is_error(condition) {                                           \
    if (!(condition))                                                   \
        printf ("ERROR in %s in line %d in file %s in function %s\n",   \
                #condition, __LINE__, __FILE__, __PRETTY_FUNCTION__);   \
}

const long double Eps = 1e-10; ///< Global constant equal to \f$\ 10^{-9}\f$

/** \brief Comparison of double variables
    \version 1.0.0
    \param [in] num1 input double parameter
    \param [in] num2 input double parameter
    \return False - number is not equal, true - number is equal
*/
bool equality_double (double num1, double num2);

/** \brief Comparing a number to zero
    \version 1.0.0
    \param [in] n input parameter
    \return False - number is not zero, true - number is zero
*/
bool is_zero (double num);

/** \brief Ñorrect zero value
    \version 1.0.0
    \param [in] n input parameter
    \note If the value is zero the program must not return -0.00
    \return returns zero if the number is zero, otherwise returns the number itself
*/
double fix_zero (double num);

/** \brief Paints a line
    \version 1.0.0
    \param [in] Colour you want to paint
    \param [in] Line to be colored
*/
void print_colour (const char colour[], const char str[]);

#endif
