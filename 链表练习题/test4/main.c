#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//��д�㷨���ڴ�ͷ���ĵ�����L��ɾ��һ����Сֵ��㣨������СֵΨһ��

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

//ɾ������������С��㣬��������С���Ψһ��
bool DeleteMiniElem(LinkList *L,ElemType *elem)
{
	if ((*L)->next == NULL)
		return false;//L�ǿձ�
	LNode* now = (*L)->next;//��¼��ǰ�������Ľ��
	LNode* min = (*L)->next;//��¼�������Ľ���е���Сֵ���
	LNode* prenow = *L;//��¼��ǰ����ǰ��
	LNode* premin = *L;//��¼��С����ǰ��
	elem = min->data;//�ٶ���һ����С
	while (now)
	{	
		if (now->next&&now->next->data < elem)
		{
			premin = now;
			min = now->next;
			elem = min->data;
		}
		prenow = now;
		now = now->next;

	}
	premin->next = min->next;
	free(min);
	return true;
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
	LinkList L;
	//ElemType elem;
	//DeleteMiniElem(&L,&elem);
	InitList(&L);
	int arr[] = {7,81,12,61,52,48,25,1,21,15};
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		HeadInsert(&L, arr[i]);//�Զ���һ���������ڳ�ʼ��
	}
	PrintList(L);
	ElemType elem;
	DeleteMiniElem(&L,&elem);
	PrintList(L);
	return 0;

}