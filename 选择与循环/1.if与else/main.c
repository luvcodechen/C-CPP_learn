#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
  int i;
  while (scanf("%d", &i) != EOF)
  {
	if (i % 2 == 0)
	{
	  printf("%dΪż��\n",i);
	}
	else
	{
	  printf("%d����ż��\n",i);

	}
  }
}