#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//��ջ�������vs2012 fflush(stdin)  
//stdin�Ǳ�׼����
//vs2017������rewind(stdin)��ձ�׼���뻺����
int main()
{
  int i,ret;
	while (rewind(stdin),(ret=scanf("%d", &i))!=EOF)
	{
	  printf("i=%d\n", i);
	}
   return 0;
}
