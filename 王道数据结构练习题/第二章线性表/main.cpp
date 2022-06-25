#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20
typedef int ElemType;
//顺序表结构体
typedef struct
{
	ElemType data[MaxSize];
	int length;
}Sqlist;//顺序表

//初始化顺序表
void InitList(Sqlist &L)
{
	L.length = 0;
}
//删除最小元素,并返回其值，空出的位置用最后一个元素填补  ------第二章第一题
bool DeleteMinElem(Sqlist &L,ElemType &e)
{
	int i = 0;
	ElemType elem = 0;
	int pos = 0;
	if (0 == L.length)
	{
		printf("顺序表为空");
		return false;
	}		
	elem = L.data[0];
	for (i = 1; i < L.length; i++)
	{
		if (L.data[i] < elem)//找到最小值和下标
		{
			elem = L.data[i];
			e = L.data[i];
			pos = i;
		}
	}
	L.data[pos] = L.data[L.length - 1];//修改值
	L.length--;
	return true;
}

//设计一个高效算法，将元素逆置，要求空间复杂度o(1）-------第二题
void reverselist(Sqlist &L)
{
	int i,j;
	ElemType temp = 0;
	for (i = 0, j = L.length - 1; i <j; i++, j--)//交换
	{
		temp = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = temp;
	}
}
//对长度为n的顺序表L,写一个时间复杂度n，空间1算法，删除所有值为x的元素------ 第三题
void deletex(Sqlist &L,ElemType x)
{
	int count = 0;//计数
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] != x)
		{
			L.data[count] = L.data[i];
			count++;
		}
	}
	L.length = count;
}

//从有序顺序表删除值在给定值s到t之间的所有元素，s<t,s或者t不合理或者为空给出反应。----------第四题
bool deletest(Sqlist &L,int s,int t)
{
	if (s >= t || L.length == 0)
		return false;
	int low=0, high=0;
	int minus;
	int i = 0;
	for (i = 0; i < L.length && L.data[i] <= s; i++);//找到比s大的最小的数的下标
	if (i >= L.length)//所有数比s小
		return false;
		low = i;
	for (i = low; i < L.length && L.data[i] < t; i++);//找到不比t小的最小的数的下标
		high = i;
	minus = high - low;//计算应该删除多少个数
	for (i = high; i <L.length; i++)//将没有删除的数前移
	{
		L.data[i - minus] = L.data[i];
	}
	L.length -= minus;
	return true;
}

//从无序顺序表删除值在给定值s到t之间的所有元素，s<t,s或者t不合理或者为空给出反应。----------第五题
bool delete_s_t(Sqlist &L,int s,int t)
{
	if (s >= t || L.length == 0)
		return false;//报错
	int i = 0;
	int count = 0;
	for (i = 0; i < L.length - 1; i++){
		if (L.data[i]<=s || L.data[i]>=t)//等于号控制是否包含边界
		{
			L.data[count] = L.data[i];
			count++;
		}
	}//for
	L.length = count;
	return true;
}

//打印顺序表
void PrintList(Sqlist L)
{
	int i = 0;
	if (L.length)
		for (i = 0; i < L.length; i++)
			printf("%d ", L.data[i]);
	printf("\nL.length=%d", L.length);
	printf("\n");
}
int main()
{

	int i = 0;
	ElemType e;
	Sqlist L;
	InitList(L);
	int arr1[] = { 10,20,30,40,50,51,55,60,66,70,80,90};
	int arr2[] = { 11,12,30,7,5,51,21,26,24,65,1,46};
	for (i = 0; i < sizeof(arr1)/sizeof(ElemType); i++)
	{
		L.data[i] = arr1[i];//用已有数组给顺序表初始化
	}
	L.length = sizeof(arr1) / sizeof(ElemType);
	//DeleteMinElem(L,e);//删除最小元素并用e返回其值
	//reverselist(L);//将元素逆置
	//deletex(L,11);//删除值为11的数
	//delete_s_t(L,10,30);//删除值在20—30之间的数
	deletest(L,10,100);//在有序表中删除值在19-49的值，不包含边界
	PrintList(L);
	return 0;
}