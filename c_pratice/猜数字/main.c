#define _CRT_SECURE_NO_WARNINGS 

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <string.h>


void menu() 
{
	printf("***************************\n");
	printf("****tap 1/0 to continue****\n");
	printf("******** 1:play game*******\n");
	printf("******** 0:exit game*******\n");
	printf("***************************\n");
}

game() {
	int ret = rand() % 100 + 1;
	int guess = 0;
	while (1)		
	{	
		printf("��²⣺");
		scanf("%d", &guess);
		
		 if (guess > ret) {
			printf("�´��ˣ���Ҫ���½�������˳���Ϸ��������404��������ʾ����\n");
		 }
		 else if (guess < ret) {
			printf("��С�ˣ���Ҫ���½�������˳���Ϸ��������404��������ʾ����\n");
		 }
		 
		 else if (guess == ret){
			printf("��ϲ�¶��ˣ�\n");
			break;
		 }
	} 
	
}
int main()
{

	
	int tap;
	srand(time(0));
	do
{
		menu();
		printf("����������ѡ��:\n");
		scanf("%d", &tap);
		
		if (tap == 1) {
			game();
			
		}
		else if (tap == 0)
		{
			printf("�˳��ɹ�");

			break;
		}
		else {
			printf("�����������ٴ�����\n");
		}
	/*	switch (tap) {
		case 1:
			game();
			break;
		case 0:

			printf("�˳��ɹ�\n");
			break;
		default:
			printf("�����������ٴ�����\n");
			break;
		}*/


	} while (tap||!tap);


	return 0;
}