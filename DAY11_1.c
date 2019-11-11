#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int A;
	int B;
	int C;
	int D;
	int E;
	for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				if (A != B&&A != C&&B != C)
				{
					for (D = 1; D <= 5; D++)
					{
						if (A != D&&B != D&&C != D)
						{
							E = 15 - A - B - C - D;
							if (A != E&&B != E&&C != E&&D != E)
							{
								if (((B == 2) + (A == 3)) == 1 && ((B == 2) + (E == 4)) == 1 && ((C == 1) + (D == 2)) == 1 && ((C == 5) + (D == 3)) == 1 && ((E == 4) + (A == 1)) == 1)
								{
									printf("A = %d\n", A);
									printf("B = %d\n", B);
									printf("C = %d\n", C);
									printf("D = %d\n", D);
									printf("E = %d\n", E);
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

#if 0
int main()
{
	int A, B, C, D, E;
	for (A = 1; A <= 5; A = A + 1)
		for (B = 1; B <= 5; B = B + 1)
			for (C = 1; C <= 5; C = C + 1)
				if (A != B && A != C && B != C)
					for (D = 1; D <= 5; D = D + 1)
						if (A != D && B != D && C != D)
						{
							E = 15 - A - B - C - D;
							if (A != E && B != E && C != E && D != E)
								if (((B == 3) + (C == 5)) == 1 && ((D == 2) + (E == 4)) == 1 && ((B == 1) + (E == 4)) == 1 &&
									((C == 1) + (B == 2)) == 1 && ((D == 2) + (A == 3)) == 1)
								{
									printf("A= %d\n", A);
									printf("B= %d\n", B);
									printf("C= %d\n", C);
									printf("D= %d\n", D);
									printf("E= %d\n", E);
								}
						}
}
#endif
