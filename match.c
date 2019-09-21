#define _CRT_SECURE_NO_WARNINGS 1
#include"match.h"
void InitBoard(char board[][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
		//memset(board[ROW][COL], ' ', ROW * COL * sizeof(char));
}
void ShowBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");

	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入1-3号下标：");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= 3 && y > 0 && y <= 3)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = 'x';
				break;
			}
			else
			{
				printf("该位置已有棋子！\n");
			}
		}
		else
		{
			printf("输入的坐标不合法,请重新输入！\n");
		}
	}
}
int IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//横向判断
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}

		//纵向判断
		else if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}

		//左对角线判断
		else if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
		{
			return board[1][1];
		}

		//右对角线判断
		else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
		{
			return board[1][1];
		}

		//判断棋盘是否放满
		else if (IsFull(board, row, col == 1))
		{
			return 0;
		}
	}
	return 1;

}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走！\n");
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')

				return 1;
		}
	}
	return 0;
}