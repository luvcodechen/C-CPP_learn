#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MaxSize 20
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
}Sqlist;

//初始顺序表
void InitSqlist(Sqlist *L,int n) 
{
	int i = 0;
	L->length = n;
	for (i = 0; i < L->length; i++)
	{
		L->data[i] = rand() % 100 + 1;
	}
}
//打印顺序表
void PrintList(Sqlist L)
{
	int i = 0;
	for (i = 0; i < L.length; i++) {
		printf("%-3d", L.data[i]);
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

//简单选择排序
void SelectSort(Sqlist *L)
{
	int i = 0,j = 0, min = 0;
	for (i = 0; i < L->length - 1; i++)
	{
		min = i;
		for (j = i + 1; j < L->length; j++)
		{
			if (L->data[min] > L->data[j])
				min = j;
		}
		if (min != i)
			swap(&L->data[i],&L->data[min]);
	}

}
int main()
{
	Sqlist L;
	srand((unsigned)time(NULL));
	InitSqlist(&L,10);
	PrintList(L);
	SelectSort(&L);
	PrintList(L);
	return 0;
}