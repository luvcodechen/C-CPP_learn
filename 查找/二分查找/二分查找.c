#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

typedef int ElemType;
//动态分配内存的一维数组
typedef struct {
	ElemType* elem;//整形指针
	int ArrLen;//数组初始长度
}Arr;
//初始化数组并传入要初始化的个数
bool InitArr(Arr* s, int len) {
//	s->ArrLen = len + 1;//多申请一个空间做哨兵
	s->ArrLen = len;
	s->elem = (ElemType*)calloc(s->ArrLen, sizeof(ElemType));
	if (!s->elem)
	{
		return false;
	}
	int i = 0;
	for (i = 0; i < s->ArrLen; i++)
	{
		s->elem[i] = rand() % 100 + 1;
	}
	return true;
}
//打印数组
void PrintArr(Arr s)
{
	int i = 0;
	for (i = 0; i < s.ArrLen; i++) {
		printf("%d ", s.elem[i]);
	}
	printf("\n");
}
//二分查找
int Binary_Search(Arr s,ElemType key)
{
	int left=0, right=s.ArrLen-1,mid=0;
	int i = 0;
	while (left <= right)
	{
		
		i++;
		mid = (left + right) / 2;
		if (s.elem[mid] == key)
		{
			printf("查找次数为;\n");
			printf("%d\n", i);
			return mid + 1;
		}
		else if (key < s.elem[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int compare(const void* left, const void* right)
{
	return *(ElemType*)left - *(ElemType*)right;
}
int main()
{
	srand((unsigned)time(NULL));
	Arr s;
	InitArr(&s, 20);
	PrintArr(s);
	ElemType key;
	qsort(s.elem,s.ArrLen,sizeof(ElemType),compare);//快速排序
	PrintArr(s);
	printf("请输入要查找的元素的值；\n");
	int j =scanf("%d", &key);
	int pos = Binary_Search(s, key);
	if (pos>=0) {
		printf("查找成功，元素位置为;%d\n",pos);
	}
	else
		printf("查找失败，元素不存在\n");
	return 0;

}