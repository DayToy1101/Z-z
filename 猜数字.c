#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int num = 28;
	int n;
	printf("请输入一个数字: ");
	scanf("%d", &n);
	int count = 5;
	while (count)
	{
		if (n < num)
		{
			printf("猜小了，请重新猜！\n");
			count--;
			printf("你还有%d次机会\n", count);
			scanf("%d", &n);
		}
		else if (n > num)
		{
			printf("猜大了，请重新猜！\n");
			count--;
			printf("你还有%d次机会\n", count);
			scanf("%d", &n);
		}
		else
		{
			printf("恭喜你，答对了！\n");
			break;
		}
	}
	return 0;
	
}