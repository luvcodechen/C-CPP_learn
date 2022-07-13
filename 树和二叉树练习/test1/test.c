#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
#define MAX 20
//编写非递归遍历二叉树算法

typedef char ElemType;
//二叉链表结构存储二叉树
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode* left, * right;
}BNode,*BiTree;

//初始化
void InitTree(BiTree*T)
{
	T = NULL;
}

//层次建树
bool LevelCreatTree(BiTree*T)
{
	return true;
}

//先序建树
bool preCreatTree(BiTree*T)
{
	ElemType ch;
	ch = getchar();
	if (ch == ' ')
		*T = NULL;
	else {
		if(!(*T=(BNode*)calloc(1,sizeof(BNode))))
			return false;
		(*T)->data = ch;
		preCreatTree(&(*T)->left);
		preCreatTree(&(*T)->right);
		}
	return true;
}
//先序遍历
void preorderTraverse(BiTree T)
{
	if (T)
	{
		putchar(T->data);
		preorderTraverse(T->left);
		preorderTraverse(T->right);
	}
}
//中序遍历二叉树
void InorderTraverse(BiTree T)
{
	if (T)
	{
		InorderTraverse(T->left);
		putchar(T->data);
		InorderTraverse(T->right);
	}
}
//后序遍历二叉树
void postorderTraverse(BiTree T)
{
	if (T)
	{
		postorderTraverse(T->left);
		postorderTraverse(T->right);
		putchar(T->data);
	}
}
//辅助栈用于非递归遍历二叉树
typedef struct node
{
	BiTree data[MAX];
	int top;
}Stack;
void InitStack(Stack *S)
{
	S->top = -1;
}
//入栈
bool PUSH(Stack *S,BiTree T)
{
	if (S->top == MAX - 1)
		return false;
	S->data[++S->top] = T;
	return true;
}
//弹栈
bool POP(Stack *S,BiTree *T)
{
	if (S->top == -1)
		return false;
	*T = S->data[S->top--];
	return true;
}
//判栈空
bool EmptyStack(Stack S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}
//获取栈顶元素
void GetTop(Stack S,BiTree*T)
{
	*T = S.data[S.top];
}
//后序遍历二叉树（非递归）
void postTraverse(BiTree T) 
{
	Stack S;
	InitStack(&S);
	BiTree p = T, r = NULL;
	while (p||!EmptyStack(S))
	{
		if (p)//走到最左边
		{
			PUSH(&S, p);
			p = p->left;
		}//if
		else//向右
		{
			GetTop(S, &p);//获取栈顶元素，非出栈
			if (p->right && p->right != r)//若右子树存在且未访问过
			{
				p = p->right;//向右
			}//if
			else//否则弹栈访问
			{
				POP(&S, &p);
				putchar(p->data);
				r = p;//记录最近访问的结点
				p = NULL;//访问结束，重置p
			}//else
		}//else
	}//while
}
int main()
{
	BiTree T;
	InitTree(&T);
	preCreatTree(&T);
	printf("\n先序遍历：");
	preorderTraverse(T);
	printf("\n中序遍历：");
	InorderTraverse(T);
	printf("\n后序遍历：");
	postorderTraverse(T);
	printf("\n后序遍历非递归：");
	postTraverse(T);
	return 0;
}