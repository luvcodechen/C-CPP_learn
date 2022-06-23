#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define MaxSize 20
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}Sqlist;

//��ʼ˳���
void InitSqlist(Sqlist* L, int n)
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

//�����󶥶�
void HeadAdjust(Sqlist *L,int s,int len)
{
	int dad = s;
	int son = 2 * dad + 1;//�����±�
	while (son <= len){
		if (son+1<=len&&L->data[son+1]>L->data[son]){
			son++;
		}
		if (L->data[son] > L->data[dad]){
			swap(&L->data[son], &L->data[dad]);
			dad = son;
			son = dad * 2 + 1;
		}
		else
			break;
	}

}
//������
void HeapSort(Sqlist *L)
{
	int i = 0;
	for (i = L->length / 2-1; i >= 0; i--)//�����󶥶�
	{
		HeadAdjust(L,i,L->length-1);
	}
	swap(&L->data[0], &L->data[L->length-1]);
	for (i=L->length-2;i>1;i--)
	{
		HeadAdjust(L,0,i);//ȥ���Ѿ��ҵ������Ԫ�����µ����󶥶�
		swap(&L->data[0], &L->data[i]);//���Ѷ���¼�����һ����¼����
	}
}

int main()
{
	Sqlist L;
	srand((unsigned)time(NULL));
	InitSqlist(&L, 10);
	//int ar[]={12,15,30,21,5,56,91,26,33,52};
	//for (int i = 0; i < 10; i++) {
	//	L.data[i] = ar[i];
	//}
	//L.length = 10;
	PrintList(L);
	HeapSort(&L);
	PrintList(L);

	return 0;

}
