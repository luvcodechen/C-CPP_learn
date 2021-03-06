#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//增序输出单链表各结点并释放所占的存储空间--------09    考虑排序后置空表

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

//删除单链表中最小结点，（假设最小结点唯一）
bool DeleteMiniElem(LinkList L, ElemType* elem)
{
	if (L->next == NULL)
		return false;//L是空表
	LNode* now = L->next;//记录当前遍历到的结点
	LNode* min = L->next;//记录遍历到的结点中的最小值结点
	LNode* prenow = L;//记录当前结点的前驱
	LNode* premin = L;//记录最小结点的前驱
	*elem = min->data;//假定第一个最小
	while (now)
	{
		if (now->next && now->next->data < *elem)
		{
			premin = now;
			min = now->next;
			*elem = min->data;//更新min
		}
		prenow = now;//继续遍历
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


//交换两个数
void swap(ElemType* a, ElemType* b)
{
	ElemType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


//使单链表递增有序，考虑冒泡
bool bubblesort(LinkList L)
{
	if (!L->next)
		return false;
	int len = Listlen(L);
	while (len)
	{
		int i = len--;
		LNode* p = L->next;
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

//删除给定范围内的结点
bool deletes_t(LinkList L, ElemType s, ElemType t)
{
	LNode* p = L->next;
	if (!p)
		return false;
	LNode* pre = L;//前驱结点
	while (p)
	{
		if (p->data > s && p->data < t)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
	return true;
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

int main()
{
	LinkList L;
	InitList(&L);
	int arr[] = { 12,152,15,61,20,48,25,15,21,15 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		HeadInsert(L, arr[i]);//自定义一个数组用于初始化
	}
	PrintList(L);
	//ElemType elem;
	//DeleteMiniElem(&L, &elem);//删除最小结点
	printf("链表长：%d\n", Listlen(L));
	int ret = bubblesort(L);
	if (ret)
		PrintList(L);
	else
		printf("排序失败\n");
	//deletes_t(L, 19, 50);
	ClearList(L);
	PrintList(L);
	return 0;

}