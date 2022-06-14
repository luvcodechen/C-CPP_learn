#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//关系运算符和逻辑运算符
int main()
{
  int a;
  scanf("%d", &a);
  if (2 < a &&a< 10)//同时判断要用逻辑运算符
  {
	printf("a is right\n");
  }
  else
  {

	printf("a is wrong");
  }

  //判断两个浮点数是否相等，要用下面的方法（复试）
  float f=234.56;
  if (f - 234.56 > -0.0001 && f - 234.56 < 0.0001)
	printf("f is equal to 234.56");
  else
	printf("f is  not equal to 234.56");
  return 0;
}