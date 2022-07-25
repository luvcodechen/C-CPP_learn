#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 10
//插入排序
void creatarr(int* a)
{
	int i = 0;
	for (i = 0; i < MAX; i++)
		a[i] = rand() % 50 + 1;
}
void Print(int* a)
{
	for (int i = 0; i < MAX; i++)
		printf("%3d", a[i]);
	printf("\n");
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//插入排序,升序排序   
void Insertsort(int *a)
{
	int i, j;
	for (i = 1; i < MAX; i++)//第一个默认有序，从下标为1开始，也就是第二个元素
	{
		if (a[i] < a[i - 1])//如果当前元素比上一个小
		{
			int temp = a[i];//暂存当前元素
			for (j = i; j >0 && a[j - 1] > temp; j--)//把前面的比当前大的都后移
				a[j] = a[j-1];
			a[j] = temp;//找到位置
		}
	}
}
//折半插入排序，相较于直接插入减少了比较次数，移动次数不变，排序速度没有实质提升
void BinaryInsertionSort(int *a)
{
	int i, j, low, high, mid;
	for (i = 0; i < MAX; i++)
	{
		if (a[i] < a[i - 1])
		{
			low = 0;
			high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (a[mid] > a[i])
					high = mid - 1;
				else
					low = mid + 1;
			}
			int temp = a[i];
			for (j = i; j > low; j--)
				a[j] = a[j - 1];
			a[j] = temp;
		}
	}
}
int main()
{
	srand(time(NULL));
	int arr[MAX];
	creatarr(arr);
	Print(arr);
	//Insertsort(arr);
	BinaryInsertionSort(arr);
	Print(arr);

	return 0;
}
