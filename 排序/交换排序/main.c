#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;

//动态申请一维数组
typedef struct  {
	ElemType* elem;
	int length;
}Arr;

//初始化一维数组，并确定元素个数
void InitArr(Arr *arr,int n)
{
	int i = 0;
	arr->length = n;
	arr->elem = (ElemType*)calloc(arr->length,sizeof(ElemType));
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
	for (int i = 0; i < arr.length; i++) {
		printf("%d ", arr.elem[i]);
	}
	printf("\n");
}

//交换两个数，因排序经常用到，所以设置函数
void swap(ElemType *a,ElemType *b)
{
	ElemType temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

//冒泡排序
void Bubblesort(ElemType A[],int n)
{
	int i,j;
	bool flag=1;//增加判断，减少循环次数
	for (i = 0; i < n-1&&flag; i++)//控制有序
	{
		flag = false;
		for (j = n - 1;j > i; j--)//内层控制比较大小然后交换次序
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
	int i, j;//j用来记录比分割值小的数据的位置
	for (i=j=left;i < right;i++)
	{
		if (a[i]<a[right])//用最右边的数作为分割值
		{
			swap(&a[i],&a[j]);//当下标i位置的值小于分割值，则交换ij下标的值
			j++;
		}
	}
	swap(&a[j],&a[right]);

	return j;
}
//快速排序，递归实现，分治思想
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
	InitArr(&arr,10);//初始化一维数组，传入个数
	PrintArr(arr);
	Bubblesort(arr.elem,10);
	PrintArr(arr);
	QuickSort(arr.elem,0,9);
	PrintArr(arr);

	return 0;
}