#define EXIT_SUCCESS /*implementation defined*/
#define EXIT_FAILURE /*implementation defined*/

#include <stdio.h>
/**
* @breaf ������ ������ �������������� ����
* @param voltage �������� ���������� � �������
* @param current_strenght �������� ���� ���� � �������
* @param work_current �������� ������ �������������� ����
* @return ����� ����������� ����������
*/
double get_result(int voltage, double  current_strenght);
/** @breaf  ����� ����� � ���������
	@return EXIT_FAILURE ���� �������� ����
	@return EXIT_SUCCESS ���� ���� ������
*/

int main()
{
	int voltage = 0;
	double  current_strenght = 0.0;
	int work_current = 0;
		
	printf_s("% s", "Voltage=");
	
	if (scanf_s("%d", &voltage) != 1 && scanf_s("%lf", &current_strenght) != 1)
	{
		printf_s("%s", "Wrong value");
		return EXIT_FAILURE;
			abort();

	}
	printf_s("\n% s", "Current_strenght=");
	if (scanf_s("%lf", &current_strenght) != 1)
	{
		printf_s("%s", "Wrong value");
		return EXIT_FAILURE;
		abort();

	}
	printf_s("voltage = %d\n", voltage);
	printf_s("current_strenght = %lf\n", current_strenght);
	work_current = get_result(voltage, current_strenght);
	printf_s("\nwork_current=%d", work_current);
	return EXIT_SUCCESS;
}
double get_result(int voltage, double current_strenght)
{

	const int timeMin = 20;
	int toSec = 60;
	return  voltage * current_strenght * timeMin * toSec;
}
