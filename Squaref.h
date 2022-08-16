char count_solves (double a, double b, double c, double *x1, double *x2, char *T);
char type (double a, double b, double c);
double discriminant (double a, double b, double c);
char square_solve (double a, double b, double c, double *x1, double *x2);
char line_solve (double a, double b, double *x);/** \brief C�������� ����� � �����
/** \brief ��������� ����� � �����
    \version 1.0.0
    \param n ������� �����
    \return false - ����� �� ����� ����, true - ����� ����� ����
    \code
    bool is_zero (double n){
        return (n == 0.0) || (fabs(n) < EPS);
    }
    \endcode
*/
bool is_zero (double n);

/** \brief ���������� ������� ����������
    \version 1.0.0
    \param a, b, c ������� ���������
    \return 0 - ���� ������� ����������� ������, 1 - ������ �������� ��������
    \code
    int read_arguments (double *a, double *b, double *c){ //���������� ��������
        assert (a != NULL);
        assert (b != NULL);
        assert (c != NULL);

        if (scanf ("%lf%lf%lf", a, b, c) != 3){
            printf ("�������� ���� ��������\n");
            return 0;
        }

        return 1;
    }
    \endcode
*/
int read_arguments (double *a, double *b, double *c);

void write_result (char T, double x1, double x2);

