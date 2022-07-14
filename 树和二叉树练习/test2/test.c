#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
#define MAX 20
//���һ���ǵݹ��㷨��������ĸ߶�

typedef char ElemType;
//��������ṹ�洢������
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode* left, * right;
}BNode, * BiTree;

//��ʼ��
void InitTree(BiTree* T)
{
	T = NULL;
}
//������
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
//�������
void preorderTraverse(BiTree T)
{
	if (T)
	{
		putchar(T->data);
		preorderTraverse(T->left);
		preorderTraverse(T->right);
	}
}
//�������������
void InorderTraverse(BiTree T)
{
	if (T)
	{
		InorderTraverse(T->left);
		putchar(T->data);
		InorderTraverse(T->right);
	}
}
//�������������
void postorderTraverse(BiTree T)
{
	if (T)
	{
		postorderTraverse(T->left);
		postorderTraverse(T->right);
		putchar(T->data);
	}
}
//�ǵݹ���������ĸ߶�
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
////������������
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
////������������
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
	printf("\n���������");
	preorderTraverse(T);
	printf("\n���������");
	InorderTraverse(T);
	printf("\n���������");
	postorderTraverse(T);
	printf("\n�������߶�:");
	printf("%d", DepthTree(T));
	//printf("\n��������������");
	//T=swap(T);
	//printf("\n���������");
	//preorderTraverse(T);
	//printf("\n���������");
	//InorderTraverse(T);
	//printf("\n���������");
	//postorderTraverse(T);

	return 0;
}