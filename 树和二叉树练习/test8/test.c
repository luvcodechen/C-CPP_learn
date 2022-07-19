#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
#define  MAXNUM(a,b) ((a)>(b)?(a):(b))
//设计算法计算给定二叉树的所有双分支节点的个数


#define MAX 20
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
	*T = NULL;
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

//二叉树高度
int  DepthTree(BiTree T)
{
	return T == NULL ? 0 : MAXNUM(DepthTree(T->left), DepthTree(T->right)) + 1;
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
//交换左右子树
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

//层序建树（此处使用顺序队方便操作，会造成空间浪费）
void levelCreat(BiTree* T)
{
	BiTree Q[MAX] = { NULL };//辅助队列
	int front, rear;//队头队尾指针
	front = rear = 0;
	ElemType c;
	BiTree new = NULL;
	while (scanf("%c", &c) != EOF)
	{
		if ('\n' == c)
			break;
		new = (BNode*)calloc(1, sizeof(BNode));//新结点
		if (new)
			new->data = c;
		if (*T == NULL)//若树根为空，第一个输入的结点值作为树根
		{
			*T = new;
			Q[rear++] = new;//入队
			continue;
		}
		if (Q[front]->left == NULL)//新节点从队头的左孩子找空位插入
			Q[front]->left = new;
		else if (Q[front]->right == NULL)//左孩子不空找右孩子
			Q[front]->right = new;
		else//找下一个结点，队头指针后移
			Q[++front]->left = new;
		Q[rear++] = new;//新节点入队
	}
}

//普通层次遍历
void leveltravese(BiTree T)
{
	if (!T)
		return;
	BiTree Q[MAX] = { NULL };//需要辅助队列
	int front, rear;
	front = rear = 0;
	Q[rear++] = T;
	BNode* p;//临时存结点
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
//计算双分支节点的个数
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
	preCreatTree(&T);//先序建树
	//levelCreat(&T);//层序建树
	printf("\n先序遍历：");
	preorderTraverse(T);
	printf("\n中序遍历：");
	InorderTraverse(T);
	printf("\n后序遍历：");
	postorderTraverse(T);
	printf("\n层序遍历：");
	leveltravese(T);
	printf("\n二叉树高度:");
	printf("%d", DepthTree(T));
	//printf("\n交换左右子树：");
	//T = swap(T);
	//printf("\n先序遍历：");
	//preorderTraverse(T);
	//printf("\n中序遍历：");
	//InorderTraverse(T);
	//printf("\n后序遍历：");
	//postorderTraverse(T);
	int num = doublenode(T);
	printf("\n双分支节点个数：%d", num);

	return 0;
}