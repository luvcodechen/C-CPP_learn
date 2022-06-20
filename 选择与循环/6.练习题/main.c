#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//判断一个整型数是否为对称数，如12321为对称数
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