#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
//��������������
#define MAX 20
typedef char ElemType;
//�����������Ĵ洢�ṹ
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode* left, * right;
	bool ltag, rtag;
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
	return T == NULL ? 0 : fmax(DepthTree(T->left), DepthTree(T->right)) + 1;
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
//���ٶ�����
void DestroyBiTree(BiTree* T)
{
	if (*T)
	{
		DestroyBiTree(&(*T)->left); /* ������������ */
		DestroyBiTree(&(*T)->right); /* �����Һ������� */
		free(*T); /* �ͷŸ���� */
		*T = NULL; /* ��ָ�븳0 */
	}
}
//����������������н���,A��B�ֱ�洢ǰ����������У�pre��mid�ֱ���ǰ�������ʼ������λ�ã�nΪ���Ľ�����
BiTree pre_ordercreate(ElemType* A, ElemType* B, int pre, int mid, int n)
{
	if (n == 0)
		return NULL;
	BiTree p = (BNode*)calloc(1, sizeof(BNode));
	if (!p)
		return NULL;
	p->data = A[pre];
	int i = 0;
	for (i = 0; B[mid + i] != A[pre]; i++);//���ڵ�����������е�λ��
	p->left = pre_ordercreate(A, B, pre + 1, mid, i);//�ݹ齨��������
	p->right = pre_ordercreate(A, B, pre + i + 1, mid + i + 1, n - i - 1);//�ݹ齨��������
	return p;

}
//��������Ŀ�ȣ����ǹ�����ȱ�������ʵ�� 
int treewidth(BiTree T)
{
	if (T == NULL)
		return 0;
	BiTree q[MAX];//��������
	int front, rear;//��ͷ��βָ��
	front = rear = -1;
	BNode* p;
	q[++rear] = T;
	int last = 0;//ָʾÿһ�����һ�����
	int i = 0, width = 0;//width��¼ÿһ���ȣ�i��¼ÿһ���һ�����
	while (front < rear)
	{
		p = q[++front];
		if (p->left)
			q[++rear] = p->left;//�������
		if (p->right)
			q[++rear] = p->right;//�Һ������
		if (front == last)
		{
			width = fmax(last - i + 1, width);
			last = rear;//�����²������λ��
			i = front + 1;//�����²��һ�����λ��
		}
	}
	return width;
}
//����ݹ�������
void InThread(BiTree T,BNode**pre)
{
	if (T)
	{
		InThread(T->left, pre);//�ݹ�����������
		if (T->left == NULL)//������Ϊ�գ�����ǰ������
		{

			T->left = *pre;
			T->ltag = 1;
		}
		if (*pre != NULL&&(*pre)->right == NULL  )//����ǰ�����ĺ������
		{
			(* pre)->right = T;
			(* pre)->rtag = 1;
		}
		*pre = T;//��ǵ�ǰ����Ϊ�ոշ��ʵĽ��
		InThread(T->right, pre);//�ݹ�����������
	}
}
//��������������
void creatInThraed(BiTree T)
{
	BNode* pre = NULL;
	if (T)
	{
		InThread(T, &pre);//�ǿն�������������
		pre->right = NULL;//��������������һ�����
		pre->rtag = 1;
	}
}
//�����������������ĵ�һ�����if
BNode* FIRSTNode(BiTree T)
{
	while (T->ltag == 0)
		T = T->left;
	return T;
}
//��������������ĳ�����ĺ�̽��
BNode* NextNode(BNode *p)
{
	if (p->rtag == 0)
		return FIRSTNode(p->right);
	else
		return p->right;
}
//�����������������������
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
	preCreatTree(&T);//������
	//printf("������һ������");
	//levelCreat(&T);//������
	//printf("�����ڶ�������");
	//levelCreat(&Tb);//������
	//ElemType A[] = "abdefgc";//��������
	//ElemType B[] = "dbfegac";//��������
	//int len = strlen(A);
	//T = pre_ordercreate(A, B, 0, 0, len);//�������������н���
	printf("���������");
	preorderTraverse(T);
	printf("\n���������");
	InorderTraverse(T);
	printf("\n���������");
	postorderTraverse(T);
	printf("\n���������");
	leveltravese(T);
	printf("\n�������߶�:");
	printf("%d", DepthTree(T));
	printf("\n");
	int width = treewidth(T);
	printf("��������ȣ�%d\n", width);
	creatInThraed(T);//����������
	Inorder(T);//���������������������

	return 0;
}