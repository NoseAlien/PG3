#include <stdio.h>

unsigned int RecursiveHourlyWage(unsigned int hour)
{
	if (hour <= 1)
	{
		return 100 * hour;
	}

	int wage = 0;

	return (wage + ((RecursiveHourlyWage(hour - 1) * 2 - 50)));
}

unsigned int RecursiveWage(unsigned int hour)
{
	int ret = 0;
	for (int i = 0; i <= hour; i++)
	{
		ret += RecursiveHourlyWage(i);
	}

	return ret;
}

int main()
{
	const int hour = 8;

	printf("��ʒ��� : %d\n", 1072 * hour);
	printf("�ċA���� : %d\n", RecursiveWage(hour));
	return 0;
}