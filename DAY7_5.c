#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//·ÇµÝ¹é
int Strlen(const char *s)
{
	int len = 0;
	do
	{
		s++;
		len += 1;
	} while (*s != '\0');
	return len;
}

int main()
{
	char *ch = "abcdefgh";
	int length = Strlen(ch);
	printf("%d\n", length);
	return 0;
}



#if 0
//µÝ¹é
int Strlen(const char *s)
{
	if (*s == '\0')
	{
		return 0;
	}
	return 1 + Strlen(s + 1);
}

int main()
{
	char *ch = "abcdefg";
	int length = Strlen(ch);
	printf("%d\n", length);
	return 0;
}
#endif