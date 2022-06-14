#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef int ElemType;//顺序表中，元素的类型
//静态分配
typedef struct 
{
  ElemType data[MaxSize];//定义的数组，用来存元素
  int length;//当前顺序表中有多少元素
}Sqlist;

//初始化顺序表
void  InitList(Sqlist&L) 
{
	L.length = 0;
	
}
//i代表插入的位置，从1开始，e要插入的元素
bool ListInsert(Sqlist& L, int i, ElemType e)
{
	  if(i<1||i>L.length+1)//判断要插入的位置是否合法
		return false;

	  if (L.length >= MaxSize)//元素存储已满，超出空间了
		return false;

	  if(i <= L.length)
	  { 
		  for (int j = L.length; j >= i-1; j--)//移动顺序表中的元素
		  L.data[j] = L.data[j - 1]; }
 
	  L.data[i - 1] = e;//数组下标从0开始，插入第一个位置，访问的下标为0
	  L.length++;
	  return true;//走到这里说明插入成功，返回true
}

//删除使用元素e的引用的目的是拿出对应的值
bool ListDelete(Sqlist& L, int i, ElemType & e)
{
  if (i<1 || i>L.length)//判断要删除的位置是否合法
	return false;
  e = L.data[i - 1];//获取顺序表中对应的元素，赋值给e
  for (int j = i; j < L.length; j++)//从i的位置，依次把元素往前覆盖
  {
	L.data[j - 1] = L.data[j];
  }
  L.length--;//删除一个元素，顺序表长度减一
  return true;
}



//打印顺序表元素
void PrintList(Sqlist& L)
{
  for (int i = 0; i < L.length; i++)
  {
	printf("%-3d", L.data[i]);//要求所有元素打印到一排
  }
  printf("\n");
}

//查找成功，返回位置，位置从1开始，查找失败，返回0
int LocateElem(Sqlist& L, ElemType e)
{
  int i;
  for (i = 0; i < L.length; i++)
  {
	if (L.data[i] == e)
	{
	  return i + 1;//加一就是元素在顺序表中的位置
	}
  }
	return 0;
  
}
//用e返回L中第i个元素的值，注意i是位置,数组下标应为i-1
bool GetElem(Sqlist& L, int i, ElemType& e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return false;
	e = L.data[i-1];
	return true;
}
//将L置为空表
bool ClearList(Sqlist &L)
{
	L.length = 0;
	return true;
}
//返回L中数据元素个数
int ListLength(Sqlist L)
{
	return L.length;

}
/*将所有的在线性表Lb中但不在La中的数据元素插入到La中*/
void unionL(Sqlist& La, Sqlist Lb)
{
	int La_len, Lb_len, i;
	ElemType e;                        /*声明与La和Lb相同的数据元素e*/
	La_len = ListLength(La);            /*求线性表的长度 */
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, e);              /*取Lb中第i个数据元素赋给e*/
		if (!LocateElem(La, e))        /*La中不存在和e相同数据元素*/
			ListInsert(La, La_len++, e); /*插入*/
	}
}
int main()
{
  Sqlist L;//顺序表的名称
  Sqlist Lb;//第二个顺序表
  bool ret;//查看返回值，布尔型是True，或者False
  ElemType del;//用来存要删除的元素
  InitList(L);
  //首先手动在顺序表中前三个元素赋值
  //L.data[0] = 1;			
  //L.data[1] = 2;
  //L.data[2] = 3;
  //L.length = 3;//总计三个元素
  //int quantity;//定义要初始化的元素数量
  //printf("请输入要初始化线性表的数量:\n");
  //scanf("%d", &quantity);
    int j;
	
	     for(j=1;j<=5;j++)
		 ListInsert(L,1,j);
		
		printf("当前顺序表为：\n");
		PrintList(L);
  ret = ListInsert(L, 2, 6);//往第二个位置插入'60'这个元素
  if (ret)
  {
	printf("插入成功\n");
	printf("当前顺序表为：\n");
	PrintList(L);//打印成功后的顺序表
  }
  else {
	printf("插入失败\n");
	printf("当前顺序表为：\n");
	PrintList(L);
  }
  ret = ListDelete(L, 1, del);//删除第一个位置的元素，并把元素值输出
  if (ret)
  {
	printf("删除成功\n");
	printf("删除的值为%d\n", del);
	printf("当前顺序表为：\n");
	PrintList(L);//打印成功后的顺序表
  }
  else
  {
	printf("删除失败");
	printf("当前顺序表为：\n");
	PrintList(L);
  }
  int elem_pos,a;
  printf("请输入要查找的元素\n");
  scanf("%d", &a);
  elem_pos = LocateElem(L,a);
  printf("查找的元素为%d\n", a);
  if (elem_pos)
  {
	printf("查找成功\n");
	printf("元素位置为%d\n", elem_pos);
	printf("当前顺序表为：\n");
	PrintList(L);
  }
  else
  {
	printf("查找失败\n");
	printf("当前顺序表为：\n");
	PrintList(L);
  }
  int i;
  printf("请输入要查找的元素位置\n");
  scanf("%d", &i);
  ret = GetElem(L, i, del); 
  if (ret)
  {
	  printf("查找成功，查到的元素为：\n");
	  printf("%d\n", del);
	  printf("当前顺序表为：\n");
	  PrintList(L);
  }
  else
  {
	  printf("查找失败\n");
	  printf("当前顺序表为：\n");
	  PrintList(L);
  }
  InitList(Lb);
  for (j = 6; j <= 15; j++)
	  i = ListInsert(Lb, 1, j);
  printf("新的顺序表Lb如下所示：\n");
  PrintList(Lb);
  unionL(L, Lb);
  printf("依次输出合并了Lb的L的元素：\n");
  PrintList(L);
  return 0;
}