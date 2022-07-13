#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
#define MAX 20
//��д�ǵݹ�����������㷨

typedef char ElemType;
//��������ṹ�洢������
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode* left, * right;
}BNode,*BiTree;

//��ʼ��
void InitTree(BiTree*T)
{
	T = NULL;
}

//��ν���
bool LevelCreatTree(BiTree*T)
{
	return true;
}

//������
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
//����ջ���ڷǵݹ����������
typedef struct node
{
	BiTree data[MAX];
	int top;
}Stack;
void InitStack(Stack *S)
{
	S->top = -1;
}
//��ջ
bool PUSH(Stack *S,BiTree T)
{
	if (S->top == MAX - 1)
		return false;
	S->data[++S->top] = T;
	return true;
}
//��ջ
bool POP(Stack *S,BiTree *T)
{
	if (S->top == -1)
		return false;
	*T = S->data[S->top--];
	return true;
}
//��ջ��
bool EmptyStack(Stack S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}
//��ȡջ��Ԫ��
void GetTop(Stack S,BiTree*T)
{
	*T = S.data[S.top];
}
//����������������ǵݹ飩
void postTraverse(BiTree T) 
{
	Stack S;
	InitStack(&S);
	BiTree p = T, r = NULL;
	while (p||!EmptyStack(S))
	{
		if (p)//�ߵ������
		{
			PUSH(&S, p);
			p = p->left;
		}//if
		else//����
		{
			GetTop(S, &p);//��ȡջ��Ԫ�أ��ǳ�ջ
			if (p->right && p->right != r)//��������������δ���ʹ�
			{
				p = p->right;//����
			}//if
			else//����ջ����
			{
				POP(&S, &p);
				putchar(p->data);
				r = p;//��¼������ʵĽ��
				p = NULL;//���ʽ���������p
			}//else
		}//else
	}//while
}
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
	printf("\n��������ǵݹ飺");
	postTraverse(T);
	return 0;
}