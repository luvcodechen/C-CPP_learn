#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//printf ���������ʽ	
int main()
{
  int i; char c; float f;
  scanf("%d %c%f", &i, &c, &f);
  printf("%5d,%c,%4.2f", i, c, f);
  return 0;
}