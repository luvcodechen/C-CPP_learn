#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//设计算法判断链表的n个字符是否中心对称

typedef char ElemType;

//单链表抽象数据类型定义
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//单链表的初始化
bool  InitList(LinkList* L)//带头结点
{
	*L = (LNode*)calloc(1, sizeof(LNode));
	if (*L == NULL)
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
bool InsertList(LinkList L, int i, ElemType e)
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
bool HeadInsert(LinkList L, ElemType e)
{
	return InsertList(L, 1, e);//在第一个位置插入
}



//打印单链表
void PrintList(LinkList L)
{
	if (!L->next)
		return;
	LNode* p = L->next;
	while (p)
	{
		printf("%5c", p->data);
		p = p->next;
	}
	printf("\n");
}
//获取单链表长度
int Listlen(LinkList L)
{
	int len = 0;
	while (L->next)
	{
		len++;
		L = L->next;
	}
	return len;
}


//交换两个数
void swap(ElemType* a, ElemType* b)
{
	ElemType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


//使单链表递增有序，考虑冒泡
bool bubblesort(LinkList* L)
{
	if (!(*L)->next)
		return false;
	int len = Listlen(*L);
	while (len)
	{
		int i = len--;
		LNode* p = (*L)->next;
		LNode* q = p->next;
		while (i-- && q)
		{
			if (p->data > q->data)
				swap(&p->data, &q->data);//大的放在后面
			p = q;//继续向后
			q = q->next;
		}
	}
	return true;
}
int main()
{
	LinkList L;
	InitList(&L);
	char arr[] = {'a','b','c','c','b','a'};
	int i = 0;
	for (i = 0; i < sizeof(arr); i++)
	{
		HeadInsert(L, arr[i]);//自定义一个数组用于初始化
	}
	PrintList(L);
	printf("链表长：%d\n", Listlen(L));
	char stack[10] = {0};
	int len = Listlen(L);
	for (i = 0; i < len; i++)
	{
		LNode *s= GetNode(L, i + 1);
		stack[i] = s->data;
	}
	puts(stack);
	int j;
	int tag = 0;
	for (i = 0, j = len - 1; i <= j; i++, j--)
	{
		if (stack[i] == stack[j])
			tag = 1;
		else
			tag = 0;
	}
	if (tag)
		printf("对称\n");
	return 0;

}