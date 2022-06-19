#define _CRT_SECURE_NO_WARNINGS 


#include "game.h"
void menu() {
	printf("***************************\n");
	printf("******    1. play    ******\n");
	printf("******    0. exit    ******\n");
}

void game() {

	char board[ROW][COL];//��ά����
	InitBoard(board, ROW, COL);//��ʼ������--��ʼ���ո� 
	//��ӡһ������
	DisplayBoard(board,ROW,COL);
	char ret = 0;
	while (1)
	{
		//�����
		PlayerStep(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret= IsWin(board,ROW,COL);
		if (ret!='C')
			break;
		//������
		ComputerStep(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret!='C')
			break;
	}
	if (ret == '*')
	{
		printf("���ʤ��\n");		
	}
	else if(ret == '#')
	{
		printf("����ʤ��\n");		
	}
	else
	{
		printf("ƽ��.\n");
	}
	DisplayBoard(board, ROW, COL);
}
int main() {
	int input = 0;
	srand(time(0));
	do{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();			
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}	
	} while (input);
	return 0;
}