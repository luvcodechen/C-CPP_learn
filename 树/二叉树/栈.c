#include "function.h"

//ջ�ĳ�ʼ��
void IninStack(SqStack* S)
{
	S->top = -1;
}

//ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S)
{
	if (-1 == S.top)
	{
		return true;
	}
	return false;
}
//ѹջ
bool Push(SqStack* S, ElemType e)
{
	if (MaxSize - 1 == S->top)//��ջ�����򷵻�false
	{
		return false;
	}
	S->data[++S->top] = e;
	return true;
}
//��ջ
bool Pop(SqStack* S, ElemType* e)
{
	if (S->top == -1)
	{
		return false;
	}
	*e = S->data[S->top--];
	return true;
}
//��ջ��Ԫ��
bool GetTop(SqStack S, ElemType* e)
{
	if (-1 == S.top)
	{
		return false;
	}
	*e = S.data[S.top];
	return true;
}

