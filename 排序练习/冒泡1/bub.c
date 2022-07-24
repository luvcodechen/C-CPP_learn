#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 10
//冒泡排序
void creatarr(int *a)
{
	int i = 0;
	for (i = 0; i < MAX; i++)
		a[i] = rand() % 30 + 1;
}
void Print(int *a)
{
	for (int i = 0; i < MAX; i++)
		printf("%3d", a[i]);
	printf("\n");
}
void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void bubblesort(int *a)//升序，从前往后
{
	int i, j;
	for (i = MAX-1; i>0 ; i--)
	{
		bool flag = false;
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				flag = true;
			}
		}
		if (flag == false)//没有发生交换，已经有序
			return;
	}
}
int main()
{
	srand(time(NULL));
	int arr[MAX];
	creatarr(arr);
	Print(arr);
	bubblesort(arr);
	Print(arr);
	return 0;
}