#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

//��̬����һά����
typedef struct  {
	ElemType* elem;
	int length;
}Arr;

//��ʼ��һά���飬��ȷ��Ԫ�ظ���
void InitArr(Arr *arr,int n)
{
	int i = 0;
	arr->length = n;
	arr->elem = (ElemType*)calloc(arr->length,sizeof(ElemType));
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
	for (int i = 0; i < arr.length; i++) {
		printf("%d ", arr.elem[i]);
	}
	printf("\n");
}

//�����������������򾭳��õ����������ú���
void swap(ElemType *a,ElemType *b)
{
	ElemType temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

//ð������
void Bubblesort(ElemType A[],int n)
{
	int i,j;
	bool flag=1;//�����жϣ�����ѭ������
	for (i = 0; i < n-1&&flag; i++)//��������
	{
		flag = false;
		for (j = n - 1;j > i; j--)//�ڲ���ƱȽϴ�СȻ�󽻻�����
		{
			if (A[j-1] > A[j])
			{
				swap(&A[j],&A[j-1]);
				flag = true;
			}
		}
	}

}
int Partition(ElemType a[], int left, int right)
{
	int i, j;//j������¼�ȷָ�ֵС�����ݵ�λ��
	for (i=j=left;i < right;i++)
	{
		if (a[i]<a[right])//�����ұߵ�����Ϊ�ָ�ֵ
		{
			swap(&a[i],&a[j]);//���±�iλ�õ�ֵС�ڷָ�ֵ���򽻻�ij�±��ֵ
			j++;
		}
	}
	swap(&a[j],&a[right]);

	return j;
}
//�������򣬵ݹ�ʵ�֣�����˼��
void QuickSort(ElemType A[],int low,int high)
{
	if (low < high)
	{
		int pivot = Partition(A,low,high);
		QuickSort(A,low,pivot-1);
		QuickSort(A,pivot+1,high);
	}
}
int main()
{
	Arr arr;
	srand((unsigned)time(NULL));
	InitArr(&arr,10);//��ʼ��һά���飬�������
	PrintArr(arr);
	Bubblesort(arr.elem,10);
	PrintArr(arr);
	QuickSort(arr.elem,0,9);
	PrintArr(arr);

	return 0;
}