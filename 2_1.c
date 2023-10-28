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
* @brief ��������� � ��������� ���� ���������� ���� double
* @return ���������� ��������� ��������
*/
double getNumber();

/**
* @brief ��������� ����������� ���������� ��������������
* @param A -������ ������� ��������������
* @param B -������ ������� ��������������
* @param � -������ ������� ��������������
* @param D -��������� ������� ��������������
* @return ���������� 1, ���� �������������� ����������, ����� 0
*/
int isCorrect(double A, double B, double C);

/**
* @brief ������������ �������� ��������������
* @param A -������ ������� ��������������
* @param B -������ ������� ��������������
* @param � -������ ������� ��������������
* @param D -��������� ������� ��������������
* @return ���������� �������� ��������������
*/
double getPerimetr(double A, double B);

/**
* @brief ������������ ������� ��������������
* @param A -������ ������� ��������������
* @param B -������ ������� ��������������
* @param � -������ ������� ��������������
* @param D -��������� ������� ��������������
* @return ���������� ������� ��������������
*/
double getSquare(double A, double B);

/**
* @brief ������������ ����� ��������� ��������������
* @param A -������ ������� ��������������
* @param B -������ ������� ��������������
* @param � -������ ������� ��������������
* @param D -��������� ������� ��������������
* @return ���������� ������� ��������������
*/
double getDiagonalLength(double A, double B);

/**
* @brief ����� ����� � ���������
* @return ���������� 0, ���� ��������� �������� ���������, ����� 1
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