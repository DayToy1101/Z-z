#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>

int main()
{
	char ch[] = "student a am i";
	int len = strlen(ch);
	char tmp;
	int start = 0;
	int end = len - 1;
	int k = 0;
	int j = 0;
	int i = 0;
	while (start < end)
	{
		tmp = ch[end];
		ch[end] = ch[start];
		ch[start] = tmp;
		start++;
		end--;
	}
	for (i = 1; i <= len; i++)
	{
		if (ch[i] == ' ' || ch[i] == '\0')
		{
			for (k = i - 1; k >= j; k--)
			{
				printf("%c", ch[k]);
			}
			if (ch[i] != '\0')
			{
				printf(" ");
			}
			j = i;
		}
	}
	printf("\n");
	return 0;
}