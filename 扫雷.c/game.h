#pragma once                                                    //预防头文件重复引入
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINENUM 10 //初始10个雷

void SetMine(char Mine[ROWS][COLS], int row, int col);     //设置雷
void c_mine(char Mine[ROWS][COLS], int row, int col);             //初始化
void Print(char Mine[ROWS][COLS], int row, int col);              //打印
void c_show(char Mine[ROWS][COLS], int row, int col);             //初始化
int FindMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col);     //找雷
