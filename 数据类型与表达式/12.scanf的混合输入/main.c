#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//一个scanf读多种类型的数据
//混合输入时每次在%c前面加一个空格
int main()
{
  int i,ret;
  char c;
  float f;
  ret=scanf("%d %c%f", &i, &c, &f);
  printf("i=%d,c=%c,f=%.2f\n", i, c, f);
  
  int a=64;
  printf("%c", a);
  return 0;
}