#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//试写算法：在带头结点的单链表L中删除一个最小值结点（假设最小值唯一）

typedef int ElemType;

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
bool InsertList(LinkList* L, int i, ElemType e)
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
			s->next = (*L)->next;
			(*L)->next = s;//带头结点的单链表，头指针指向第一个结点
			return true;
		}

	}
	LNode* p = GetNode(*L, i - 1);
	return InsertNextNode(p, e);
}

//头插法
bool HeadInsert(LinkList* L, ElemType e)
{
	return InsertList(L, 1, e);//在第一个位置插入
}

//删除单链表中最小结点，（假设最小结点唯一）
bool DeleteMiniElem(LinkList *L,ElemType *elem)
{
	if ((*L)->next == NULL)
		return false;//L是空表
	LNode* now = (*L)->next;//记录当前遍历到的结点
	LNode* min = (*L)->next;//记录遍历到的结点中的最小值结点
	LNode* prenow = *L;//记录当前结点的前驱
	LNode* premin = *L;//记录最小结点的前驱
	elem = min->data;//假定第一个最小
	while (now)
	{	
		if (now->next&&now->next->data < elem)
		{
			premin = now;
			min = now->next;
			elem = min->data;
		}
		prenow = now;
		now = now->next;

	}
	premin->next = min->next;
	free(min);
	return true;
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
	LinkList L;
	//ElemType elem;
	//DeleteMiniElem(&L,&elem);
	InitList(&L);
	int arr[] = {7,81,12,61,52,48,25,1,21,15};
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		HeadInsert(&L, arr[i]);//自定义一个数组用于初始化
	}
	PrintList(L);
	ElemType elem;
	DeleteMiniElem(&L,&elem);
	PrintList(L);
	return 0;

}