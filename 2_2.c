#include<stdio.h>
#include <stdlib.h>
#include<math.h>

/**
* @brief считывает и проверяет ввод переменной типа double
* @return Возвращает считанное значение
*/
double getNumber();

/**
*\brief функция выполняет вычисление при x < 2
*\param x - число, вводимое пользователем
*\return возвращает значение функции
**/
double getEquation1(double x, double const a);

/**
*\brief функция выполняет вычисление при x >= 2
*\param x - число, вводимое пользователем
*\return возвращает значение функции
**/
double getEquation2(double x, double const a);

double RamifiedProcess(double const x, double const a);
double x = 0.0;

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает правильно, иначе 1
*/
int main()
{
	printf_s("Enter x: ");
	double x = getNumber();
	const double a = 2.3;
	printf_s("Value is %lf\n", RamifiedProcess(x, a));
}
double getNumber()
{
	double x;
	if (scanf_s(" %lf", &x) == 1 && x > 0)
	{
		return x;
	}
	printf_s("Wrong value");
	abort();
}
double RamifiedProcess(double const x, double const a)
{
	if (x < 2)
		return getEquation1(x, a);
	else if (x >= 2)
		return getEquation2(x, a);
}

double getEquation1(double x, double const a)
{
	return 1.5 * pow(cos(x), 2);
}
double getEquation2(double x, double const a)
{
	return pow ((x-2),2)+6;
}
