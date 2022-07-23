#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
//中序线索二叉树
#define MAX 20
typedef char ElemType;
//线索二叉树的存储结构
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode* left, * right;
	bool ltag, rtag;
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
	return T == NULL ? 0 : fmax(DepthTree(T->left), DepthTree(T->right)) + 1;
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
//销毁二叉树
void DestroyBiTree(BiTree* T)
{
	if (*T)
	{
		DestroyBiTree(&(*T)->left); /* 销毁左孩子子树 */
		DestroyBiTree(&(*T)->right); /* 销毁右孩子子树 */
		free(*T); /* 释放根结点 */
		*T = NULL; /* 空指针赋0 */
	}
}
//根据先序和中序序列建树,A、B分别存储前序和中序序列，pre、mid分别是前序和中序开始遍历的位置，n为树的结点个数
BiTree pre_ordercreate(ElemType* A, ElemType* B, int pre, int mid, int n)
{
	if (n == 0)
		return NULL;
	BiTree p = (BNode*)calloc(1, sizeof(BNode));
	if (!p)
		return NULL;
	p->data = A[pre];
	int i = 0;
	for (i = 0; B[mid + i] != A[pre]; i++);//根节点在中序遍历中的位置
	p->left = pre_ordercreate(A, B, pre + 1, mid, i);//递归建立左子树
	p->right = pre_ordercreate(A, B, pre + i + 1, mid + i + 1, n - i - 1);//递归建立右子树
	return p;

}
//求二叉树的宽度，考虑广度优先遍历帮助实现 
int treewidth(BiTree T)
{
	if (T == NULL)
		return 0;
	BiTree q[MAX];//辅助队列
	int front, rear;//队头队尾指针
	front = rear = -1;
	BNode* p;
	q[++rear] = T;
	int last = 0;//指示每一层最后一个结点
	int i = 0, width = 0;//width记录每一层宽度，i记录每一层第一个结点
	while (front < rear)
	{
		p = q[++front];
		if (p->left)
			q[++rear] = p->left;//左孩子入队
		if (p->right)
			q[++rear] = p->right;//右孩子入队
		if (front == last)
		{
			width = fmax(last - i + 1, width);
			last = rear;//更新下层最后结点位置
			i = front + 1;//更新下层第一个结点位置
		}
	}
	return width;
}
//中序递归线索化
void InThread(BiTree T,BNode**pre)
{
	if (T)
	{
		InThread(T->left, pre);//递归线索左子树
		if (T->left == NULL)//左子树为空，建立前驱线索
		{

			T->left = *pre;
			T->ltag = 1;
		}
		if (*pre != NULL&&(*pre)->right == NULL  )//建立前驱结点的后继线索
		{
			(* pre)->right = T;
			(* pre)->rtag = 1;
		}
		*pre = T;//标记当前结点成为刚刚访问的结点
		InThread(T->right, pre);//递归线索右子树
	}
}
//中序线索二叉树
void creatInThraed(BiTree T)
{
	BNode* pre = NULL;
	if (T)
	{
		InThread(T, &pre);//非空二叉树，线索化
		pre->right = NULL;//处理遍历到的最后一个结点
		pre->rtag = 1;
	}
}
//求中序线索二叉树的第一个结点if
BNode* FIRSTNode(BiTree T)
{
	while (T->ltag == 0)
		T = T->left;
	return T;
}
//返回中序线索树某个结点的后继结点
BNode* NextNode(BNode *p)
{
	if (p->rtag == 0)
		return FIRSTNode(p->right);
	else
		return p->right;
}
//中序线索二叉树的中序遍历
void Inorder(BiTree T) 
{
	for (BNode* p = FIRSTNode(T); p != NULL; p = NextNode(p))
		putchar(p->data);
}
int main()
{
	BiTree T;
	//BiTree Tb;
	InitTree(&T);
	//InitTree(&Tb);
	preCreatTree(&T);//先序建树
	//printf("建立第一棵树：");
	//levelCreat(&T);//层序建树
	//printf("建立第二棵树：");
	//levelCreat(&Tb);//层序建树
	//ElemType A[] = "abdefgc";//先序序列
	//ElemType B[] = "dbfegac";//中序序列
	//int len = strlen(A);
	//T = pre_ordercreate(A, B, 0, 0, len);//根据先中序序列建树
	printf("先序遍历：");
	preorderTraverse(T);
	printf("\n中序遍历：");
	InorderTraverse(T);
	printf("\n后序遍历：");
	postorderTraverse(T);
	printf("\n层序遍历：");
	leveltravese(T);
	printf("\n二叉树高度:");
	printf("%d", DepthTree(T));
	printf("\n");
	int width = treewidth(T);
	printf("二叉树宽度：%d\n", width);
	creatInThraed(T);//中序线索化
	Inorder(T);//中序线索二叉树中序遍历

	return 0;
}