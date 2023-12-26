#include <math.h>
/**
* @breaf ������������ �������� ���������� �
* @param x �������� ��������� x
* @param y �������� ��������� y
* @param z �������� ��������� z
* @return ���������� �������� ���������� �
*/
double get_A(const double x, const double y, const double z);

/**
*@breaf ������������ �������� ���������� b
* @param x �������� ��������� x
* @param y �������� ��������� y
* @param z �������� ��������� z
* @return ���������� �������� ���������� �
*/
double get_B(const double x, const double y, const double z);

int main()
{
    double a, b;
    const double x = -2.9;
    const double y = 15.5;
    const double z = 1.5;
    a = get_A(x, y, z);
    b = get_B(x, y, z);
    printf_s("a=%lf\n", a);
    printf_s("b=%lf\n", b);
    return 0;
}

double get_A(const double x, const double y, const double z)
{
    return  sqrt(pow(x, 2) + y) - pow(y, 2) * pow(sin((x + z) / x), 3);
}

double get_B(const double x, const double y, const double z)
{
    return pow(cos(pow(x, 3)), 2) - x / (sqrt(pow(z, 2) + pow(y, 2)));
}
