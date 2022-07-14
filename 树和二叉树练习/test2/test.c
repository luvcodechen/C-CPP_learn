#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
#define MAX 20
//设计一个非递归算法求二叉树的高度

typedef char ElemType;
//二叉链表结构存储二叉树
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode* left, * right;
}BNode, * BiTree;

//初始化
void InitTree(BiTree* T)
{
	T = NULL;
}
//先序建树
bool preCreatTree(BiTree* T)
{
	ElemType ch;
	ch = getchar();
	if (ch == ' ')
		*T = NULL;
	else {
		if (!(*T = (BNode*)calloc(1, sizeof(BNode))))
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
//非递归求二叉树的高度
int DepthTree(BiTree T)
{
	if (!T)
		return 0;
	BiTree Q[20];
	int front = -1, rear = -1;
	int level = 0, last = 0;
	Q[++rear] = T;
	BNode* p;
	while (front < rear)
	{
		p = Q[++front];
		if (p->left)
			Q[++rear] = p->left;
		if (p->right)
			Q[++rear] = p->right;
		if (front == last)
		{
			level++;
			last = rear;
		}
	}
	return level;
}
////交换左右子树
//void swap(BiTree T)
//{
//	if (T)
//	{
//		swap(T->left);
//		swap(T->right);
//		BNode* p = T->left;
//		T->left = T->right;
//		T->right = p;
//	}
//}
////交换左右子树
//BNode* swap(BiTree T)
//{
//	if (T)
//	{
//		BNode* tmp;
//		tmp = T->left;
//		T->left = T->right;
//		T->right = tmp;
//		T->right = swap(T->right);
//		T->left = swap(T->left);
//		return T;
//	}
//	return T;
//}
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
	printf("\n二叉树高度:");
	printf("%d", DepthTree(T));
	//printf("\n交换左右子树：");
	//T=swap(T);
	//printf("\n先序遍历：");
	//preorderTraverse(T);
	//printf("\n中序遍历：");
	//InorderTraverse(T);
	//printf("\n后序遍历：");
	//postorderTraverse(T);

	return 0;
}