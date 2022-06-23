#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
	
typedef int ElemType;
//动态申请一维数组
typedef struct {
	ElemType* elem;
	int length;
}Arr;


//初始化一维数组，并确定元素个数
void InitArr(Arr* arr, int n)
{
	int i = 0;
	arr->length = n+1;//0号元素为哨兵
	arr->elem = (ElemType*)calloc(arr->length, sizeof(ElemType));
	if (NULL == arr->elem)
	{
		return;//申请内存失败。返回
	}
	for (i = 0; i < arr->length; i++)
	{
		arr->elem[i] = rand() % 100 + 1;//随机生成1-100的数字
	}
}

//打印数组
void PrintArr(Arr arr)
{
	for (int i = 1; i < arr.length; i++) {//此处从i=1开始是因为0号元素为哨兵
		printf("%-3d", arr.elem[i]);
	}
	printf("\n");
}

//直接插入排序
void InsertSort(ElemType A[], int n)//传入首地址相当与数组名可以用一个数组名接收
{
	int i, j;
	for (i = 2;i <= n;i++)
	{
		if (A[i] <A[i - 1])
		{
			A[0] = A[i];//设置哨兵
			for (j=i-1;A[j]>A[0];j--)
			{
				A[j + 1] = A[j];//后移
			}
			A[j + 1] = A[0];//最后找到位置将哨兵内存储的值取出来
		}
		
	}
}
//折半插入排序
void binaryinsertsort(ElemType A[],int n)
{
	int i = 0, j = 0, high = 0, low= 0, mid = 0;
	for (i = 2; i <= n; i++)
	{
		A[0] = A[i];
		low = 1;
		high = i - 1;
		while (low <= high)//折半查找要插入的位置
		{
			mid = (low + high) / 2;
			if (A[mid] > A[0])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i-1; j > high; j--)
		{
			A[j + 1] = A[j];//后移
		}
		A[high + 1] = A[0];
	}
}
int main()
{
	Arr arr;
	srand((unsigned)time(NULL));
	InitArr(&arr, 10);
	PrintArr(arr);
	//InsertSort(arr.elem,10);
	binaryinsertsort(arr.elem,10);
	PrintArr(arr);
	return 0;
}