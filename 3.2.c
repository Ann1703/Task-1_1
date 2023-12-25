#include <stdio.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <stdlib.h>

/**
* @brief Функция считывающая количество членов последовательности.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Количество членов последовательности.
*/
int GetCount();

/**
* @brief Функция расчитывающая сумму членов последовательности.
* @param count - количество членов последовательности.
* @return Сумма последовательности.
*/
double GetSum(int count);

/**
* @brief Функция расчитывающая рекурентный член последовательности.
* @param k - номер члена последовательности.
* @return Значение рекурентного члена последовательности.
*/
double GetRecurrent(int k);
/**
* @brief Функция ввода и проверки на правильность точности вычислений.
* @return Точность вычислений.
*/
double GetEpsilon();

/**
* @brief Функция вычисления суммы членов последовательности, не меньших epsilon.
* @param epsilon - точность вычислений.
* @return Сумма.
*/
double GetSecondSum(const double epsilon);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/


/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
	printf_s("%s", "Insert end of the segment: ");
	int count = GetCount();
	printf_s("Sum of %d sequence terms: %lf \n", count + 1, GetSum(count));
	printf_s("Insert calculation accuracy: ");
	const double epsilon = GetEpsilon();
	printf_s("The sum of the terms of the sequence not less than calculation accuracy: %lf", GetSecondSum(epsilon));
	return 0;

}

int GetCount()
{
	int count;
	int result = scanf_s("%d", &count);

	if (result != 1 || count < 1)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}
	return count;
}

double GetSum(int count)
{
	double current = -1;
	double sum = current;
	for (int k = 1; k < count; k++)
	{
		current *= GetRecurrent(k);
		sum += current;
	}
	return sum;
}

double GetRecurrent(int k)
{
	return ((-1.0) * pow((k + 1), 3)) / pow(k, 4);
}
	double GetEpsilon()
	{
		double epsilon;
		double result = scanf_s("%lf", &epsilon);
		if (result != 1 || epsilon < DBL_EPSILON)
		{
			errno = EIO;
			perror("Error");
			abort();
		}
		return epsilon;
	}

	double GetSecondSum(const double epsilon)
	{
		double current = 1;
		double sum = current;
		int k = 1;
		while (fabs(current) >= epsilon)
		{
			current *= GetRecurrent(k);
			sum += current;
			k++;
		}
		return sum;
	}

