#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
  int i;
  scanf("%d", &i);
  if (i % 4 == 0&&i%100!=0 || i % 400 == 0)
	{
	  printf("yes\n");
	}	
  else
	{ 
	  printf("no\n");
    }
//Ñ§Ï°Âß¼­·Ç
  int a, b=65;
  a = !b;
  printf("a=%d\n", a);
  a = !!b;
  printf("a=%d", a);
	
}