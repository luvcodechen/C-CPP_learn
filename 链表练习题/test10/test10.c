#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//��c{a1,b1a2,b2����������an,bn}���ô�ͷ���������ţ����Ϊ��������A{a1,a2������an},B{bn,b(n-1),������b1}��--------11    

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

//��ֵ�����{a1,b1a2,b2����������an,bn}Ϊ��������A{a1,a2������an},B{bn,b(n-1),������b1}
bool SplitList(LinkList La, LinkList Lb)
{
	LNode* ra = La->next;
	LNode* s;
	int i = 20;//��Ŀ�Ѹ�nҲ����������Ϊ2n��ż���������һ��
	while (i)
	{
		i-=2;
		s = ra->next; ra->next = s->next; ra = s->next;//������bȡ����
		s->next = Lb->next; Lb->next = s;//ͷ�����±��Ｔ������
	}
	return true;
}

int main()
{
	LinkList L;
	InitList(&L);
	int arr[] = { 20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
	int i = 0;
	for (i = 0; i < sizeof(arr) / 4; i++)
	{
		HeadInsert(L, arr[i]);//�Զ���һ���������ڳ�ʼ��
	}
	PrintList(L);
	printf("������%d\n", Listlen(L));
	LinkList LB;
	InitList(&LB);
	SplitList(L, LB);
	printf("���Ѻ�\n");
	PrintList(L);
	PrintList(LB);

	return 0;

}