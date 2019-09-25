#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[10] = { 6, 3, 8, 6, 5, 4, 3, 6, 8, 4 };
	int len = sizeof(a) / sizeof(a[0]);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		a[0] = a[0] ^ a[i];
	}
	printf("%d\n", a[0]);
	return 0;
}