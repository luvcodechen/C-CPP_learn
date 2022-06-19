#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>

typedef int ElemType;
//����Ľڵ�ṹ
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QNode,*QueuePtr;

//���е�����ṹ
typedef struct
{
	QueuePtr front, rear;//��ͷ����βָ��
}LinkQueue;

//�����еĳ�ʼ�����ն���
bool InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)calloc(1, sizeof(QNode));//����ռ䲢����ֵ
	if (NULL == Q->front)
	{
		return false;
	}
	return true;

}

//���
bool EnQueue(LinkQueue *Q,ElemType e)
{
	QueuePtr s = (QueuePtr)calloc(1, sizeof(QNode));
	if (NULL == s)
	{
		return false;
	}
	s->data = e;//��Ϊ�õ�callos��s�ĺ��nextָ����Ϊ�գ������ٸ�ֵ
	Q->rear->next = s;//��s��ֵ����ԭ��β���ĺ��
	Q->rear = s;//��βָ��ָ��s
	return true;
}
//����
bool DeQueue(LinkQueue *Q,ElemType *e)
{
	if (Q->front == Q->rear)
	{
		return false;
	}
	QueuePtr q = Q->front->next;//ȡ��Ҫ���ӵĽ��
	*e = q->data;
	Q->front->next = q->next;
	if (q == Q->rear)
	{
		Q->rear = Q->front;//�����ӵ�Ϊ���һ��Ԫ�أ���rearָ��ָ��ͷ���
	}
	free(q);
	return true;

}
//�ж��Ƿ�Ϊ��
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
	return false;
}
bool visit(ElemType e)
{
	printf("%d ", e);
	return true;
}

//����еĳ���
int QueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr q = Q.front;
	while (q != Q.rear)
	{
		i++;
		q = q->next;
	}
	return i;
}

//�Ӷ�ͷ����β�������
bool QueueTraverae(LinkQueue Q)
{
	QueuePtr q = Q.front->next;
	if (!q)
	{
		return false;
	}
	while (q)
	{
		visit(q->data);
		q = q->next;
	}
	printf("\n");
	return true;
}
int main()
{
	LinkQueue Q;
	InitQueue(&Q);
	ElemType e;
	EnQueue(&Q,5);
	EnQueue(&Q,545);
	EnQueue(&Q,121);
	EnQueue(&Q,5121);
	DeQueue(&Q,&e);
	printf("%d\n", QueueLength(Q));
	QueueTraverae(Q);
	return 0;
}