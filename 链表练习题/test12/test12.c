#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//空间（1），时间尽可能高效的算法，重新排列L中的各节点，到L'{a1,an,a2,a(n-1),·····a(n-2)··}，--------2019统考真题    

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

//重新排列L
void ReSortList(LinkList L)
{
	LNode* p, * q, * r, * s;
	p = q = L;
	while (q) {//找到中间结点
		r = q->next;
		if (r){
			q = r->next; p = p->next;
		}
		else
			break;
	}
	r = p->next;//将后一半结点指针逆置
	p->next = NULL;//前后分离，断链
	q = r->next;
	r->next = NULL;
	while (q)
	{
		s = r;
		r = q;
		q=q->next;
		r->next = s;
	}//逆置指针
	q = L->next;
	while (r)//将逆置后的后一半链表元素依次插入链表
	{		
		p = q->next;
		s = r; //取后一半链表第一个结点
		r = r->next;//指针后移
		s->next = p; q->next = s;//将结点插入
		q = p; 
		if (r)//待插入结点后移
			p = p->next;
	}


}


int main()
{
	LinkList L;
	InitList(&L);
	int arr[] = { 11,10,9,8,7,6,5,4,3,2,1 };
	int i = 0;
	for (i = 0; i < sizeof(arr) / 4; i++)
	{
		HeadInsert(L, arr[i]);//自定义一个数组用于初始化
	}
	PrintList(L);
	printf("链表长：%d\n", Listlen(L));
	ReSortList(L);
	PrintList(L);
	return 0;

}