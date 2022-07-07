#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//两个递增的有序单链表合并为一个递减的表，使用原本的结点存放归并后的顺序表，--------13   

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
		printf("%5d", p->data);
		p = p->next;
	}
	printf("\n");
}
//获取单链表长度
int Listlen(LinkList L)
{
	int len = 0;
	LNode* p = L->next;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}
//将链表置为空表
void ClearList(LinkList L)
{
	LNode* p, * s;
	p = L->next;
	while (p)
	{
		s = p->next;
		free(p);
		p = s;
	}
	L->next = NULL;
}
//有序递增单链表归并一个递减链表
void  MergeList(LinkList La,LinkList *Lb)
{
	LNode* pc = La;
	LNode* p = La->next, * q = (*Lb)->next;
	int lena = Listlen(La), lenb = Listlen(*Lb);
	while (lena && lenb){
		if (p->data >= q->data){
			pc->next = q;
			pc = q;
			q = q->next;
			lenb--;
		}
		else{
			pc->next = p;
			pc = p;
			p = p->next;
			lena--;
		}
	}
	if(lenb)
		pc->next = q;
	if (lena)
		pc->next = p;
	free(*Lb);
	p = La->next;
	La->next = NULL;
	while (p)
	{
		q = p->next;
		p->next = La->next;
		La->next = p;
		p = q;
	}
}


int main()
{
	LinkList L;
	LinkList Lb;
	InitList(&L);
	InitList(&Lb);
	int arr[] = { 9,8,7,6,5,4,3,2,1};
	int arrb[] = { 19,18,17,16,15,14,13,11,10 };
	int i = 0;
	for (i = 0; i < sizeof(arr) / 4; i++)
	{
		HeadInsert(L, arr[i]);//自定义一个数组用于初始化
		HeadInsert(Lb, arrb[i]);//自定义一个数组用于初始化
	}
	PrintList(L);
	printf("链表长：%d\n", Listlen(L));
	PrintList(Lb);
	printf("链表长：%d\n", Listlen(Lb));
	MergeList(L,&Lb);
	PrintList(L);
	printf("链表长：%d\n", Listlen(L));
	return 0;

}