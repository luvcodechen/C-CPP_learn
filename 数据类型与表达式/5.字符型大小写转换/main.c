#include <stdio.h>

int main()
{
  char c = 'a'; //������Сд��ĸa��Ҫ��Ϊ��д��ĸA
  c = c - 32;
  printf("%c\n", c);//���ַ���ʽ�����c
  char d = 'B';
  d = d + 32;
  printf("%c\n", d);
}