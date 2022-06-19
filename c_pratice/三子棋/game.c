#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col) 
{

	int i = 0;
	int j = 0;
	for (i=0;i<row;i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}		
	}												
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
				if(j<col-1)//最后一列不输出分割
					printf("|");
		}
		printf("\n");
		if (i < row - 1)//最后一行不输出分割
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//最后一列不输出分割
					printf("|");

			}
			printf("\n");
		}
	}
}



void ComputerStep(char board[ROW][COL], int row, int  col) 
{
	printf("电脑:\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}	
	}			
}
void PlayerStep(char board[ROW][COL], int row, int  col)
{
	int x = 0, y = 0;
	printf("玩家：\n");
	while (1)
	{
		printf("请输入要走的坐标：");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已满，请再次输入：\n");
			}								
		}
		else
		{
			printf("输入有误，请再次输入\n");
		}
	}
        
}
char IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{

			if (board[i][j] == ' ')
			{
				return  0;
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[0][i];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//状态
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	return 'C';


}