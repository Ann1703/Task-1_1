#include <locale.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <stdio.h>

/**
* @brief Функция для вычисления рекуррентного члена ряда.
* @param x Параметр функции, аппроксимируемой рядом.
* @param n Индекс члена ряда.
* @return Значение рекуррентного члена.
*/
double GetRecurrent(int x, double n);

/**
* @brief Функция для вычисления суммы ряда.
* @param x Показатель степени.
* @return Результат 3-го значения в степени x.
*/
double GetSeriesSum(int x, double e);

/**
* @brief Функция для вычисления значения функции.
* @param x - аргумент функции.
* @return Значение функции.
*/
double GetFunction(int x);

/**
* @brief Функция проверки ввода шага на правильность.
* @param step - шаг функции.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
*/
void CheckStep(double step);

/**
* @brief Функция проверки шага на правильность.
* @param message - сообщение пользователю.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Возвращает значение в случае успеха.
*/
double GetValue(const char* message);

/**
* @brief Функция проверки отрезка на существование.
* @param beginning_interval - начало отрезка.
* @param end_interval - конец
отрезка.
*/
void CheckSegment(const double beginning_interval, const double end_interval);

/**
* @brief Функция расчёта первого элемента последовательности.
* @param x - аргумент функции.
* @return Возвращает значение первого элемента последовательности.
*/
double GetFirstElement(int x);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	const double e = pow(30, -5);
	const double beginning_interval = GetValue("Enter the beginning of the interval: ");
	const double end_interval = GetValue("Enter the end of the interval: ");
	CheckSegment(beginning_interval, end_interval);
	const double step = GetValue("Enter the function step: ");
	CheckStep(step);
	double x = beginning_interval;
	while (x - end_interval <= DBL_EPSILON)
	{
		printf_s("%10.2lf | %25.15lf | %.15lf \n", x, GetFunction(x), GetSeriesSum(x, e));
		x += step;
	}
	return 0;
}

double GetSeriesSum(int x, double e)
{
	double current = 1;
	double sum = current;
	int n = 1;

	while (fabs(current)  > e)
	{
		current *= GetRecurrent(x,n);
		sum += current;
		n++;
	}
	return sum;
}

double GetRecurrent(int x, double n)
{
	return pow(x, 4) / ((4 *n  + 1) * (4 * n + 5));
}

double GetFunction(int x)
{
	return 0.25*log((1+x)/(1-x))+0.5*atan(x);
}

void CheckStep(double step)
{
	if (step < DBL_EPSILON)
	{
		puts("The value was entered incorrectly!");
		abort();
	}
}

void CheckSegment(const double beginning_interval, const double end_interval)
{
	if (beginning_interval - end_interval > DBL_EPSILON)
	{
		puts("The interval is entered incorrectly!");
		abort();
	}
}

double  GetValue(const char* message)
{
	double value;
	printf_s("%s", message);
	int result = scanf_s("%lf", &value);

	if (result != 1)
	{
		errno = EIO;
		perror("Input error");
		abort();
	}
	return value;
}

double GetFirstElement(int x)
{
	double current = pow(x, 5) / 5;
	return current;
}