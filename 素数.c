#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int IsPrime(int a)
{
	int i = 0;
	for (i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int num;
	printf("请输入一个数：");
	scanf("%d", &num);
	int m = IsPrime(num);
	printf("%d\n", m);
	return 0;
}