char count_solves (double a, double b, double c, double *x1, double *x2, char *T);
char type (double a, double b, double c);
double discriminant (double a, double b, double c);
char square_solve (double a, double b, double c, double *x1, double *x2);
char line_solve (double a, double b, double *x);/** \brief Cравнение числа с нулем
/** \brief Сравнение числа с нулем
    \version 1.0.0
    \param n входное число
    \return false - число не равно нулю, true - число равно нулю
    \code
    bool is_zero (double n){
        return (n == 0.0) || (fabs(n) < EPS);
    }
    \endcode
*/
bool is_zero (double n);

/** \brief Считывание входных параметров
    \version 1.0.0
    \param a, b, c входные параметры
    \return 0 - были введены некоректные данные, 1 - данные введеные коректно
    \code
    int read_arguments (double *a, double *b, double *c){ //считывание значений
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

void write_result (char T, double x1, double x2);

