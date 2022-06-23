#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
	
typedef int ElemType;
//��̬����һά����
typedef struct {
	ElemType* elem;
	int length;
}Arr;


//��ʼ��һά���飬��ȷ��Ԫ�ظ���
void InitArr(Arr* arr, int n)
{
	int i = 0;
	arr->length = n+1;//0��Ԫ��Ϊ�ڱ�
	arr->elem = (ElemType*)calloc(arr->length, sizeof(ElemType));
	if (NULL == arr->elem)
	{
		return;//�����ڴ�ʧ�ܡ�����
	}
	for (i = 0; i < arr->length; i++)
	{
		arr->elem[i] = rand() % 100 + 1;//�������1-100������
	}
}

//��ӡ����
void PrintArr(Arr arr)
{
	for (int i = 1; i < arr.length; i++) {//�˴���i=1��ʼ����Ϊ0��Ԫ��Ϊ�ڱ�
		printf("%-3d", arr.elem[i]);
	}
	printf("\n");
}

//ֱ�Ӳ�������
void InsertSort(ElemType A[], int n)//�����׵�ַ�൱��������������һ������������
{
	int i, j;
	for (i = 2;i <= n;i++)
	{
		if (A[i] <A[i - 1])
		{
			A[0] = A[i];//�����ڱ�
			for (j=i-1;A[j]>A[0];j--)
			{
				A[j + 1] = A[j];//����
			}
			A[j + 1] = A[0];//����ҵ�λ�ý��ڱ��ڴ洢��ֵȡ����
		}
		
	}
}
//�۰��������
void binaryinsertsort(ElemType A[],int n)
{
	int i = 0, j = 0, high = 0, low= 0, mid = 0;
	for (i = 2; i <= n; i++)
	{
		A[0] = A[i];
		low = 1;
		high = i - 1;
		while (low <= high)//�۰����Ҫ�����λ��
		{
			mid = (low + high) / 2;
			if (A[mid] > A[0])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i-1; j > high; j--)
		{
			A[j + 1] = A[j];//����
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