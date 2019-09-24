#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//非递归
int Fib(int n)
{
	int ret = 1;
	int a = 1;
	int b = 0;
	while (n > 2)
	{
		n--;
		b = a;
		a = ret;
		ret = a + b;
	}
	return ret;
}

int main()
{
	int n = 0;
	printf("请输入要求第几个斐波那契数：");
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d\n", ret);
	return 0;
}

#if 0
//递归
int Fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}

int main()
{
	int n = 0;
	printf("请输入要求第几个斐波那契数：");
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d\n", ret);
	return 0;
}
#endif