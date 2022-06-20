#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1加到一百，和大于两千终止循环
int main()
{
  int i, total;
  for (i = 1, total = 0; i <= 100; i++)//for里面只能有两个分号，后不能加分号
  {
	if (total > 2000)
	{
	  break;//当求和大于2000，终止循环
	}
	total = total + i;
  }
  printf("total=%d\ni=%d\n", total,i);
}