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

//������ĳ�ʼ��
bool InitList(LinkList*L)
{
	*L = (LinkList)malloc(sizeof(LNode));//����ͷ��㣬ʹLָ���ͷ���
	if (*L == NULL)
	{
		//perror(InitList);//�ڴ����ʧ��
		return false;
	}
	(*L)->next = NULL;//ָ����Ϊ��
	return true;
}
//��L�е�i��λ��֮ǰ�����µ�Ԫ��e��L�ĳ��ȼ�1
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
		return false;//��i��Ԫ�ز�����
	}
	s = (LinkList)malloc(sizeof(LNode));//�����½��
	s->data = e;
	s->next = p->next;//��p�ĺ�̽�㸳ֵ��s�ĺ��
	p->next = s;//��s��Ϊp�ĺ��
	return true;

}
//��e����L�е�i��Ԫ�ص�ֵ
bool GetElem(LinkList L,int i,ElemType *e)
{
	int j = 1;
	LinkList p;//����һ�����p
	p = L->next;//��pָ���һ�����
	while (j < i && p)
	{
		p = p->next;
		++j;
	}
	if (j > i || !p)
	{
		//perror(GetElem);
		return false;//��i��Ԫ�ز�����
	}
	else
	{
		*e = p->data;
	}
	return true;
}

//���ص�i������ָ��
LinkList GetElemP(LinkList L,int i)
{
	int j = 1;
	LinkList p = L->next;
	if (0 == i)
	{
		return L;//��i����0���򷵻�ͷ���
	}
	 if (i < 1)
	{
		 return NULL;//��i��Ч���򷵻�NULL
	}
	 while (p && j < i)
	 {
		 p = p->next;
		 j++;
	 }
	 return p;//���ص�i������ָ�룬��i���ڱ����򷵻�NULL
}
//��ֵ���ҽ��
LinkList LocateElem(LinkList L,ElemType e)
{
	LinkList p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

//ͷ�巨�½�����
void CreatList1(LinkList *L,int n)
{
	int i = 0; int j  = 0;
	ElemType e=0;
	LinkList p;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
		j = scanf("%d", &p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
//β�巨�½�����
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
//ɾ�������i��λ�õ�Ԫ�أ�����e������ֵ
bool ListDelete(LinkList*L,int i,ElemType*e)
{
	//һ�㷽��
	//int j = 0;
	//LinkList p, q;
	//p = *L;
	//while (p->next && j < i)//����������
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

	//����GetelemP���ؽ��ָ��
	LinkList p = GetElemP(*L,i - 1);
	if (NULL == p)
	{
		//perror(ListDelete);
		return false;
	}
	LinkList q = p->next;
	p->next = q->next;//����
	free(q);//�ͷŶ�Ӧ���ռ�
	q = NULL;//����Ұָ��
	return true;
}
//������
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
//��ӡ����
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
//����������ɾ��
void ClearList(LinkList*L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);//�����ͷ�
		p = q;
	}
	(*L)->next = NULL;//�ͷ�ͷ����ָ���� 
}
//���
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

//�ϲ�La��Lb������������ΪLc��Lc����Ϊ��������
void MergeList(LinkList*La,LinkList*Lb,LinkList*Lc)
{
	LinkList pa = (*La)->next;
	LinkList pb = (*Lb)->next;
	LinkList pc = *La;
	*Lc = pc;//��La��ͷ�����ΪLc��ͷ��� 
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
	LinkList L ;//ͷָ��
	LinkList Lb ;//ͷָ��
	LinkList Lc;
	LinkList search=NULL;//�����洢ĳһ�����
	InitList(&L);//һ��Ҫ�ǵó�ʼ��
	InitList(&Lb);//һ��Ҫ�ǵó�ʼ��
	InitList(&Lc);//һ��Ҫ�ǵó�ʼ��
	CreatList1(&Lb,3);
	PrintList(Lb);
//	getchar();
	CreatList1(&L,2);
	//ListDelete(&L, 3, &e);
	PrintList(L);
	MergeList(&L,&Lb,&Lc);//�����ĺϲ�
	PrintList(L);
	printf("%d", ListLength(L));
	return 0;
}