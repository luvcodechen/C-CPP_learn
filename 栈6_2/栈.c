#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>
typedef int ElemType;
#define MAXSIZE 50

//顺序栈的抽象数据类型定义
typedef struct stack
{
	ElemType data[MAXSIZE];//创键结构体，栈
	int top;
}SqStack;

//栈的初始化
void IninStack(SqStack *S)
{
	S->top = -1;
}

//栈是否为空
bool IsEmpty(SqStack S)
{
	if (-1 == S.top)
	{
		return true;
	}
	return false;
}
//压栈
bool Push(SqStack *S,ElemType e)
{
	if (MAXSIZE - 1 == S->top)//若栈满，则返回false
	{
		return false;
	}
	S->data[++S->top] = e;
	return true;	
}
//弹栈
bool Pop(SqStack *S,ElemType *e)
{
	if (S->top == -1)
	{
		return false;
	}
	*e = S->data[S->top--];
	return true;
}
//读栈顶元素
bool GetTop(SqStack S,ElemType *e)
{
	if (-1 == S.top)
	{
		return false;
	}
	*e = S.data[S.top];
	return true;
}
//输出栈中第i个元素
bool visit(SqStack S,int i)
{
	if (IsEmpty(S))
	{
		return false;
	}
	printf("%-3d",S.data[i]);
}
//依次从栈底到栈顶打印栈
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

//数制转换
void Conversion(int n,int x)
{
	SqStack St;
	ElemType e = 0;
	IninStack(&St);
	while (n)
	{
		Push(&St,n%x);//当n不为0.将n对x取模压栈
		n = n / x;//n取为n除以x的商
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
		printf("栈为空\n");
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
	//输入一个十进制数，将其转化成x(8或者2或者16)进制
	int n = 0, x = 0;
	printf("请输入一个十进制非负整数，和要转化的进制\n");
	int j=scanf("%d %d", &n, &x);
	Conversion(n,x);//进制转换



	return 0;
}