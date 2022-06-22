#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef int ElemType;
//动态分配内存的一维数组
typedef struct {
	ElemType* elem;//整形指针
	int ArrLen;//数组初始长度
}Arr;
//初始化数组并传入要初始化的个数
bool InitArr(Arr* s, int len) {
	s->ArrLen = len + 1;//多申请一个空间做哨兵
	s->elem = (ElemType*)calloc(s->ArrLen,sizeof(ElemType));
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
		printf("%d ",s.elem[i]);
	}
	printf("\n");
}
//顺序查找,返回位置
int Search_Seq(Arr s,ElemType key) {
	s.elem[0] = key;//哨兵
	int i = 0;
	for (i = s.ArrLen - 1; s.elem[i] != key; i--);
		return i;
	
}
int main()
{
	srand((unsigned)time(NULL));
	Arr s;
	InitArr(&s,10);
	PrintArr(s);
	ElemType key;
	printf("请输入要查找的元素的值；\n");
	scanf("%d", &key);
	if (Search_Seq(s, key))
	{
		printf("查找成功，元素位置为%d\n", Search_Seq(s, key));
	}
	else { 
		printf("查找失败"); }

	//qsort();
	return 0;

}