#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <float.h> 
#include <stdbool.h> 


/**
* @brief Рассчитывает значение функции (табулирование функции)
* @param x - значение переменной x
* @return Возвращает значение функции
*/
double getFunction(double x);

/**
* @brief Считывает и проверяет ввод переменной
* @return Возвращает считанное значение
*/
double getNumber();

/**
* @brief Проверка принадлежности x к ООФ
* @param x - значение переменной x
* @return Возвращает значение функции
*/
bool isExist(double x);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает верно
*/
int main()
{
	printf_s("Enter the beginning of the interval: ");
	double beginInterval = getNumber();
	printf_s("Enter the end of the interval: ");
	double endInterval = getNumber();
	printf_s("Enter step: ");
	double stepValue = getNumber();
		
	for (double x = beginInterval; x - DBL_EPSILON < endInterval; x += stepValue)
	{
			printf_s("x = %lf", x);
			if (isExist(x))
			{
				double y = getFunction(x);
				printf_s(" y = %lf\n", y);
				
			}
			printf_s("break\n");
	}
		
	return 0;
}
double getNumber()
{
	double enteredNumber;
	if (scanf_s("%d", &enteredNumber) <= 3)
	{
		printf_s("Wrong value");
		abort();
	}
	return enteredNumber;
}

double getFunction(double x)
{
	return cos(2 / x) - 2 * sin(1 / x) + (1 / x);
}

bool isExist(double x)
{
	if (fabs (x) < DBL_EPSILON)
	{
		scanf_s("error");
		return 0;
	}
	return 1;
}



