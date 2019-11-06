#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	double avg = 0;
	int a = 0;
	int b = 0;
	printf("请输入两个数：");
	scanf("%d%d", &a, &b);
	if (a == b)
	{
		avg = a;
	}
	else if (a > b)
	{
		a = a - b;
		avg = (a >> 1) + b;
	}
	else
	{
		b = b - a;
		avg = (b >> 1) + a;
	}
	printf("%lf\n", avg);
	return 0;
}