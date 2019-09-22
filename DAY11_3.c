#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define N  20
int main()
{
	int i = 0;
	int j = 0;
	int a[N][N];
	int n = 0;
	printf("请输入要打印的行数：");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
	
		a[i][0] = 1;
		a[i][i] = 1;
		for (j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("\t%d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}