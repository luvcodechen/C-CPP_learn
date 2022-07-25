#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 10
//��������
void creatarr(int* a)
{
	int i = 0;
	for (i = 0; i < MAX; i++)
		a[i] = rand() % 30 + 1;
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
//�����㷨
int partition(int *a,int low,int high)
{
	int piovt = a[low];
	while (low < high)
	{

		while (low<high&&a[high] >= piovt)high--;
		a[low] = a[high];
		while (low<high&&a[low] <= piovt)low++;
		a[high] = a[low];
	}
	a[low] = piovt;
	return low;
}
//���ţ�����
void quicksort(int *a,int low,int high)
{
	if (low < high)
	{
		int piovtpos = partition(a, low, high);
		quicksort(a, low, piovtpos - 1);
		quicksort(a, piovtpos + 1, high);
	} 

}
int cmp_int(const void* _a, const void* _b)//������ʽ�̶�
{
	//int* a = (int*)_a;    //ǿ������ת��
	//int* b = (int*)_b;
	return (int*)_a - (int*)_b;
}
int main()
{
	srand(time(NULL));
	int arr[MAX];
	creatarr(arr);
	Print(arr);
	quicksort(arr,0,9);
	Print(arr);
	qsort(arr,10,sizeof(int), cmp_int);
	Print(arr);
	return 0;
}