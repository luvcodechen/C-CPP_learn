#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//���һ���ݹ��㷨ɾ������ͷ���ĵ�����L�е�����ֵΪx�Ľ��

typedef int ElemType;

//����������������Ͷ���
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//������ĳ�ʼ��
void InitList(LinkList &L)//����ͷ���
{
	L = NULL;
}

//��λ����ҽ��
LNode * GetNode(LinkList L,int i)
{
	if (i < 1) 
		return NULL;
	if (i == 1)
		return L;//�򲻴�ͷ��㣬��һ��������L����
	int j = 1;
	LNode* p = L;
	while (p!= NULL && j < i)//����������
	{
		p = p->next;
		j++;
	}
	return p;
}

//��ĳ������������½��
bool InsertNextNode(LNode *p,ElemType e)
{
	if (!p)
		return false;//pΪNULL������
	LNode* s = (LNode*)calloc(1, sizeof(LNode));
	if (!s)
		return false;//�����ڴ�ʧ�ܣ�����
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//�ڵ�i��λ�ò���Ԫ��
bool InsertList(LinkList &L,int i,ElemType e)
{
	if (i < 1) 
		return false;//λ�ò��Ϸ�
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
	//LNode* p = L;//�α�ָ��
	//int j = 1;
	//while (p != NULL && j < i-1)
	//{
	//	p = p->next;
	//	j++;
	//}
	LNode* p = GetNode(L, i - 1);
	return InsertNextNode(p, e);
}

//ͷ�巨
bool HeadInsert(LinkList &L,ElemType e)
{
	return InsertList(L,1,e);//�ڵ�һ��λ�ò���
}
//ɾ����i�����
bool DeleteNode(LinkList &L,int i)
{
	if (i < 1)
		return false;
	if (i == 1)
	{
		if (L->next == NULL)//ֻ��һ�����
		{
			L = NULL;//�������ÿ�
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

//��ĳ����㿪ʼ��ֵΪx�Ľ��
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

//�ݹ��㷨��ɾ��ֵΪx�Ľ��
void deletex(LinkList &L,ElemType x)
{
	LNode* s = NULL;//�������ɾ�Ľ��
	if (L == NULL)
		return;//�ݹ��յ�
	if (L->data == x)//���ҵ�x����ɾ����������һ��
	{
		s = L;
		L = L->next;
		free(s);
		deletex(L,x);
	}
	deletex(L->next,x);	//ô���ҵ�����������
}

//��ӡ������
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
		HeadInsert(L,i);//ͷ��
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