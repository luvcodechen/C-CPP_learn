#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
  char c;
  while (scanf("%c", &c) != EOF)
  {
	if (c != '\n')
	  {
		printf("%c", c - 32);
	  }
	  else
	  {
		printf("\n");
	  }
  }
}