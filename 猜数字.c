#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int num = 28;
	int n;
	printf("������һ������: ");
	scanf("%d", &n);
	int count = 5;
	while (count)
	{
		if (n < num)
		{
			printf("��С�ˣ������²£�\n");
			count--;
			printf("�㻹��%d�λ���\n", count);
			scanf("%d", &n);
		}
		else if (n > num)
		{
			printf("�´��ˣ������²£�\n");
			count--;
			printf("�㻹��%d�λ���\n", count);
			scanf("%d", &n);
		}
		else
		{
			printf("��ϲ�㣬����ˣ�\n");
			break;
		}
	}
	return 0;
	
}