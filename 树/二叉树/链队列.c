#define _CRT_SECURE_NO_WARNINGS 
#include "function.h"
//链队列的初始化，空队列
bool InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)calloc(1, sizeof(QNode));//申请空间并赋空值
	if (NULL == Q->front)
	{
		return false;
	}
	return true;

}

//入队
bool EnQueue(LinkQueue* Q, ElemType e)
{
	QueuePtr s = (QueuePtr)calloc(1, sizeof(QNode));
	if (NULL == s)
	{
		return false;
	}
	s->data = e;//因为用的callos，s的后继next指针域为空，不用再赋值
	Q->rear->next = s;//将s赋值给在原队尾结点的后继
	Q->rear = s;//队尾指针指向s
	return true;
}
//出队
bool DeQueue(LinkQueue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		return false;
	}
	QueuePtr q = Q->front->next;//取到要出队的结点
	*e = q->data;
	Q->front->next = q->next;
	if (q == Q->rear)
	{
		Q->rear = Q->front;//若出队的为最后一个元素，则rear指针指向头结点
	}
	free(q);
	return true;

}
//判断是否为空
bool IsEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}