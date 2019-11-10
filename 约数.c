#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Yue(int i, int j)
{
	int temp = 0;
	if (i < j)
		Yue(j, i);
	else if (j == 0)
		return i;
	else
	{
		temp = i;
		i = j;
		j = temp%i;
		Yue(i, j);
	}
	return i;
}
int main()
{
	int a = 0;
	int b = 0;
	int n = 0;
	printf("请输入两个数：\n");
	scanf("%d%d", &a, &b);
	n = Yue(a, b);
	printf("%d\n", n);
	return 0;
}