#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>

//void modify_pointer(char **p)
//{
//	*p = (char*)malloc(50);
//	fgets(*p, 50, stdin);
//}
typedef int ElemType;
typedef struct LNode 
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//单链表的初始化
bool InitList(LinkList*L)
{
	*L = (LinkList)malloc(sizeof(LNode));//创建头结点，使L指向该头结点
	if (*L == NULL)
	{
		//perror(InitList);//内存分配失败
		return false;
	}
	(*L)->next = NULL;//指针域为空
	return true;
}
//在L中第i个位置之前插入新的元素e，L的长度加1
bool ListInsert(LinkList*L,int i,ElemType e)
{
	int j = 1;
	LinkList p,s;
	p = *L;
	while (j < i && p)
	{
		p = p -> next;
		++j;
	}
	if (j > i || !p)
	{
		return false;//第i个元素不存在
	}
	s = (LinkList)malloc(sizeof(LNode));//生成新结点
	s->data = e;
	s->next = p->next;//将p的后继结点赋值给s的后继
	p->next = s;//将s作为p的后继
	return true;

}
//用e返回L中第i个元素的值
bool GetElem(LinkList L,int i,ElemType *e)
{
	int j = 1;
	LinkList p;//声明一个结点p
	p = L->next;//让p指向第一个结点
	while (j < i && p)
	{
		p = p->next;
		++j;
	}
	if (j > i || !p)
	{
		//perror(GetElem);
		return false;//第i个元素不存在
	}
	else
	{
		*e = p->data;
	}
	return true;
}

//返回第i个结点的指针
LinkList GetElemP(LinkList L,int i)
{
	int j = 1;
	LinkList p = L->next;
	if (0 == i)
	{
		return L;//若i等于0，则返回头结点
	}
	 if (i < 1)
	{
		 return NULL;//若i无效，则返回NULL
	}
	 while (p && j < i)
	 {
		 p = p->next;
		 j++;
	 }
	 return p;//返回第i个结点的指针，若i大于表长，则返回NULL
}
//按值查找结点
LinkList LocateElem(LinkList L,ElemType e)
{
	LinkList p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

//头插法新建链表
void CreatList1(LinkList *L,int n)
{
	int i = 0; int j  = 0;
	ElemType e=0;
	LinkList p;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));//生成新节点
		j = scanf("%d", &p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
//尾插法新建链表
void CreatList2(LinkList* L, int n)
{
	srand((int)time(0));
	int i = 0;
	LinkList p,r;
	p = *L;
	for (i = 0; i < n; i++)
	{
		r = (LinkList)malloc(sizeof(LNode));
		r->data = rand() % 100 + 1;
		p->next = r;
		p = r;
	}
	p->next = NULL;
}
//删除链表第i个位置的元素，并用e返回其值
bool ListDelete(LinkList*L,int i,ElemType*e)
{
	//一般方法
	//int j = 0;
	//LinkList p, q;
	//p = *L;
	//while (p->next && j < i)//遍历单链表
	//{
	//	p = p->next;
	//	j++;
	//}
	//if (!p || j > i)
	//{
	//	return false;
	//}
	//q = p->next;
	//p->next = q->next;
	//*e = q->data;
	//free(q);
	//q = NULL;
	//return true;

	//采用GetelemP返回结点指针
	LinkList p = GetElemP(*L,i - 1);
	if (NULL == p)
	{
		//perror(ListDelete);
		return false;
	}
	LinkList q = p->next;
	p->next = q->next;//断链
	free(q);//释放对应结点空间
	q = NULL;//避免野指针
	return true;
}
//插入结点
bool ListFrontInsert(LinkList L, int i, ElemType e)
{
	LinkList p = GetElemP(L, i - 1);
	if (NULL == p)
	{
		return false;	
	}
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//打印链表
void PrintList(LinkList L)
{
	L= L->next;
	while (L!=NULL)
	{
		printf("%4d", L->data);
		L = L->next;
	}
	printf("\n");
}
//单链表整表删除
void ClearList(LinkList*L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);//依次释放
		p = q;
	}
	(*L)->next = NULL;//释放头结点的指针域 
}
//求表长
int ListLength(LinkList L)
{
	int count=0;
	L = L->next;
	while (L != NULL)
	{
		count++;
		L = L->next;
	}
	return count;
}

//合并La和Lb两个有序链表为Lc，Lc依旧为有序链表
void MergeList(LinkList*La,LinkList*Lb,LinkList*Lc)
{
	LinkList pa = (*La)->next;
	LinkList pb = (*Lb)->next;
	LinkList pc = *La;
	*Lc = pc;//用La的头结点作为Lc的头结点 
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa: pb;
	free(*Lb);
}
int main()
{
	//char* p=NULL;
	//modify_pointer(&p);
	//printf("%s", p);
	ElemType e=0;
	LinkList L ;//头指针
	LinkList Lb ;//头指针
	LinkList Lc;
	LinkList search=NULL;//用来存储某一个结点
	InitList(&L);//一定要记得初始化
	InitList(&Lb);//一定要记得初始化
	InitList(&Lc);//一定要记得初始化
	CreatList1(&Lb,3);
	PrintList(Lb);
//	getchar();
	CreatList1(&L,2);
	//ListDelete(&L, 3, &e);
	PrintList(L);
	MergeList(&L,&Lb,&Lc);//有序表的合并
	PrintList(L);
	printf("%d", ListLength(L));
	return 0;
}