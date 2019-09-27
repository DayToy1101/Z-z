#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Init(int a[],int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		scanf("%d", &a[i]);
		printf("%3d", a[i]);
	}
	printf("\n");
}

void Empty(int a[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		a[i] = 0;
		printf("%3d", a[i]);
	}
	printf("\n");
}

void Reverse(int a[], int len)
{
	int i = 0;
	int temp = 0;
	for (i = 0; i < len / 2;i++)
	{
		temp = a[i];
		a[i] = a[len - 1 - i];
		a[len-1-i]= temp;
	}
	for (i = 0; i < len; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10];
	int i = 0;
	Init(arr,10);
	Reverse(arr, 10);
	Empty(arr, 10);
	return 0;
}