#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[][COLS],int rows,int cols,char set )
{
	int i = 0;
	int j = 0;
	for(i = 0;i < rows;i++)
	{
		for(j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void ShowBoard(char board[][COLS],int rows,int cols)
{
	int i = 0;
	int j = 0;
	printf("======================\n");
	for(i = 0;i < rows-1;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for(i = 1;i < rows-1;i++)
	{
		printf("%d ",i);
		for(j = 1;j < cols-1;j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	printf("======================\n");
}

void SetMine(char mine[][COLS],int row,int col)//9  9
{
	int count = MINENUM;
	int x = 0;
	int y = 0;
	while(count != 0)
	{
		x = rand()%row+1;//[0-9)  [1,10)
		y = rand()%col +1;
		if(mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


static int GetMine(char mine[][COLS],int x,int y)
{
	//'1' - '0'  = 1
	// 1 + '0' = '1'

	//return mine[x-1][y-1]-'0'+
	//mine[x-1][y]-'0'+
	//mine[x-1][y+1]-'0'+
	//mine[x][y+1]-'0'+
	//mine[x+1][y+1]-'0'+
	//mine[x+1][y]-'0'+
	//mine[x+1][y-1]-'0'+
	//mine[x][y-1]-'0';
		return mine[x-1][y-1]+
	mine[x-1][y]+
	mine[x-1][y+1]+
	mine[x][y+1]+
	mine[x+1][y+1]+
	mine[x+1][y]+
	mine[x+1][y-1]+
	mine[x][y-1]-  8 * '0';
}

void FindMine(char mineInfo[][COLS],char mine[][COLS],int row,int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	//                     < 81 - 10 = 71
	while( count  < row * col - MINENUM)
	{
		printf("请输入你的坐标：");
		scanf("%d%d",&x,&y);
		if(x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if(mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				break;
			}
			else
			{
				//1、找到旁边八个位置有几个雷   4
				int mineNum =  GetMine(mine,x,y);//  
				//2、将当前位置置为   '4'
				mineInfo[x][y] = mineNum+'0';
				//3、count++;
				count++;

				ShowBoard(mineInfo,ROWS,COLS);
			}
		}
		else
		{
			printf("坐标不合法\n");
		}
	}

	if(count  ==  row * col - MINENUM)
	{
		printf("扫雷成功\n");
	}
}
