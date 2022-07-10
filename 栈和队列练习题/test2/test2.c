#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//ϣ��ѭ������������Ԫ�ض��õ����ã�����һ��tag��־ ����tagΪ0����1�����ֶ�ͷָ��Ͷ�βָ���غ��ǿջ�ջ��

typedef int ElemType;
#define MAXSIZE 5

//˳��洢ѭ�����г�����������
typedef  struct queue
{
	ElemType data[MAXSIZE];
	int front, rear;
	int tag;
}Squeue;

//���г�ʼ��
void InitQueue(Squeue *q)
{
	q->front = q->rear = q->tag = 0;
}
//���
bool EnQueue(Squeue *q,ElemType e) 
{
	if (q->tag == 1)
		return false;//tagΪ1��ʾ������
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
	if (q->rear == q->front)
		q->tag = 1;
	else
		q->tag = -1;//��Ϊ����ˣ����в��գ�tag����Ϊ0
	return true;
}

//����
bool DeQueue(Squeue* q, ElemType *e)
{
	if (q->tag == 0)
		return false;//���пգ�����ʧ��
	*e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	if (q->front == q->rear)
		q->tag = 0;//����Ҫô��
	else
		q->tag = -1;//Ҫô����
	return true;
}
//�������
void PrintQueue(Squeue q)
{
	if (q.tag == 1)//���������ʹ�front��ʼ���ȫ��Ԫ��
		for (int i = 0; i < MAXSIZE; i++, q.front = (q.front + 1) % MAXSIZE)
			printf("%3d", q.data[q.front]);
	else if (q.front != q.rear)//��������ʹ�front��ʼ�����rear
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
		printf("���ӳɹ���elem=%d\n", elem);
	else
		printf("����ʧ��\n");
	PrintQueue(q);
	return 0;
}
