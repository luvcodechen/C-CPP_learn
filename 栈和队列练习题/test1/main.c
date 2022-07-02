#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//����㷨�ж������n���ַ��Ƿ����ĶԳ�

typedef char ElemType;

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
		printf("%5c", p->data);
		p = p->next;
	}
	printf("\n");
}
//��ȡ��������
int Listlen(LinkList L)
{
	int len = 0;
	while (L->next)
	{
		len++;
		L = L->next;
	}
	return len;
}


//����������
void swap(ElemType* a, ElemType* b)
{
	ElemType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


//ʹ������������򣬿���ð��
bool bubblesort(LinkList* L)
{
	if (!(*L)->next)
		return false;
	int len = Listlen(*L);
	while (len)
	{
		int i = len--;
		LNode* p = (*L)->next;
		LNode* q = p->next;
		while (i-- && q)
		{
			if (p->data > q->data)
				swap(&p->data, &q->data);//��ķ��ں���
			p = q;//�������
			q = q->next;
		}
	}
	return true;
}
int main()
{
	LinkList L;
	InitList(&L);
	char arr[] = {'a','b','c','c','b','a'};
	int i = 0;
	for (i = 0; i < sizeof(arr); i++)
	{
		HeadInsert(L, arr[i]);//�Զ���һ���������ڳ�ʼ��
	}
	PrintList(L);
	printf("������%d\n", Listlen(L));
	char stack[10] = {0};
	int len = Listlen(L);
	for (i = 0; i < len; i++)
	{
		LNode *s= GetNode(L, i + 1);
		stack[i] = s->data;
	}
	puts(stack);
	int j;
	int tag = 0;
	for (i = 0, j = len - 1; i <= j; i++, j--)
	{
		if (stack[i] == stack[j])
			tag = 1;
		else
			tag = 0;
	}
	if (tag)
		printf("�Գ�\n");
	return 0;

}