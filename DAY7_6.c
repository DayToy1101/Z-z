#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//�ǵݹ�
int JiCheng(int n)
{
	int result = 1;
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int main()
{
	int num = 0;
	printf("Input a number: ");
	scanf("%d", &num);
	int ret = JiCheng(num);
	printf("%d�Ľ׳���%d\n", num, ret);
	return 0;
}


#if 0
//�ݹ�
int JiCheng(int n)
{
	while (n)
	{
		return n*JiCheng(n - 1);
	}
	return 1;
}

int main()
{
	int num = 0;
	printf("Input a number: ");
	scanf("%d", &num);
	int ret = JiCheng(num);
	printf("%d�Ľ׳���%d\n", num, ret);
	return 0;
}
#endif