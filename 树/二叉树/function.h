#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define OVERFOLW 0;

#define _CRT_SECURE_NO_WARNINGS

typedef char BiElemType;
//���������ĳ�����������
typedef struct BiTNode
{
	BiElemType data;//������
	struct BiTNode* lchild, * rchild;//���ӡ��Һ���ָ����
}BiTNode, * BiTree;


typedef struct tag
{
	BiTree p;//����ĳһ�����ĵ�ֵַ
	struct tag* pnext;
}tag_t,*ptag_t;

//ջ������������Ͷ���

#define MaxSize 50
typedef BiTree ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;
void IninStack(SqStack * S);
bool StackEmpty(SqStack S);
//ѹջ
bool Push(SqStack* S, ElemType e);
//��ջ
bool Pop(SqStack* S, ElemType* e);
//��ջ��Ԫ��
bool GetTop(SqStack S, ElemType* e);

//�����еĳ����������Ͷ���
//����Ľڵ�ṹ
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

//���е�����ṹ
typedef struct
{
	QueuePtr front, rear;//��ͷ����βָ��
}LinkQueue;
//�����еĳ�ʼ�����ն���
bool InitQueue(LinkQueue* Q);
//�ж��Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q);
//���
bool EnQueue(LinkQueue* Q, ElemType e);
//����
bool DeQueue(LinkQueue* Q, ElemType* e);

