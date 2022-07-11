#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//Q��һ�����У�S��һ����ջ��ʵ�ֽ������е�Ԫ������
typedef int ElemType;
#define MAXSIZE 11

//ѭ������
typedef  struct queue
{
	ElemType data[MAXSIZE];//Ԥ����λ������
	int front, rear;
}Squeue;

//˳��ջ
typedef struct Stack
{
	ElemType data[MAXSIZE];
	int top;
}Stack;

//��ʼ������
void InitQueue(Squeue *Q)
{
	Q->front = Q->rear = 0;
}

//��ʼ��ջ
void InitStack(Stack *S)
{
	S->top = -1;
}

//���
bool EnQueue(Squeue*Q,ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return false;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return true;
}
//����
bool DeQueue(Squeue* Q, ElemType* e)
{
	if (Q->rear == Q->front)
		return false;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return true;
}
//��ջ
bool Push(Stack *S,ElemType e)
{
	if (S->top == (MAXSIZE - 1))
		return false;
	S->data[++S->top] = e;
	return true;
}
//��ջ
bool Pop(Stack *S,ElemType*e)
{
	if (S->top == -1)
		return false;
	*e = S->data[S->top--];
	return true;
}
//���ض��е�Ԫ�ظ���
int QueueLength(Squeue Q)
{
	return (Q.rear + MAXSIZE - Q.front) % MAXSIZE;
}
//��ӡ
void PrintQueue(Squeue Q)
{
	if (Q.front == Q.rear)
		return;
	int i = QueueLength(Q);
	for (; i; i--)
	{
		printf("%3d", Q.data[Q.front]);
		Q.front = (Q.front + 1) % MAXSIZE;
	}
	printf("\n");
}
//���ö���Ԫ��
bool ReverseQueue(Squeue *Q,Stack *S)
{
	int len = QueueLength(*Q);
	if (!len)
		return false;
	if (S->top != -1)
		return false;
	ElemType e;
	int i = len;
	for (; i; i--)
	{
		DeQueue(Q, &e);
		Push(S,e);
	}
	for (i = len; i; i--)
	{
		Pop(S,&e);
		EnQueue(Q, e);
	}
	return true;
}
int main() 
{
	Squeue Q;
	Stack S;
	InitQueue(&Q);
	InitStack(&S);
	srand((unsigned int)(time(NULL)));
	for (int i = 1; i <= MAXSIZE; i++)
		EnQueue(&Q, rand()%10+1);
	PrintQueue(Q);
	ReverseQueue(&Q,&S);
	PrintQueue(Q);
	return 0;
}