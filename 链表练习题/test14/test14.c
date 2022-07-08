#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//AB������ͷ��㵥���������������㷨�ӹ���Ԫ�����в�������C���Ҳ��ƻ�AB�еĽ��--------14   

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
bool InsertList(LinkList L, int i, ElemType e)
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
			s->next = L->next;
			L->next = s;//��ͷ���ĵ�����ͷָ��ָ���һ�����
			return true;
		}

	}
	LNode* p = GetNode(L, i - 1);
	return InsertNextNode(p, e);
}

//ͷ�巨
bool HeadInsert(LinkList L, ElemType e)
{
	return InsertList(L, 1, e);//�ڵ�һ��λ�ò���
}


//��ӡ������
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
//��ȡ��������
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
//��������Ϊ�ձ�
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
//��ȡ����Ԫ�ز����±�
LinkList ExactList(LinkList  La, LinkList Lb)
{
	LinkList Lc;
	InitList(&Lc);
	LNode* pa = La->next, * pb = Lb->next, * pc = Lc;
	while (pa && pb)
	{
		if (pa->data < pb->data)
			pa = pa->next;
		else if (pa->data > pb->data)
			pb = pb->next;
		else
		{
			LNode* s = (LNode*)calloc(1, sizeof(LNode));
			if (s)
				s->data = pa->data;
			else
				return NULL;
			pc->next = s;
			pc = s;
			pa = pa->next;
			pb = pb->next;
		}
	}
	pc->next = NULL;
	return Lc;
}

int main()
{
	LinkList L;
	LinkList Lb;
	InitList(&L);
	InitList(&Lb);
	int arr[] = { 22,20,14,10,9,7,5,3,1 };
	int arrb[] = { 19,18,17,16,15,14,13,11,3 };
	int i = 0;
	for (i = 0; i < sizeof(arr) / 4; i++)
	{
		HeadInsert(L, arr[i]);//�Զ���һ���������ڳ�ʼ��
		HeadInsert(Lb, arrb[i]);//�Զ���һ���������ڳ�ʼ��
	}
	PrintList(L);
	printf("����L��%d\n", Listlen(L));
	PrintList(Lb);
	printf("����Lb��%d\n", Listlen(Lb));
	LinkList Lc = ExactList(L,Lb);
	PrintList(Lc);
	printf("����Lc��%d\n", Listlen(Lc));
	PrintList(L);
	printf("����L��%d\n", Listlen(L));
	PrintList(Lb);
	printf("����Lb��%d\n", Listlen(Lb));
	return 0;

}