#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fac(int n)
{
	if (n > 1)
	{
		return n*Fac(n - 1);
	}
	return n;
}
int main()
{
	int n = 0;
	printf("输入一个数： ");
	scanf("%d", &n);
	int num = Fac(n);
	printf("%d\n", num);
	return 0;
}