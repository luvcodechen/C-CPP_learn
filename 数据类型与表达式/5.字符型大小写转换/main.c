#include <stdio.h>

int main()
{
  char c = 'a'; //现在是小写字母a，要变为大写字母A
  c = c - 32;
  printf("%c\n", c);//以字符形式来输出c
  char d = 'B';
  d = d + 32;
  printf("%c\n", d);
}