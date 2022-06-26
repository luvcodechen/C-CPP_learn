#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//设计一个递归算法删除不带头结点的单链表L中的所有值为x的结点

typedef int ElemType;

//单链表抽象数据类型定义
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//单链表的初始化
void InitList(LinkList &L)//不带头结点
{
	L = NULL;
}

//按位序查找结点
LNode * GetNode(LinkList L,int i)
{
	if (i < 1) 
		return NULL;
	if (i == 1)
		return L;//因不带头结点，第一个结点就是L自身
	int j = 1;
	LNode* p = L;
	while (p!= NULL && j < i)//遍历单链表
	{
		p = p->next;
		j++;
	}
	return p;
}

//在某个结点后面插入新结点
bool InsertNextNode(LNode *p,ElemType e)
{
	if (!p)
		return false;//p为NULL，报错
	LNode* s = (LNode*)calloc(1, sizeof(LNode));
	if (!s)
		return false;//申请内存失败，报错
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//在第i个位置插入元素
bool InsertList(LinkList &L,int i,ElemType e)
{
	if (i < 1) 
		return false;//位置不合法
	if (i == 1)
	{	
		LNode* s = (LNode*)calloc(1, sizeof(LNode));
		if (!s)
			return false;
		else
		{	
			s->data = e;
			s->next = L;
			L = s;
			return true;	
		}
		
	}
	//LNode* p = L;//游标指针
	//int j = 1;
	//while (p != NULL && j < i-1)
	//{
	//	p = p->next;
	//	j++;
	//}
	LNode* p = GetNode(L, i - 1);
	return InsertNextNode(p, e);
}

//头插法
bool HeadInsert(LinkList &L,ElemType e)
{
	return InsertList(L,1,e);//在第一个位置插入
}
//删除第i个结点
bool DeleteNode(LinkList &L,int i)
{
	if (i < 1)
		return false;
	if (i == 1)
	{
		if (L->next == NULL)//只有一个结点
		{
			L = NULL;//单链表置空
			return true;
		}
		LNode* s = L;
		L = L->next;
		free(s);
		return true;
	}
	LNode* s = GetNode(L, i - 1);
	if (s == NULL)
		return false;
	LNode* q = s->next;
	if (q == NULL)
		return false;
	s->next = q->next;
	free(q);
	return true;
}

//从某个结点开始找值为x的结点
LNode* GetElem(LNode*s,ElemType x)
{
	if (s == NULL)
		return NULL;
	while (s)
	{
		if (s->data == x)
			return s;
		s = s->next;
	}
	return NULL;
}

//递归算法，删除值为x的结点
void deletex(LinkList &L,ElemType x)
{
	LNode* s = NULL;//用来存待删的结点
	if (L == NULL)
		return;//递归终点
	if (L->data == x)//若找到x，则删除，进入下一层
	{
		s = L;
		L = L->next;
		free(s);
		deletex(L,x);
	}
	deletex(L->next,x);	//么有找到。往下面找
}

//打印单链表
void PrintList(LinkList L)
{
	if (!L)
		return;
	LNode* p = L;
	while (p)
	{
		printf("%3d", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LinkList L;
	InitList(L);
	for (int i = 10; i > 0; i--)
	{
		HeadInsert(L,i);//头插
	}
	//PrintList(L);
	InsertList(L,1,15);
	InsertList(L,1,6);
	InsertList(L,3,8);
	InsertList(L,5,15);
	InsertList(L,7,15);
	InsertList(L,15,15);
	InsertList(L,10,15);
	PrintList(L);
	//DeleteNode(L,1);
	//PrintList(L);
	deletex(L,15);
	PrintList(L);
	return 0;
}