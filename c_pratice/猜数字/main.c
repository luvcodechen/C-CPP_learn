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
		printf("请猜测：");
		scanf("%d", &guess);
		
		 if (guess > ret) {
			printf("猜大了，若要重新进入或者退出游戏，请输入404并按照提示操作\n");
		 }
		 else if (guess < ret) {
			printf("猜小了，若要重新进入或者退出游戏，请输入404并按照提示操作\n");
		 }
		 
		 else if (guess == ret){
			printf("恭喜猜对了！\n");
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
		printf("请输入您的选择:\n");
		scanf("%d", &tap);
		
		if (tap == 1) {
			game();
			
		}
		else if (tap == 0)
		{
			printf("退出成功");

			break;
		}
		else {
			printf("输入有误，请再次输入\n");
		}
	/*	switch (tap) {
		case 1:
			game();
			break;
		case 0:

			printf("退出成功\n");
			break;
		default:
			printf("输入有误，请再次输入\n");
			break;
		}*/


	} while (tap||!tap);


	return 0;
}