#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
  int a=1*2+3/3+10%3;
  printf("%d\n", a);
  scanf("%d", &a);
  while (a != 0)//��a������0�Ϳ��Խ���ѭ��
  {
	printf("%d", a % 10);
	a = a / 10;

  }
  return 0;
}