#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//i代表i=i+1,比较难理解的是后++
//++i直接按照优先级进行运算即可。	
int main()
{
  int i=-2;
  int j;
  j =++ i> -1; //先运算i=i+1,此时表达式为j=-1>-1...
  j = i++ > -2;//此时拆分为j=i>-1;i++;...
  printf("j=%d,i=%d\n", j,i);
  printf("i的字节数=%d\n", sizeof(i));

}