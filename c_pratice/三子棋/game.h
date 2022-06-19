#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//º¯ÊýµÄÉùÃ÷
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerStep(char boaed[ROW][COL], int row, int  col);
void ComputerStep(char board[ROW][COL], int row, int  col);
char IsWin(char board[ROW][COL],int row,int col);