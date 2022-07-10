#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//希望循环队列中所有元素都得到利用，设置一个tag标志 ，以tag为0或者1来区分队头指针和队尾指针重合是空或栈满

typedef int ElemType;
#define MAXSIZE 5

//顺序存储循环队列抽象数据类型
typedef  struct queue
{
	ElemType data[MAXSIZE];
	int front, rear;
	int tag;
}Squeue;

//队列初始化
void InitQueue(Squeue *q)
{
	q->front = q->rear = q->tag = 0;
}
//入队
bool EnQueue(Squeue *q,ElemType e) 
{
	if (q->tag == 1)
		return false;//tag为1表示队列满
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	if (q->rear == q->front)
		q->tag = 1;
	else
		q->tag = -1;//因为入队了，队列不空，tag不能为0
	return true;
}

//出队
bool DeQueue(Squeue* q, ElemType *e)
{
	if (q->tag == 0)
		return false;//队列空，出队失败
	*e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	if (q->front == q->rear)
		q->tag = 0;//出队要么空
	else
		q->tag = -1;//要么不空
	return true;
}
//输出队列
void PrintQueue(Squeue q)
{
	if (q.tag == 1)//队列满，就从front开始输出全部元素
		for (int i = 0; i < MAXSIZE; i++, q.front = (q.front + 1) % MAXSIZE)
			printf("%3d", q.data[q.front]);
	else if (q.front != q.rear)//其他情况就从front开始输出到rear
		for (; q.front != q.rear; q.front = (q.front + 1) % MAXSIZE)
			printf("%3d", q.data[q.front]);
	printf("\n");
}
int main()
{
	Squeue q;
	ElemType elem;
	InitQueue(&q);
	EnQueue(&q,5);
	EnQueue(&q,6);
	EnQueue(&q,7);
	EnQueue(&q,8);
	EnQueue(&q,9);
	EnQueue(&q,10);
	PrintQueue(q);
	int status = DeQueue(&q,&elem);
	if (status)
		printf("出队成功，elem=%d\n", elem);
	else
		printf("出队失败\n");
	PrintQueue(q);
	return 0;
}
