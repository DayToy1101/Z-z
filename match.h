#pragma once
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
//��ʼ������
void InitBoard(char board[][COL], int row, int col);
//��ӡ����
void ShowBoard(char board[][COL], int row, int col);
//����ƶ�
void PlayerMove(char board[][ROW], int row, int col);
//�Ƿ�Ӯ����ʤ�� 
int IsWin(char board[][ROW],int row,int col); 
//�����ƶ� 
void ComputerMove(char board[][ROW],int row,int col);
//�ж������Ƿ����
int IsFull(char board[ROW][COL], int row, int col);
