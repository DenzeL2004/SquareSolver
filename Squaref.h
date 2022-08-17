/** \brief Solution of the original equation
    \version 1.0.0
    \note The function returns one of the enum state's values
    \param a, b, c input parameters of equation
    \param x1, x2 roots of equation
    \param T type of equation
    \return Number of solutions to the original equation
    \code
    char count_solves (double a, double b, double c, double *x1, double *x2, char *T){
        assert (!isnan(a));
        assert (!isnan(b));
        assert (!isnan(c));

        *T = type (a, b, c);
        switch (*T){
            case INF_ROOTS:
                return -1;

            case SQUARE:
                return square_solve (a, b, c, x1, x2);

            case ONE_ROOT:
                return line_solve (b, c, x1);

            case NO_ROOTS:
                return 0;

            default:
                return ANOTHER;
        }
    }
    \endcode
*/
char count_solves (double a, double b, double c, double *x1, double *x2, char *T);

/** \brief Determines the type of equation
    \version 1.0.0
    \note The function returns one of the enum state's values
    \param a, b, c input parameters of equation
    \return Type of equation
    \code
    char type (double a, double b, double c){
        assert (!isnan(a));
        assert (!isnan(b));
        assert (!isnan(c));

        if (is_zero(a))
            if (is_zero(b))
                if (is_zero(c))
                    return INF_ROOTS;
                else
                    return NO_ROOTS;
            else
                return ONE_ROOT;
        else
            return SQUARE;

        return ANOTHER;
    }
    \endcode
*/
char type (double a, double b, double c);

/** \brief Finding the discriminant of second degree equation
    \version 1.0.0
    \param a, b, c input parameters of equation
    \return Value of discriminant
    \code
    double discriminant (double a, double b, double c){ //поиск дескрименанта
        assert (!isnan(a));
        assert (!isnan(b));
        assert (!isnan(c));

        return b*b - 4*a*c;
    }
    \endcode
*/
double discriminant (double a, double b, double c);

/** \brief Solution of a second degree equation
    \version 1.0.0
    \param a, b, c input parameters of equation
    \param x1, x2 roots of equation
    \return Number of roots
    \code
    char square_solve (double a, double b, double c, double *x1, double *x2){  // Решение квдратного уравнения
        assert (!isnan(a));
        assert (!isnan(b));
        assert (!isnan(c));

        double D = discriminant (a, b, c);

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
    \code
    char line_solve (double a, double b, double *x){
        assert (!isnan(a));
        assert (!isnan(b));

        *x = -b/a;

        return 1;
    }
    \endcode
*/
char line_solve (double a, double b, double *x);

/** \brief Comparing a number to zero
    \version 1.0.0
    \param n input parameter
    \return False - number is not zero, true - number is zero
    \code
    bool is_zero (double n){
        return (n == 0.0) || (fabs(n) < EPS);
    }
    \endcode
*/
bool is_zero (double n);

/** \brief Reading input parameters
    \version 1.0.0
    \param a, b, c input parameters of equation
    \return 0 - data entered incorrectly, 1 - data entered correctly
    \code
    int read_arguments (double *a, double *b, double *c){
        assert (a != NULL);
        assert (b != NULL);
        assert (c != NULL);

        if (scanf ("%lf%lf%lf", a, b, c) != 3){
            printf ("Неверный ввод значений\n");
            return 0;
        }

        return 1;
    }
    \endcode
*/
int read_arguments (double *a, double *b, double *c);

/** \brief Output of the number of roots and their values
    \version 1.0.0
    \param count_roots - number of roots of the equation
    \param x1, x2 roots of equation
    \code
    void write_result (char count_roots, double x1, double x2){
        if (count_roots == INF_ROOTS){
            printf ("Бесконечное множество решений\n");
            return;
        }

        if (count_roots == NO_ROOTS){
            printf ("Решений нет\n");
            return;
        }

        if (count_roots == ONE_ROOT){
            printf ("Уравнение имеет ровно одно решение\n");

            if (is_zero(x1))
                x1 = -x1;

            printf ("x = %.6lf\n", x1);
            return;
        }

        if (count_roots == SQUARE){
            printf ("Уравнение имеет два различных решения\n");
            printf ("x1 = %.6lf\nx2 = %.6lf\n", x1, x2);
            return;
        }

        printf ("ERROR\n");
        return;
    }
    \endcode
*/
void write_result (char T, double x1, double x2);

