#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//原理对机试很重要
//缓冲区为空的时候，scanf才会卡主（阻塞）
int main()
{
  int i;
  float f;
  char c;
  scanf("%d", &i);
  printf("i=%d\n", i);
  /*canf("%c", &c);
  printf("c=%c\n", c);*/
  scanf("%f", &f);
  printf("f=%f\n", f);
}