#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Reversr_String(char *str)
{
	if (*str != '\0')
	{
		Reversr_String(str + 1);
	}
	printf("%c", *str);
}

int main()
{
	char *ch = "abcdefghjk";
	printf(" %s\n", ch);
	Reversr_String(ch);
	return 0;
}