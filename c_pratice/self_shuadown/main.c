#define _CRT_SECURE_NO_WARNINGS 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main() {
	char s[20] = { 0 };
	system("shutdown -s -t 100");
again :
	printf("你的电脑将在100秒后关机，请输入  我是笨蛋  阻止此次关机:\n");
	scanf("%s", s);
	if (strcmp(s, "我是笨蛋") == 0)
	{
		system("shutdown -a");
	}
	else {
		goto again;
	}
}