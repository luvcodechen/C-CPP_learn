#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//��ϵ��������߼������
int main()
{
  int a;
  scanf("%d", &a);
  if (2 < a &&a< 10)//ͬʱ�ж�Ҫ���߼������
  {
	printf("a is right\n");
  }
  else
  {

	printf("a is wrong");
  }

  //�ж������������Ƿ���ȣ�Ҫ������ķ��������ԣ�
  float f=234.56;
  if (f - 234.56 > -0.0001 && f - 234.56 < 0.0001)
	printf("f is equal to 234.56");
  else
	printf("f is  not equal to 234.56");
  return 0;
}