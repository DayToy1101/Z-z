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
		PlayerMove(board, ROW, COL);//�������
		ShowBoard(board, ROW, COL);//��ӡ����
		ret = IsWin(board, ROW, COL);//ÿ�ζ�Ҫ�ж��Ƿ�Ӯ�˱��� 
		if (ret != 1)//������Ϸ
		{
			break;
		}
		ComputerMove(board, ROW, COL);//��������
		ShowBoard(board, ROW, COL); //��ӡ����
		ret = IsWin(board, ROW, COL);//ÿ�ζ�Ҫ�ж��Ƿ�Ӯ�˱���
		if (ret != 1)//������Ϸ
		{
			break;
		}
	}
	if (ret == 'X')//��һ�ʤ����Ϸ����
	{
		printf("��һ�ʤ\n");
	}
	if (ret == 'Y')//���Ի�ʤ����Ϸ����
	{
		printf("���Ի�ʤ\n");
	}
	if (ret == 0)//ƽ�֣���Ϸ����
	{
		printf("ƽ��\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("��������Ĳ�����");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}
