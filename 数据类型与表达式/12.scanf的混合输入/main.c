#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//һ��scanf���������͵�����
//�������ʱÿ����%cǰ���һ���ո�
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