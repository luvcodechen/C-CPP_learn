#define _CRT_SECURE_NO_WARNINGS

#include "function.h"
//�������
void preorder(BiTree T)
{
	if (T != NULL)
	{
		putchar(T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}//�������
void inorder(BiTree T)
{
	if (T != NULL)
	{		
		inorder(T->lchild);
		putchar(T->data);
		inorder(T->rchild);
	}
}
//�ǵݹ��������
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
//�������
void postorder(BiTree T)
{
	if (T != NULL)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		putchar(T->data);
	}
}
//�������������,������ȱ���
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
////ǰ��������������ͨ��������
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
//����ȫ�����������
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
	BiTree tree = NULL;//����
	BiElemType c;
	ptag_t phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;//phead���Ƕ���ͷ��ptail���Ƕ���β��pcur�Ǹ��α�
	//������
	while (scanf("%c", &c) != 'EOF')
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->data = c;
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));//�����н������ռ�
		listpnew->p = pnew;
		if (NULL == tree)//�жϴ�ʱ�����Ƿ�Ϊ��
		{
			tree = pnew;
			phead = ptail = listpnew;//����ͷβָ��ͷ���
			pcur = listpnew;
			continue;
		}
		else
		{
			ptail->pnext = listpnew;//β�巨���½ڵ���Ϊԭ�����ĺ��
			ptail = listpnew;//βָ��ָ���²���Ľ��
		}
		//pcurʼ��ָ��Ҫ����Ľ���λ��
		if (NULL==pcur->p->lchild)
		{
			pcur->p->lchild = pnew;//����Ϊ�����������
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;//�Һ���Ϊ��������Һ��ӣ�
			pcur = pcur->pnext;//��ʱpcurָ��Ľ������Һ���ָ�����Ϊ�գ�pcurָ����һ���ڵ�
		}

	}
	printf("�������\n");
	preorder(tree);
	printf("\n�������\n");
	inorder(tree);
	printf("\n�ǵݹ��������\n");
	inorder2(tree);
	printf("\n�������\n");
	postorder(tree);
	printf("\n������ȱ���\n");
	levelorder(tree);
	printf("\n��ȫ�����������Ϊ:\n");
	printf("%d\n",TreeDepth(tree));
	//BiTree T;
	//CreatBitree(&T);
	//printf("�������\n");
	//preorder(T);
	//printf("\n�������\n");
	//inorder(T);
	//printf("\n�������\n");
	//postorder(T);
	return 0;

}