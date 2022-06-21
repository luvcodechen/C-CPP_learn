#define _CRT_SECURE_NO_WARNINGS

#include "function.h"
//先序遍历
void preorder(BiTree T)
{
	if (T != NULL)
	{
		putchar(T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}//中序遍历
void inorder(BiTree T)
{
	if (T != NULL)
	{		
		inorder(T->lchild);
		putchar(T->data);
		inorder(T->rchild);
	}
}
//非递归中序遍历
void inorder2(BiTree T)
{
	SqStack S;
	IninStack(&S);
	BiTree p = T;
	while (p || !StackEmpty(S))
	{
		if (p)
		{
			Push(&S, p);
			p = p->lchild;
		}
		else
		{
			Pop(&S, &p);
			putchar(p->data);
			p = p->rchild;
		}
	}
}
//后序遍历
void postorder(BiTree T)
{
	if (T != NULL)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		putchar(T->data);
	}
}
//层序遍历二叉树,广度优先遍历
void levelorder(BiTree T)
{
	LinkQueue Q;
	if (!InitQueue(&Q))
	{
		return false;
	}
	BiTree p;
	EnQueue(&Q,T);
	while (!IsEmpty(Q))
	{
		DeQueue(&Q,&p);
		putchar(p->data);
		if (p->lchild != NULL)
		{
			EnQueue(&Q, p->lchild);
		}
		if (p->rchild != NULL)
		{
			EnQueue(&Q,p->rchild);
		}
	}


}
////前序建立二叉树（普通二叉树）
//void CreatBitree(BiTree *T)
//{
//	BiElemType ch;
//	scanf("%c", &ch);
//	if (ch == '#')
//	{
//		*T = NULL;
//	}
//	else
//	{
//		*T = (BiTree)calloc(1, sizeof (BiTNode));
//		if (NULL == *T)
//		{
//			perror(CreatBitree);
//		}
//		(*T)->data = ch;
//		CreatBitree(&(*T)->lchild);
//		CreatBitree(&(*T)->rchild);
//	}
//}
//求完全二叉树的深度
int TreeDepth(BiTree T)
{
	int i = 0;
	while (T)
	{
		i++;
		T = T->lchild;
	}
	return i;
}
int main() 
{
	BiTree pnew;
	BiTree tree = NULL;//树根
	BiElemType c;
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;//phead就是队列头，ptail就是队列尾，pcur是个游标
	//层序建树
	while (scanf("%c", &c) != 'EOF')
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->data = c;
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//给队列结点申请空间
		listpnew->p = pnew;
		if (NULL == tree)//判断此时树根是否为空
		{
			tree = pnew;
			phead = ptail = listpnew;//链表头尾指向头结点
			pcur = listpnew;
			continue;
		}
		else
		{
			ptail->pnext = listpnew;//尾插法，新节点作为原本结点的后继
			ptail = listpnew;//尾指针指向新插入的结点
		}
		//pcur始终指向要插入的结点的位置
		if (NULL==pcur->p->lchild)
		{
			pcur->p->lchild = pnew;//左孩子为空则放入左孩子
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//右孩子为空则放入右孩子，
			pcur = pcur->pnext;//此时pcur指向的结点的左右孩子指针均不为空，pcur指向下一个节点
		}

	}
	printf("先序遍历\n");
	preorder(tree);
	printf("\n中序遍历\n");
	inorder(tree);
	printf("\n非递归中序遍历\n");
	inorder2(tree);
	printf("\n后序遍历\n");
	postorder(tree);
	printf("\n广度优先遍历\n");
	levelorder(tree);
	printf("\n完全二叉树的深度为:\n");
	printf("%d\n",TreeDepth(tree));
	//BiTree T;
	//CreatBitree(&T);
	//printf("先序遍历\n");
	//preorder(T);
	//printf("\n中序遍历\n");
	//inorder(T);
	//printf("\n后序遍历\n");
	//postorder(T);
	return 0;

}