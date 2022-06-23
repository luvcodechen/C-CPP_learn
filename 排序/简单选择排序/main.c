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

//��ʼ˳���
void InitSqlist(Sqlist *L,int n) 
{
	int i = 0;
	L->length = n;
	for (i = 0; i < L->length; i++)
	{
		L->data[i] = rand() % 100 + 1;
	}
}
//��ӡ˳���
void PrintList(Sqlist L)
{
	int i = 0;
	for (i = 0; i < L.length; i++) {
		printf("%-3d", L.data[i]);
	}
	printf("\n");
}

//�����������������򾭳��õ����������ú���
void swap(ElemType* a, ElemType* b)
{
	ElemType temp = *a;
	*a = *b;
	*b = temp;
}

//��ѡ������
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