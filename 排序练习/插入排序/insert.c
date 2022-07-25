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
//��������,��������   
void Insertsort(int *a)
{
	int i, j;
	for (i = 1; i < MAX; i++)//��һ��Ĭ�����򣬴��±�Ϊ1��ʼ��Ҳ���ǵڶ���Ԫ��
	{
		if (a[i] < a[i - 1])//�����ǰԪ�ر���һ��С
		{
			int temp = a[i];//�ݴ浱ǰԪ��
			for (j = i; j >0 && a[j - 1] > temp; j--)//��ǰ��ıȵ�ǰ��Ķ�����
				a[j] = a[j-1];
			a[j] = temp;//�ҵ�λ��
		}
	}
}
//�۰�������������ֱ�Ӳ�������˱Ƚϴ������ƶ��������䣬�����ٶ�û��ʵ������
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
