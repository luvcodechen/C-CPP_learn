#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>

#define MAXSIZE 5
typedef int ElemType;
//ѭ�����еĳ����������Ͷ���
typedef struct
{
	ElemType data[MAXSIZE];
	int front, rear;
}Queue;

//�ж϶���Ϊ��
bool IsEmpty(Queue Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;
}
//��ʼ��ѭ������
void InitQueue(Queue *Q)
{
	Q->front = Q->rear = 0;
}

//�ж϶����Ƿ���
bool QueueFull(Queue Q)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front )//������������
	{
		return true;
	}
	return false;
}
//���
bool EnQueue(Queue* Q, ElemType e)
{
	if (QueueFull(*Q))
	{
		return false;//�������򱨴�
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return true;
}
//����
bool DeQueue(Queue *Q,ElemType *e)
{
	if (IsEmpty(*Q))
	{
		return false;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return true;
}
//���ض��е�Ԫ�ظ���
int QueueLength(Queue Q)
{
	return (Q.rear+Q.front+MAXSIZE)%MAXSIZE;
}
int main()
{
	Queue Q;
	InitQueue(&Q);
	if (IsEmpty(Q))
	{
		printf("����Ϊ��\n");
	}
	EnQueue(&Q,15);
	EnQueue(&Q,12);
	EnQueue(&Q,20);
	EnQueue(&Q,20);
	printf("%d\n", QueueFull(Q));
	if (!                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       EnQueue(&Q, 20))
	{
		printf("���ʧ��\n");
	}
	printf("%d\n", QueueLength(Q));

	return 0;
}