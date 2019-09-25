#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int ret = 0;
	unsigned int sum = 0;
	int n = 0;
	int i = 0;
	printf("Input a number:");
	scanf("%d", &n);
	for (i = 0; i < 32; i++)
	{
		ret = n % 2;
		sum = sum + ret * (int)pow((double)2, (double)(31 - i));
		n = n >> 1;
	}
	printf("%u\n", sum);
	return 0;
}
	