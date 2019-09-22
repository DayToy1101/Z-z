#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int num = 0;
    int a, b, c, d, e, f;
	for (num = 0; num <= 999999; num++)
	{
		int count = 0;
		int i = num;
		while (i)
		{
			count++;
			i = i / 10;
		}
		a = num % 10;
		b = (num / 10) % 10;
		c = (num / 100) % 10;
		d = (num / 1000) % 10;
		e = (num / 10000) % 10;
		f = num / 100000;
		if ((pow((double)a, (double)count) + pow((double)b, (double)count) + pow((double)c, (double)count) + pow((double)d, (double)count) + pow((double)e, (double)count) + pow((double)f, (double)count)) == num)
		{
			printf("%d\n", num);
		}
	}
	return 0;
}