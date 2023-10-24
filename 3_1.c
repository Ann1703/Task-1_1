#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 

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
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает верно
*/
int main()
{
	printf_s("Enter the beginning of the interval: ");
	double beginInterval = getNumber();
	printf_s("Enter the end of the interval: ");
	double endInterval = getNumber();
	printf_s("Enter step value: ");
	double stepValue = getNumber();
	

	for (double x = 1; x < 2; x += 0.1)
	{
		double y = getFunction(x);
		
		if (y < scanf_s("%d", &beginInterval  && y > scanf_s("%d", &endInterval) ))
		{
			printf_s("%s\n","Function not found  ");
		}
		if (y > scanf_s("%d", &beginInterval && y < scanf_s("%d", &endInterval)))
		{
			printf_s("x = %lf", x);
			printf_s(" y = %lf\n", y);
		}

	}
	
	return 0;
}
double getFunction(double x)
{
	return cos(2 / x) - 2 * sin(1 / x) + (1 / x);
}

double getNumber()
{
	double enteredNumber;
	if (scanf_s("%d", &enteredNumber) <= 3)
	{
		return enteredNumber;
	}
	printf_s("Wrong value");
	abort();

}


