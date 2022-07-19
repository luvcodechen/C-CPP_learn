#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
#define  MAXNUM(a,b) ((a)>(b)?(a):(b))
//����㷨�������������������˫��֧�ڵ�ĸ���


#define MAX 20
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
	*T = NULL;
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

//�������߶�
int  DepthTree(BiTree T)
{
	return T == NULL ? 0 : MAXNUM(DepthTree(T->left), DepthTree(T->right)) + 1;
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
//������������
BNode* swap(BiTree T)
{
	if (T)
	{
		BNode* tmp;
		tmp = T->left;
		T->left = T->right;
		T->right = tmp;
		T->right = swap(T->right);
		T->left = swap(T->left);
		return T;
	}
	return T;
}

//���������˴�ʹ��˳��ӷ������������ɿռ��˷ѣ�
void levelCreat(BiTree* T)
{
	BiTree Q[MAX] = { NULL };//��������
	int front, rear;//��ͷ��βָ��
	front = rear = 0;
	ElemType c;
	BiTree new = NULL;
	while (scanf("%c", &c) != EOF)
	{
		if ('\n' == c)
			break;
		new = (BNode*)calloc(1, sizeof(BNode));//�½��
		if (new)
			new->data = c;
		if (*T == NULL)//������Ϊ�գ���һ������Ľ��ֵ��Ϊ����
		{
			*T = new;
			Q[rear++] = new;//���
			continue;
		}
		if (Q[front]->left == NULL)//�½ڵ�Ӷ�ͷ�������ҿ�λ����
			Q[front]->left = new;
		else if (Q[front]->right == NULL)//���Ӳ������Һ���
			Q[front]->right = new;
		else//����һ����㣬��ͷָ�����
			Q[++front]->left = new;
		Q[rear++] = new;//�½ڵ����
	}
}

//��ͨ��α���
void leveltravese(BiTree T)
{
	if (!T)
		return;
	BiTree Q[MAX] = { NULL };//��Ҫ��������
	int front, rear;
	front = rear = 0;
	Q[rear++] = T;
	BNode* p;//��ʱ����
	while (front < rear)
	{
		p = Q[front++];
		printf("%c", p->data);
		if (p->left)
			Q[rear++] = p->left;
		if (p->right)
			Q[rear++] = p->right;
	}
}
//����˫��֧�ڵ�ĸ���
int doublenode(BiTree T)
{
	if (T == NULL)
		return 0;
	if (T->left && T->right)
		return doublenode(T->left) + doublenode(T->right) + 1;
	else
		return doublenode(T->left) + doublenode(T->right);
}

int main()
{
	BiTree T;
	InitTree(&T);
	preCreatTree(&T);//������
	//levelCreat(&T);//������
	printf("\n���������");
	preorderTraverse(T);
	printf("\n���������");
	InorderTraverse(T);
	printf("\n���������");
	postorderTraverse(T);
	printf("\n���������");
	leveltravese(T);
	printf("\n�������߶�:");
	printf("%d", DepthTree(T));
	//printf("\n��������������");
	//T = swap(T);
	//printf("\n���������");
	//preorderTraverse(T);
	//printf("\n���������");
	//InorderTraverse(T);
	//printf("\n���������");
	//postorderTraverse(T);
	int num = doublenode(T);
	printf("\n˫��֧�ڵ������%d", num);

	return 0;
}