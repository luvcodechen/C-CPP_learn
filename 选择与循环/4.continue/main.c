#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1-100之间奇数求和
int main()
{
  int i, total;
  for (i = 1, total = 0; i <= 100; i++)//for里面只能有两个分号，后不能加分号
  {
	  if(i%2==0)
		{
		continue;//提前结束本轮循环
		}
		total = total + i;
  }
  printf("total=%d\n", total);
}