
#define EXIT_SUCCESS /*implementation defined*/
#define EXIT_FAILURE /*implementation defined*/

#include <stdio.h>

/**
* @breaf ������� ��������� �������� �� ����� � ����� 
* @param weight �������� � �������
* @param ounce �������� ��������� ounce
* @return �����������  ���������� � ������
*/
double get_ounce(double weight);
/** @breaf  ����� ����� � ���������
	@return EXIT_FAILURE ���� �������� ����
	@return EXIT_SUCCESS ���� ���� ������ 
*/
  int main()
{
	double weight =0;
	double result;
    result= get_ounce(weight);
	printf_s("% s", "Weight=");
	if (scanf_s("%lf", &weight) != 1)
	{
		printf_s("%s","Wrong value");
		return EXIT_FAILURE
		abort();

	}
	printf_s("weight = %lf", weight);
	printf_s("\nresult=%lf", result);
	return EXIT_SUCCESS;
  }
  double get_ounce(double weight)
	{
		
		const double ounce = 28.3;
		return  weight * ounce;
    }
	