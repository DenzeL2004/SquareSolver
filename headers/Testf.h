#ifndef _TESTF_H_
#define _TESTF_H_

/**
    \struct Parameters_equation
    \brief Represents of second degree equation
*/
typedef struct Parameters_equation {
    double a, b, c;         ///< parametors equation
    int count_roots;        ///< number of roots equation
    double x1, x2;          ///< roots equation
} Parameters;

/**
    \brief Testing
    \version 1.0.0
    \note The function tests pre-prepared tests
*/
void unit_test();

/**
    \brief Solution of the original equation
    \version 1.0.0
    \note Function compares true and current roots
    \param [in] cur_x1 first root found by the program
    \param [in] cur_x1 second root found by the program
    \param [in] cur_count_root number of roots found by the program
    \param [in] ans_param struct Parameters_equation with correct root values
    \param [in] test_number number of current test
    \return True - original and calculated roots are equal, False - another way
*/
bool check_equality (double cur_x1, double cur_x2, char cur_count_roots, Parameters ans_param, int test_number);

/**
    \brief Conclusion of the verdict
    \version 1.0.0
    \param [in] count_root number of roots found by the program
*/
void print_result (const char colour[], int count_roots);

#endif
