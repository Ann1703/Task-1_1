#include <stdio.h>
#include <stdlib.h>

/**
* @brief считывает и проверяет ввод переменной типа double
* @return Возвращает считанное значение
*/
double getValue();

/**
* @brief функция рассчитывает пройденный путь
* @param time - время движения по участку
* @param speed - скорость движения по участку
* @return возвращает значение функции
**/
double getWay(double time, double speed);

/**
* @brief функция считает половину суммарного пройденного пути
* @param t1 - время движения по первому участку
* @param v1 - скорость движения по первому участку
* @param t2 - время движения по второму участку
* @param v2 - скорость движения по второму участку
* @param t3 - время движения по третьему участку
* @param v3 - скорость движения по третьему участку
* @return возвращает значение функции
**/
double halfSumWay(double t1, double v1, double t2, double v2, double t3, double v3);

/**
* @brief функция считает время начала привала
* @param t1 - время движения по первому участку
* @param v1 - скорость движения по первому участку
* @param t2 - время движения по второму участку
* @param v2 - скорость движения по второму участку
* @param t3 - время движения по третьему участку
* @param v3 - скорость движения по третьему участку
* @return возвращает значение функции
**/
double getTimeStartRest(double t1, double v1, double t2, double v2, double t3, double v3);

/**
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена верно, иначе 1
*/
int main() {
    printf_s("Enter time 1\n");
    double t1 = getValue();
    printf_s("Enter speed 1\n");
    double v1 = getValue();
    printf_s("Enter time 2\n");
    double t2 = getValue();
    printf_s("Enter speed 2\n");
    double v2 = getValue(); 
    printf_s("Enter time 3\n");
    double t3 = getValue();
    printf_s("Enter speed 3\n");
    double v3 = getValue();
    printf_s("Value is %lf\n", getTimeStartRest(t1, v1, t2, v2, t3, v3));
}
double getValue() 
{
    double value;
    if (scanf_s(" %lf", &value) == 1 && value > 0)
    {
        return value;
    }
    printf_s("Wrong value");
    abort();
}
double getTimeStartRest(double t1,double v1, double t2, double v2,double t3,double v3)
{
    double halfWay = halfSumWay(t1, v1, t2, v2, t3, v3);
    if (getWay(t1, v1)>=halfWay)
    {
        return halfWay / v1;
    }
    else 
        if (getWay(t1, v1) + getWay(t2, v2) >= halfWay)
        {
            return (halfWay - getWay(t1, v1)) / v2 + t1;
        }
        else
        {
            return (halfWay - getWay(t1, v1) - getWay(t2, v2)) / v3 + t1 + t2;
        }
       
 }

double halfSumWay(double t1, double v1, double t2, double v2, double t3, double v3)
{
    return (t1 * v1 + t2 * v2 + t3 * v3)/2;
}

double getWay(double time, double speed)
{
    return time * speed;
}
