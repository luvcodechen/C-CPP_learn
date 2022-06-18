#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>
typedef int ElemType;
#define MAXSIZE 50

//˳��ջ�ĳ����������Ͷ���
typedef struct stack
{
	ElemType data[MAXSIZE];//�����ṹ�壬ջ
	int top;
}SqStack;

//ջ�ĳ�ʼ��
void IninStack(SqStack *S)
{
	S->top = -1;
}

//ջ�Ƿ�Ϊ��
bool IsEmpty(SqStack S)
{
	if (-1 == S.top)
	{
		return true;
	}
	return false;
}
//ѹջ
bool Push(SqStack *S,ElemType e)
{
	if (MAXSIZE - 1 == S->top)//��ջ�����򷵻�false
	{
		return false;
	}
	S->data[++S->top] = e;
	return true;	
}
//��ջ
bool Pop(SqStack *S,ElemType *e)
{
	if (S->top == -1)
	{
		return false;
	}
	*e = S->data[S->top--];
	return true;
}
//��ջ��Ԫ��
bool GetTop(SqStack S,ElemType *e)
{
	if (-1 == S.top)
	{
		return false;
	}
	*e = S.data[S.top];
	return true;
}
//���ջ�е�i��Ԫ��
bool visit(SqStack S,int i)
{
	if (IsEmpty(S))
	{
		return false;
	}
	printf("%-3d",S.data[i]);
}
//���δ�ջ�׵�ջ����ӡջ
bool StackTraverse(SqStack S)
{
	if (IsEmpty(S))
	{
		return false;
	}
	int i = 0;
	for (i = 0; i <= S.top; i++)
	{
		visit(S,i);
	}
	printf("\n");
	return true;
}

//����ת��
void Conversion(int n,int x)
{
	SqStack St;
	ElemType e = 0;
	IninStack(&St);
	while (n)
	{
		Push(&St,n%x);//��n��Ϊ0.��n��xȡģѹջ
		n = n / x;//nȡΪn����x����
	}
	while (!IsEmpty(St))
	{
		Pop(&St,&e);
		printf("%d", e);
	}

}

//
int main()
{
	SqStack S;
	bool flag=0;
	ElemType element=0;
	IninStack(&S);
	flag=IsEmpty(S);
	if (flag)
	{
		printf("ջΪ��\n");
	}
	Push(&S,3);
	Push(&S,4);
	Push(&S,5);
	GetTop(S, &element);
	Push(&S, 55);
	//Pop(&S, &element);
	visit(S,2);
	printf("\n");
	StackTraverse(S);
	//����һ��ʮ������������ת����x(8����2����16)����
	int n = 0, x = 0;
	printf("������һ��ʮ���ƷǸ���������Ҫת���Ľ���\n");
	int j=scanf("%d %d", &n, &x);
	Conversion(n,x);//����ת��



	return 0;
}