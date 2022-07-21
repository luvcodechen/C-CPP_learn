#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define Isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
#define  MAXNUM(a,b) ((a)>(b)?(a):(b))
//在二叉树中查找值为x的结点，编写算法打印x的所有祖先，假设x的值不多于一个
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
//打印值为x的结点的全部祖先节点，根据后序遍历非递归的算法，当要访问某个结点时栈内为全部祖先
void x_parent(BiTree T,ElemType x)
{
	BNode* p = T;
	BNode* r = NULL;//标记
	BiTree s[MAX];//辅助栈
	int top = -1;//栈顶指针
	while (p || top != -1)
	{
		if (p)
		{
			if (p->data == x)//访问到目标节点，此时该结点祖先存在栈中
				break;
			s[++top] = p;//根节点进栈
			p = p->left;//左孩子进栈
		}
		else//到达最左节点
		{
			p = s[top];//获取栈顶元素
			if (p->right&&p->right!=r)//若右子树存在且未遍历过则转向右
				p = p->right;
			else 
			{
				top--;//弹出栈顶元素
				r = p;//记录此节点
				p = NULL;
			}

		}
	}
	while (top != -1)
		printf("%c", s[top--]->data);
}
int main()
{
	BiTree T;
	InitTree(&T);
	//preCreatTree(&T);//先序建树
	//levelCreat(&T);//层序建树
	ElemType A[] = "abdefgc";//先序序列
	ElemType B[] = "dbfegac";//中序序列
	int len = strlen(A);
	T = pre_ordercreate(A, B, 0, 0, len);//根据先中序序列建树
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
	char c = 'd';
	x_parent(T, c);
	return 0;
}