#include <stdio.h>
#include <stdlib.h>
#include <math.h>
enum Variants
{
	PERIMETR = 1,
	SQUARE = 2,
	DIAGONAL_LENGHT=3
};

/**
* @brief считывает и проверяет ввод переменной типа double
* @return Возвращает считанное значение
*/
double getNumber();

/**
* @brief проверяет возможность построения прямоугольника
* @param A -первая сторона прямоугольника
* @param B -вторая сторона прямоугольника
* @param С -третья сторона прямоугольника
* @param D -четвертая сторона прямоугольника
* @return Возвращает 1, если прямоугольника существует, иначе 0
*/
int isCorrect(double A, double B, double C);

/**
* @brief рассчитывает периметр прямоугольника
* @param A -первая сторона прямоугольника
* @param B -вторая сторона прямоугольника
* @param С -третья сторона прямоугольника
* @param D -четвертая сторона прямоугольника
* @return Возвращает периметр прямоугольника
*/
double getPerimetr(double A, double B);

/**
* @brief рассчитывает площадь прямоугольника
* @param A -первая сторона прямоугольника
* @param B -вторая сторона прямоугольника
* @param С -третья сторона прямоугольника
* @param D -четвертая сторона прямоугольника
* @return Возвращает площадь прямоугольника
*/
double getSquare(double A, double B);

/**
* @brief рассчитывает длину диагонали прямоугольника
* @param A -первая сторона прямоугольника
* @param B -вторая сторона прямоугольника
* @param С -третья сторона прямоугольника
* @param D -четвертая сторона прямоугольника
* @return Возвращает площадь прямоугольника
*/
double getDiagonalLength(double A, double B);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает правильно, иначе 1
*/
int main()
{
	printf_s("Enter A: ");
	double sideA = getNumber();
	printf_s("Enter B: ");
	double sideB = getNumber();
	printf_s("Enter C: ");
	double sideC = getNumber();
	printf_s("Enter D: ");
	double sideD = getNumber();
	if (isCorrect(sideA, sideB, sideC,sideD))
	{
		printf_s("Enter %d to get perimetr, %d to get square, %d or to get diagonal_length  : ", PERIMETR, SQUARE,DIAGONAL_LENGHT);
		int selectVariants = getNumberInt();
		if (selectVariants == PERIMETR)
		{
			printf_s("Perimetr is %lf", getPerimetr(sideA, sideB));
		}
		else if (selectVariants == SQUARE)
		{
			printf_s("Square is %lf", getSquare(sideA, sideB));
		}
		else if (selectVariants == DIAGONAL_LENGHT)
		{
			printf_s("DiagonalLength is %lf", getDiagonalLength(sideA, sideB));
		}
	}
	else
	{
		printf_s("It can't be rectangle");
	}

	return 0;
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

int getNumberInt()
{
	int x;
	if (scanf_s(" %d", &x) == 1 && (x == PERIMETR || x == SQUARE || x== DIAGONAL_LENGHT))
	{
		return x;
	}
	printf_s("Wrong value");
	abort();
}

int isCorrect(double A, double B, double C,double D)
{
	if ( A = C && B==D )
		return 1;
	return 0;
}

double getPerimetr(double A, double B)
{
	return 2*A + 2*B ;
}

double getSquare(double A, double B)
{
		return A * B;
}

double getDiagonalLength(double A, double B)
{
	return sqrt(pow(A, 2) + pow(B, 2));
}