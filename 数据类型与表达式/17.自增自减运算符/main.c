#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//i����i=i+1,�Ƚ��������Ǻ�++
//++iֱ�Ӱ������ȼ��������㼴�ɡ�	
int main()
{
  int i=-2;
  int j;
  j =++ i> -1; //������i=i+1,��ʱ���ʽΪj=-1>-1...
  j = i++ > -2;//��ʱ���Ϊj=i>-1;i++;...
  printf("j=%d,i=%d\n", j,i);
  printf("i���ֽ���=%d\n", sizeof(i));

}