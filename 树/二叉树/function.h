#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define OVERFOLW 0;

#define _CRT_SECURE_NO_WARNINGS

typedef char BiElemType;
//二叉树结点的抽象数据类型
typedef struct BiTNode
{
	BiElemType data;//数据域
	struct BiTNode* lchild, * rchild;//左孩子。右孩子指针域
}BiTNode, * BiTree;


typedef struct tag
{
	BiTree p;//树的某一个结点的地址值
	struct tag* pnext;
}tag_t,*ptag_t;

//栈的相关数据类型定义

#define MaxSize 50
typedef BiTree ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;
void IninStack(SqStack * S);
bool StackEmpty(SqStack S);
//压栈
bool Push(SqStack* S, ElemType e);
//弹栈
bool Pop(SqStack* S, ElemType* e);
//读栈顶元素
bool GetTop(SqStack S, ElemType* e);

//链队列的抽象数据类型定义
//链表的节点结构
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

//队列的链表结构
typedef struct
{
	QueuePtr front, rear;//队头，队尾指针
}LinkQueue;
//链队列的初始化，空队列
bool InitQueue(LinkQueue* Q);
//判断是否为空
bool IsEmpty(LinkQueue Q);
//入队
bool EnQueue(LinkQueue* Q, ElemType e);
//出队
bool DeQueue(LinkQueue* Q, ElemType* e);

