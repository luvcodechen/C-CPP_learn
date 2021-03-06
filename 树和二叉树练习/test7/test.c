#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
#define  MAXNUM(a,b) ((a)>(b)?(a):(b))
//判断一棵二叉树是否是完全二叉树


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
//逆置层次遍历
void Revsrseleveltravese(BiTree T)
{
	if (!T)
		return;
	BiTree Q[MAX] = { NULL };//需要辅助队列
	ElemType S[MAX] = { 0 };//辅助栈
	int top = -1;
	int front, rear;
	front = rear = 0;
	Q[rear++] = T;
	BNode* p;//临时存结点
	while (front < rear)
	{
		p = Q[front++];
		S[++top] = p->data;
		if (p->left)
			Q[rear++] = p->left;
		if (p->right)
			Q[rear++] = p->right;
	}
	while (top != -1)
		printf("%c", S[top--]);

}

int count = 0;//设置一个全局变量，省去函数中传参
void pretraverse(BiTree T, int k, ElemType* data)//用先序遍历递归的算法改进求得第k个数据
{
	if (T && k != count)
	{
		count++;
		if (count == k)//访问到第k个结点
			*data = T->data;
		pretraverse(T->left, k, data);
		pretraverse(T->right, k, data);
	}
}
//求先序遍历序列第k（节点个数>k>1）个结点的值
ElemType Getelem(BiTree T, int k)
{
	ElemType data;
	pretraverse(T, k, &data);
	return data;
}

//判断二叉树是否是完全二叉树，借助层序遍历的思想
bool  CBTree(BiTree T)
{
	if (T == NULL)
		return true;//空数也是完全二叉树
	BiTree Q[MAX] = { NULL };//需要辅助队列
	int front, rear;
	front = rear = 0;
	Q[rear++] = T;
	BNode* p;//临时存结点
	while (front < rear)
	{
		p = Q[front++];//队头出队
		if (p)//左右孩子入队
		{
			Q[rear++] = p->left;
			Q[rear++] = p->right;
		}
		else//若出队元素为空指针进入循环
		{
			while (front < rear)//只需要从队列后一个开始找队中是否有非空指针
			{
				p = Q[front++];
				if (p)
					return false;
			}
		}
	}
	return true;
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
	printf("\n逆转层序遍历遍历：");
	Revsrseleveltravese(T);
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
	//ElemType data = Getelem(T, 5);
	//printf("\n先序遍历第5个为：%c", data);
	if (CBTree(T))
		printf("\n是完全二叉树");
	else
		printf("\n不是完全二叉树");
	return 0;
}