#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
//��LΪ��ͷ���ĵ������д�㷨ʵ�ִ�β��ͷ�������ÿ������ֵ 

typedef int ElemType;

//����������������Ͷ���
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//������ĳ�ʼ��
bool  InitList(LinkList* L)//��ͷ���
{
	*L = (LNode*)calloc(1, sizeof(LNode));
	if (*L == NULL)
		return false;
	return true;
}

//��λ����ҽ��
LNode* GetNode(LinkList L, int i)
{
	if (i < 0)
		return NULL;
	if (i == 0)
		return L;//ͷ��㼴��0��
	int j = 0;
	LNode* p = L;
	while (p != NULL && j < i)//����������
	{
		p = p->next;
		j++;
	}
	return p;
}

//��ĳ������������½��
bool InsertNextNode(LNode* p, ElemType e)
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
bool InsertList(LinkList* L, int i, ElemType e)
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
			s->next = (*L)->next;
			(*L)->next = s;//��ͷ���ĵ�����ͷָ��ָ���һ�����
			return true;
		}

	}
	LNode* p = GetNode(*L, i - 1);
	return InsertNextNode(p, e);
}

//ͷ�巨
bool HeadInsert(LinkList* L, ElemType e)
{
	return InsertList(L, 1, e);//�ڵ�һ��λ�ò���
}

//�ݹ����
void Print_L(LinkList L)
{
	if(L->next)
	   Print_L(L->next);
	if(L)
		printf("%3d",L->data); 
} 

//������������� 
void ReversePrint(LinkList L)
{
	if(L->next)
		 Print_L(L->next);
    printf("\n"); 
} 
 


//��ӡ������
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
	InitList(&L);
	int i = 0;
//	for (i = 0; i < 5; i++)
//		HeadInsert(&L, rand() % 20 + 1);
	//PrintList(L);
	//InsertList(L,2,15);
	//PrintList(L);
	//InsertList(L,4,20);
	//PrintList(L);
	//InsertList(L,20,100);
	//PrintList(L);
	for (i = 10; i > 0; i--)
	{
		HeadInsert(&L, i);//ͷ��
	}
	//PrintList(L);
	InsertList(&L, 1, 15);
	InsertList(&L, 1, 10);
	InsertList(&L, 5, 8);
	InsertList(&L, 5, 15);
	InsertList(&L, 7, 10);
	InsertList(&L, 7, 10);
	InsertList(&L, 15, 1);
	InsertList(&L, 10, 15);
	PrintList(L);
//	deletex(&L,10);
	ReversePrint(L);
	//PrintList(L);
	return 0;

}
