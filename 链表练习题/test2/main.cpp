#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//在带头结点的单链表中，删除所有值为x的结点，并释放其空间

typedef int ElemType;

//单链表抽象数据类型定义
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//单链表的初始化
bool  InitList(LinkList& L)//带头结点
{
	L = (LNode*)calloc(1, sizeof(LNode));
	if (L == NULL)
		return false;
	return true;
}

//按位序查找结点
LNode* GetNode(LinkList L, int i)
{
	if (i < 0)
		return NULL;
	if (i == 0)
		return L;//头结点即第0个
	int j = 0;
	LNode* p = L;
	while (p != NULL && j < i)//遍历单链表
	{
		p = p->next;
		j++;
	}
	return p;
}

//在某个结点后面插入新结点
bool InsertNextNode(LNode* p, ElemType e)
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
bool InsertList(LinkList& L, int i, ElemType e)
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
			s->next = L->next;
			L->next = s;//带头结点的单链表，头指针指向第一个结点
			return true;
		}

	}
	LNode* p = GetNode(L, i - 1);
	return InsertNextNode(p, e);
}

//头插法
bool HeadInsert(LinkList& L, ElemType e)
{
	return InsertList(L, 1, e);//在第一个位置插入
}


//删除值为x的结点
void deletex(LinkList& L, ElemType x)
{
	LNode* s = NULL;//用来存待删的结点
	LNode* q = L;
	while (q)
	{
		if (q->next&&q->next->data == x)
		{		
			s = q->next;
			q->next = s->next;
			free(s);
			continue;
		}
		q = q->next;
	}
}

//打印单链表
void PrintList(LinkList L)
{
	if (!L->next)
		return;
	LNode* p = L->next;
	while (p)
	{
		printf("%3d", p->data);
		p = p->next;
	}
	printf("\n");
}


int main()
{
	srand((unsigned)time(NULL));
	LinkList L;
	InitList(L);
	int i = 0;
	//for (i = 0; i < 5; i++)
	//	HeadInsert(L, rand() % 20 + 1);
	//PrintList(L);
	//InsertList(L,2,15);
	//PrintList(L);
	//InsertList(L,4,20);
	//PrintList(L);
	//InsertList(L,20,100);
	//PrintList(L);
	for (i = 10; i > 0; i--)
	{
		HeadInsert(L, i);//头插
	}
	//PrintList(L);
	InsertList(L, 1, 15);
	InsertList(L, 1, 10);
	InsertList(L, 5, 8);
	InsertList(L, 5, 15);
	InsertList(L, 7, 10);
	InsertList(L, 7, 10);
	InsertList(L, 15, 10);
	InsertList(L, 10, 15);
	PrintList(L);
	deletex(L,10);
	PrintList(L);
	return 0;

}