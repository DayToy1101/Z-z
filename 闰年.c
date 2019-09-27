#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Year(int a)
{
	if ((a % 4 == 0) && (a % 400 != 0) || (a % 100 == 0))
	{
		printf("%d\n", a);
	}
}
int main()
{
	int year;
	for (year = 1000; year <= 2019; year++)
	{
		Year(year);
	}
	return 0;
}