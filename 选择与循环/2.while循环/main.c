#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
  int i = 1;
  int total = 0;//�洢���յĺ�
  while (i <= 100)
  {
	total = total + i;
	i++;
  }
  printf("total=%d\n", total);

}