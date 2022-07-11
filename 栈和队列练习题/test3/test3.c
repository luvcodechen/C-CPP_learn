#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//Q是一个队列，S是一个空栈，实现将队列中的元素逆置
typedef int ElemType;
#define MAXSIZE 11

//循环队列
typedef  struct queue
{
	ElemType data[MAXSIZE];//预留空位置判满
	int front, rear;
}Squeue;

//顺序栈
typedef struct Stack
{
	ElemType data[MAXSIZE];
	int top;
}Stack;

//初始化队列
void InitQueue(Squeue *Q)
{
	Q->front = Q->rear = 0;
}

//初始化栈
void InitStack(Stack *S)
{
	S->top = -1;
}

//入队
bool EnQueue(Squeue*Q,ElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return false;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return true;
}
//出队
bool DeQueue(Squeue* Q, ElemType* e)
{
	if (Q->rear == Q->front)
		return false;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return true;
}
//进栈
bool Push(Stack *S,ElemType e)
{
	if (S->top == (MAXSIZE - 1))
		return false;
	S->data[++S->top] = e;
	return true;
}
//弹栈
bool Pop(Stack *S,ElemType*e)
{
	if (S->top == -1)
		return false;
	*e = S->data[S->top--];
	return true;
}
//返回队列的元素个数
int QueueLength(Squeue Q)
{
	return (Q.rear + MAXSIZE - Q.front) % MAXSIZE;
}
//打印
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
//逆置队列元素
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