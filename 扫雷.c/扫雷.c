#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Menu()
{
	printf("****************************\n");
	printf("*****欢迎来到扫雷小游戏*****\n");
	printf("***********1.paly***********\n");
	printf("***********0.exit***********\n");
	printf("****************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	c_mine(mine, ROWS, COLS);      //初始化雷区
	SetMine(mine, ROW, COL);       //放置雷
	c_show(show, ROWS, COLS);      //初始化show
	//Print(mine, ROW, COL);       //打印雷区
	Print(show, ROW, COL);
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		Menu();
		printf("请输入你的操作:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
