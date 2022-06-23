#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MaxSize 20
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;

}Sqlist;

//初始顺序表
void InitSqlist(Sqlist* L, int n)
{
	int i = 0;
	L->length = n;
	for (i = 0; i < L->length; i++)
	{
		L->data[i] = rand() % 200 + 1;
	}
}
//打印顺序表
void PrintList(Sqlist L)
{
	int i = 0;
	for (i = 0; i < L.length; i++) {
		printf("%-4d", L.data[i]);
	}
	printf("\n");
}

//交换两个数，因排序经常用到，所以设置函数
void swap(ElemType* a, ElemType* b)
{
	ElemType temp = *a;
	*a = *b;
	*b = temp;
}

//归并
void merge(ElemType A[],int low ,int mid ,int high)
{
	ElemType B[MaxSize];
	int i, j, k = 0;
	while (k <= high)
		B[k] = A[k++];
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
	{
		if (B[i] <= B[j])
			A[k] = B[i++];
		else
			A[k] = B[j++];
	}
	while (i<=mid)
		A[k++] = B[i++];
	while (j <= high)
		A[k++] = B[j++];

}

//归并排序
void mergesort(ElemType A[],int low,int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergesort(A,low,mid);
		mergesort(A,mid+1,high);
		merge(A,low,mid,high);
	}
}
int main()
{
	Sqlist L;
	srand((unsigned)time(NULL));
	InitSqlist(&L,19);
	PrintList(L);
	mergesort(L.data,0,L.length-1);
	PrintList(L);
	return 0;

}