#define _CRT_SECURE_NO_WARNINGS 1
#include"match.h"
void Menu()
{
	printf("*********************\n");
	printf("********0.exit*******\n");
	printf("********1.play*******\n");
	printf("*********************\n");
}
void Game()
{

	int ret = 0;

	char board[ROW][COL] = { 0 };

	InitBoard(board, ROW, COL);

	ShowBoard(board, ROW, COL);

	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		ShowBoard(board, ROW, COL);//打印棋盘
		ret = IsWin(board, ROW, COL);//每次都要判断是否赢了比赛 
		if (ret != 1)//结束游戏
		{
			break;
		}
		ComputerMove(board, ROW, COL);//电脑下棋
		ShowBoard(board, ROW, COL); //打印棋盘
		ret = IsWin(board, ROW, COL);//每次都要判断是否赢了比赛
		if (ret != 1)//结束游戏
		{
			break;
		}
	}
	if (ret == 'X')//玩家获胜，游戏结束
	{
		printf("玩家获胜\n");
	}
	if (ret == 'Y')//电脑获胜，游戏结束
	{
		printf("电脑获胜\n");
	}
	if (ret == 0)//平局，游戏结束
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("请输入你的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}
