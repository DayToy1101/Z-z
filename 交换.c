#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Search(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d,%d\n",a, b);
}
int main()
{
	int i = 0;
	int j = 0;
	printf("请输入两个数字：\n");
	scanf("%d%d", &i, &j);
	Search(i, j);
	return 0;
}