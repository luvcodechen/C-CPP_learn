#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1�ӵ�һ�٣��ʹ�����ǧ��ֹѭ��
int main()
{
  int i, total;
  for (i = 1, total = 0; i <= 100; i++)//for����ֻ���������ֺţ����ܼӷֺ�
  {
	if (total > 2000)
	{
	  break;//����ʹ���2000����ֹѭ��
	}
	total = total + i;
  }
  printf("total=%d\ni=%d\n", total,i);
}