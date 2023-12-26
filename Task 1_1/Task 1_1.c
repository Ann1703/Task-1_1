﻿#include <stdio.h>
#include <math.h>
/**
* @breaf Рассчитывает значение переменной а
* @param x значение константы x
* @param y значение константы y
* @param z значение константы z
* @return возвращает значение переменной а
*/
double get_A(const double x, const double y, const double z);

/**
*@breaf Рассчитывает значение переменной b
* @param x значение константы x
* @param y значение константы y
* @param z значение константы z
* @return возвращает значение переменной а
*/
double get_B(const double x, const double y, const double z);

int main()
{
    double a, b;
    const double x = 2;
    const double y = 0.7;
    const double z = -1;
    a = get_A(x, y, z);
    b = get_B(x, y, z);
    printf("a=%lf", a);
    printf("b=%lf", b);
    return 0;
}

double get_A(const double x, const double y, const double z)
{
    return  cbrt(x * y * z + fabs(z * sin(y)));
}

double get_B(const double x, const double y, const double z)
{
    return   y * cos(x * z * sin(y)) + 3;
}
