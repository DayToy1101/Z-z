#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0;
	printf("请输入一个数：");
	scanf("%d", &n);
	int tmp = n;
	int num = 0;
	int i = 0;
	for (i = 0; i < 16;i++)
	{
		num = tmp % 2;
		printf("%d", num);
		tmp = tmp >> 2;
	}
	printf("\n");
	tmp = n;
	for (i = 0; i < 16; i++)
	{
		tmp = tmp >> 1;
		num = tmp % 2;
		printf("%d", num);
	}
	printf("\n");
	return 0;
}