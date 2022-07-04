#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//将一个带头结点的单链表A分开为A和B两个带头结点的链表A中含有原本链表奇数元素。B中偶数元素，保持相对次序不变，--------10    

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

//拆分单链表为两个链表分别存储奇数位序偶数位序元素
bool SplitList(LinkList La,LinkList Lb)
{
	LNode* p = La->next;
	if (!p)
		return false;
	LNode* ra = La, * rb = Lb;//尾指针
	LNode* s = p->next;
	int i = 0;
	while (p)//游标指针
	{
		i++;
		if (i % 2 != 0){
			ra->next = p; ra = p; //奇数接在a后面
		}
		else{
			rb->next = p; rb = p; //偶数接在b后面
		}
		p = p->next;
	}
	ra->next = NULL;
	rb->next = NULL;
	return true;
}

int main()
{
	LinkList L;
	InitList(&L);
	int arr[] = { 121,115,52,22,25,56,252,25,2,32,10,9,8,7,6,5,4,3,2,1 };
	int i = 0;
	for (i = 0; i < sizeof(arr)/4; i++)
	{
		HeadInsert(L, arr[i]);//自定义一个数组用于初始化
	}
	PrintList(L);
	printf("链表长：%d\n", Listlen(L));
	LinkList LB;
	InitList(&LB);
	SplitList(L,LB);
	printf("分裂后：\n");
	PrintList(L);
	PrintList(LB);
	return 0;

}