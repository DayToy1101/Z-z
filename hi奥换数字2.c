#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Search(int a, int b)
{
	int t = 0;
	if (a != b)
	{
		t = a;
		a = b;
		b = t;
	}
	printf("%d,%d\n", a, b);
}
int main()
{
	int a = 0;
	int b = 0;
	int t = 0;
	printf("请输入两个数字：\n");
	scanf("%d%d", &a, &b);
	Search(a, b);
	return 0;
}