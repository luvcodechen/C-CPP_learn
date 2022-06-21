#include "function.h"

//Õ»µÄ³õÊ¼»¯
void IninStack(SqStack* S)
{
	S->top = -1;
}

//Õ»ÊÇ·ñÎª¿Õ
bool StackEmpty(SqStack S)
{
	if (-1 == S.top)
	{
		return true;
	}
	return false;
}
//Ñ¹Õ»
bool Push(SqStack* S, ElemType e)
{
	if (MaxSize - 1 == S->top)//ÈôÕ»Âú£¬Ôò·µ»Øfalse
	{
		return false;
	}
	S->data[++S->top] = e;
	return true;
}
//µ¯Õ»
bool Pop(SqStack* S, ElemType* e)
{
	if (S->top == -1)
	{
		return false;
	}
	*e = S->data[S->top--];
	return true;
}
//¶ÁÕ»¶¥ÔªËØ
bool GetTop(SqStack S, ElemType* e)
{
	if (-1 == S.top)
	{
		return false;
	}
	*e = S.data[S.top];
	return true;
}

