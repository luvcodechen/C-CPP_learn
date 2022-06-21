#define _CRT_SECURE_NO_WARNINGS 
#include "function.h"
//�����еĳ�ʼ�����ն���
bool InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)calloc(1, sizeof(QNode));//����ռ䲢����ֵ
	if (NULL == Q->front)
	{
		return false;
	}
	return true;

}

//���
bool EnQueue(LinkQueue* Q, ElemType e)
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
bool DeQueue(LinkQueue* Q, ElemType* e)
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