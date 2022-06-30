#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//��ͷ��������L,����㷨ʹ���������

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
bool DeleteMiniElem(LinkList* L, ElemType* elem)
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
		if (now->next && now->next->data < elem)
		{
			premin = now;
			min = now->next;
			elem = min->data;//����min
		}
		prenow = now;//��������
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
		printf("%5d", p->data);
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
void swap(ElemType *a,ElemType *b)
{
	ElemType temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


//ʹ������������򣬿���ð��
bool bubblesort(LinkList *L)
{
	if (!(*L)->next)
		return false;
	int len = Listlen(*L);
	LNode* p = (*L)->next;
	LNode* q = p->next;
	while(len)
	{
		int i=len;
		LNode* p = (*L)->next;
		LNode* q = p->next;
		while (i&& q)
		{
			if (p->data > q->data)
				swap(&p->data, &q->data);//��ķ��ں���
			p = p->next;//�������
			q = q->next;
			i--;
		}
		len--;
	}
	return true;
}

int main()
{
	LinkList L;
	InitList(&L);
	int arr[] = { 12,152,156,61,2,48,25,15,21,15 };
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		HeadInsert(&L, arr[i]);//�Զ���һ���������ڳ�ʼ��
	}
	PrintList(L);
	//ElemType elem;
	//DeleteMiniElem(&L, &elem);//ɾ����С���
	printf("������%d\n", Listlen(L));
	int ret = bubblesort(&L);
	if (ret)
		PrintList(L);
	else
		printf("����ʧ��\n");
	return 0;

}