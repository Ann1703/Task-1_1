#define EXIT_SUCCESS /*implementation defined*/
#define EXIT_FAILURE /*implementation defined*/

#include <stdio.h>
/**
* @breaf Расчёт работы электрического тока
* @param voltage значение напряжения в вольтах
* @param current_strenght значения силы тока в амперах
* @param work_current значение работы электрического тока
* @return Вывод полученного результата
*/
double get_result(double voltage, double  current_strenght);

/** @breaf  точка входа в программу
	@return EXIT_FAILURE если неверный ввод
	@return EXIT_SUCCESS если ввод верный
*/
int main()
{
	double voltage = 0.0;
	double  current_strenght = 0.0;
	double work_current = 0.0;
	printf_s("% s", "Voltage=");
	
	if (scanf_s("%d", &voltage) != 1 && scanf_s("%lf", &current_strenght) != 1)
	{
		printf_s("%s", "Wrong value");
		return EXIT_FAILURE;
	}
	printf_s("\n% s", "Current_strenght=");
	if (scanf_s("%lf", &current_strenght) != 1)
	{
		printf_s("%s", "Wrong value");
		return EXIT_FAILURE;
	}
	printf_s("voltage = %d\n", voltage);
	printf_s("current_strenght = %lf\n", current_strenght);
	work_current = get_result(voltage, current_strenght);
	printf_s("\nwork_current=%d", work_current);
	return EXIT_SUCCESS;
}
double get_result(double voltage, double current_strenght)
{
	const int timeMin = 20;
	int toSec = 60;
	return  voltage * current_strenght * timeMin * toSec;
}
