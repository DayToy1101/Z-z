#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int count_one_bits(unsigned int value)
{
	int count = 0;
	int i = 0;
	int num = value;
	for (i = 0; i < 32; i++)
	{
		if ((num >> i) & 1 == 1)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int n = 0;
	printf("请输入一个数字：");
	scanf("%d", &n);
	int ret = count_one_bits(n);
	printf("%d里有%d个1\n", n, ret);
	return 0;
}

#if 0
int main()
{
	int n = 0;
	printf("请输入一个数字：");
	scanf("%d", &n);
	int count = 0;
	int i = 0;
	int num = n;
	for (i = 0; i < 32; i++)
	{
		if ((num >> i) & 1 == 1)
		{
			count++;
		}
	}
	printf("%d里有%d个1\n", n, count);
	return 0;
}
int main()
{
	int n = 0;
	printf("请输入一个数字：");
	scanf("%d", &n);
	int count = 0;
	int num = n;
	while (num != 0)
	{
		count++;
		num = num & (num - 1);
			
	}
	printf("%d里有%d个1\n", n, count);
	return 0;
}
#endif