#include <stdio.h>

int main()
{
  int i = 5;
  float j = i / 2;//j�������2
  float k = (float)i / 2;//k�������2.5
  printf("%f\n%f\n", j,k);
  printf("j=%f,k=%f", j, k);
}