#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�ж�һ���������Ƿ�Ϊ�Գ�������12321Ϊ�Գ���
int main()
{
  int a, b, c;
  while (scanf("%d", &a) != EOF)
  {
	b = 0;
	c = a;
	while (a)
	{
	  b = b * 10 + a % 10;
	  a = a / 10;
	}
	/*printf("%d", b);*/
  
	  if (c==b)
	  {
		printf("yes\n");
	  }
	  else
	  {
		printf("no\n");
	  }
	}
  return 0;
}