#define _CRT_SECURE_NO_WARNINGS 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main() {
	char s[20] = { 0 };
	system("shutdown -s -t 100");
again :
	printf("��ĵ��Խ���100���ػ���������  ���Ǳ���  ��ֹ�˴ιػ�:\n");
	scanf("%s", s);
	if (strcmp(s, "���Ǳ���") == 0)
	{
		system("shutdown -a");
	}
	else {
		goto again;
	}
}