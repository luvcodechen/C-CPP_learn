#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//清空缓冲区，vs2012 fflush(stdin)  
//stdin是标准输入
//vs2017及以上rewind(stdin)清空标准输入缓冲区
int main()
{
  int i,ret;
	while (rewind(stdin),(ret=scanf("%d", &i))!=EOF)
	{
	  printf("i=%d\n", i);
	}
   return 0;
}
