#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1-100֮���������
int main()
{
  int i, total;
  for (i = 1, total = 0; i <= 100; i++)//for����ֻ���������ֺţ����ܼӷֺ�
  {
	  if(i%2==0)
		{
		continue;//��ǰ��������ѭ��
		}
		total = total + i;
  }
  printf("total=%d\n", total);
}