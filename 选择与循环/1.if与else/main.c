#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
  int i;
  while (scanf("%d", &i) != EOF)
  {
	if (i % 2 == 0)
	{
	  printf("%d为偶数\n",i);
	}
	else
	{
	  printf("%d不是偶数\n",i);

	}
  }
}