#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>

#define MAXSIZE 5
typedef int ElemType;
//循环队列的抽象数据类型定义
typedef struct
{
	ElemType data[MAXSIZE];
	int front, rear;
}Queue;

//判断队列为空
bool IsEmpty(Queue Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;
}
//初始化循环队列
void InitQueue(Queue *Q)
{
	Q->front = Q->rear = 0;
}

//判断队列是否满
bool QueueFull(Queue Q)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front )//队列满的条件
	{
		return true;
	}
	return false;
}
//入队
bool EnQueue(Queue* Q, ElemType e)
{
	if (QueueFull(*Q))
	{
		return false;//若队满则报错
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return true;
}
//出队
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
//返回队列的元素个数
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
		printf("队列为空\n");
	}
	EnQueue(&Q,15);
	EnQueue(&Q,12);
	EnQueue(&Q,20);
	EnQueue(&Q,20);
	printf("%d\n", QueueFull(Q));
	if (!                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       EnQueue(&Q, 20))
	{
		printf("入队失败\n");
	}
	printf("%d\n", QueueLength(Q));

	return 0;
}