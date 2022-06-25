#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 30
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
//有序表中删除重复元素，使表中元素不同--------------第六题
void deletesame(Sqlist &L)
{
	int i = 0,j = 0;
	for (i = 0; i < L.length; i++)
		if (L.data[i] != L.data[i + 1])
			L.data[j++] = L.data[i];//前后不同则存入
	L.length = j;
}

//有序表的合并------------------------第七题
Sqlist un( Sqlist La, Sqlist Lb)
{
	Sqlist Lc;
	int i = 0,j = 0,k = 0,lena = La.length,lenb=Lb.length;
	for (i = 0,j = 0; i < lena&&j<lenb;)
	{
		if (La.data[i] <= Lb.data[j])
			Lc.data[k++] = La.data[i++];
		else
			Lc.data[k++] = Lb.data[j++];
	}
	while (i < lena)
		Lc.data[k++] = La.data[i++];
	while (j < lenb)
		Lc.data[k++] = Lb.data[j++];
	Lc.length = k;
	return Lc;
}
//已知一维数组A[m+n]存放了两个线性表a1，a2···，am，b1，b2···bn，将两表顺序互换----------第八题
void change(ElemType B[], int m, int n)
{
	Sqlist Lm, Ln;
	int i = 0,j = 0;
	for (i = 0; i < m; i++)
		Lm.data[i] = B[i];
	Lm.length = m;
	for (; i < m + n; i++)
		Ln.data[j++] = B[i];
	Ln.length = n;
	for (i = 0; i < n; i++)
		B[i] = Ln.data[i];
	j = 0;
	for (; i < m + n; i++)
		B[i] = Lm.data[j++];

}
//线性表有序递增，设计算法最少时间找到某值，若找到，与后继位置交换。若没有，则插入----------第九题

//折半查找
int BinarySearch(Sqlist L,ElemType e)
{
	int low = 0, high = L.length-1,mid = 0;
	while(low <= high)
	{
		mid = (low+high) / 2;
		if (L.data[mid] == e)return mid;
		else if (L.data[mid] < e)low = mid + 1;
		else high = mid - 1;
	}
	return mid;
}
//按位置插入
bool InsertList(Sqlist&L,int pos,ElemType e)
{
	if (pos<1 || pos>L.length + 1 || L.length == MaxSize)
		return false;//非法
	int i = 0;
	for (i = L.length - 1; i >= pos - 1; i--)
	{
		L.data[i + 1] = L.data[i];
	}
	L.data[pos - 1] = e;
	L.length++;
	return true;
}
//第九题具体实现
void search_change(Sqlist&L,ElemType x)
{
	int ret=BinarySearch(L,x);
	if (L.data[ret] == x&&ret!=L.length-1)
	{
		ElemType temp = L.data[ret];
		L.data[ret] = L.data[ret + 1];
		L.data[ret + 1] = temp;
		return;
	}
	if (L.data[ret] > x)
		InsertList(L, ret+1, x);
	else if(L.data[ret]<x)
		InsertList(L, ret + 2, x);
}
//n个整数在一维数组R中。将r中保存的序列循环左移p，0<p<n,-------------------第十题
void cirleftmove(ElemType *R, int p) {
	int n = 10;
	int i = 0, k = 0;
	ElemType arr[10] ;
	for (i = 0; i < n; i++)
	{
		arr[(i + n - p)%n] = R[i];//循环左移公式
	}
	for (i = 0; i < n; i++)
	{
		R[i] = arr[i];//空间复杂度和时间复杂度均为o(n).
	}
}
//第十题，空间o(1)实现
//逆置数组下标s-t之间的数,包括边界
void reverse(int *A,int s,int t)
{
	int i = 0, temp = 0,j = 0;
	for (i = s,j = 0; i < (t-j); i++, j++)
	{
		temp = A[i]; A[i] = A[t - j]; A[t - j] = temp;
	}
}
void cirleftmove1(ElemType* R, int p)
{
	int n = 10;
	reverse(R,0,p-1);
	reverse(R,p,n-1);
	reverse(R,0,n-1);
}

//打印顺序表
void PrintList(Sqlist L)
{
	int i = 0;
	if (L.length)
		for (i = 0; i < L.length; i++)
			printf("%d ", L.data[i]);
	printf("\nlength=%d", L.length);
	printf("\n");
}
int main()
{

	int i = 0;
	ElemType e = 0;
	Sqlist L;
	Sqlist Lb;
	Sqlist Lc;
	InitList(L);
	InitList(Lb);
	ElemType A[] = { 10,20,50,51,60,66,8,11,30,51};
	int arr1[] = { 10,20,20,20,50,51,51,60,66,66,80,90};
	int arr3[] = { 1,2,3,4,5,15,20,30,65,75,80,95};
	int arr2[] = { 11,12,30,7,5,51,21,26,24,65,1,46};
	for (i = 0; i < sizeof(arr1)/sizeof(ElemType); i++)
	{
		L.data[i] = arr1[i];//用已有数组给顺序表初始化
	}
	L.length = sizeof(arr1) / sizeof(ElemType);
	for (i = 0; i < sizeof(arr3)/sizeof(ElemType); i++)
	{
		Lb.data[i] = arr3[i];//用已有数组给顺序表初始化
	}
	Lb.length = sizeof(arr3) / sizeof(ElemType);
	//DeleteMinElem(L,e);//删除最小元素并用e返回其值
	//reverselist(L);//将元素逆置
	//deletex(L,11);//删除值为11的数
	//delete_s_t(L,10,30);//删除值在20—30之间的数
	//deletest(L,10,10);//在有序表中删除值在19-49的值，不包含边界
	//deletesame(L);//删除有序表中重复元素使表中元素不同
	//change(A,10,8);//交换数组的两个长度为10和8的线性表的位置
	//for (i = 0; i < sizeof(A) / 4; i++)
	//	printf("%d ", A[i]);
	//printf("\n");
	//PrintList(Lb);
	//Lc = un(L,Lb);//有序表的合并
	//PrintList(Lc);
	//PrintList(L);
	//printf("%d\n", BinarySearch(L, 90));
	//search_change(L,90);//有序表中查找90，若有，与后继交换，若无，插入
	//cirleftmove1(A,5);
	//for (int i = 0; i < 01; i++)
		//printf("%d ", A[i]);
	PrintList(L);

	return 0;
}