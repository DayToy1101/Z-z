#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Swap(int *pa, int *pb)
{
	int temp = 0;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
int main()
{
	int a = 32;
	int b = 98;
	Swap(&a, &b);
	printf("%d,%d\n", a, b);
	return 0;
}