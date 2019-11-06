#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void ShowNum(int n)
{
	if (n > 9)
	{
		ShowNum(n / 10);
	}
	printf("%d ", n % 10);
}

int main()
{
	int n = 0;
	printf("Input a number: ");
	scanf("%d", &n);
	ShowNum(n);
	return 0;
}