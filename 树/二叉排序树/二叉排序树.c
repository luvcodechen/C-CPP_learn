#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int  ElemType;
//�����������Ķ�������Ľ��ṹ�����������Ͷ���
typedef struct BSTNode
{
	ElemType data;//�������
	struct BSTNode* lchild, * rchild;//���Һ���ָ��
}BSTNode, * BsTree;

//������������ʼ��
void InitBST(BsTree* T)
{
	*T = NULL;
}

//����ĳ��ֵ�����ؽ��λ��
BsTree SearchBST(BsTree T, ElemType key, BsTree* p)//������ֵ��˫�׽��
{
	//����Ϊ�ǵݹ����
	while (T->data != key && T != NULL)//����ǰ���T��ֵ��ΪҪ���ҵ�ֵʱ�����ѭ��
	{
		*p = T;//����ѭ�����ȸ���p��ָ�룬��Ϊ����T����T�ĺ��ӣ���ʱp����˫�׽��
		if (key < T->data)//С�ڵ�ǰ����ֵ����ȥ�����ң��ݹ�
			T = T->lchild;
		T = T->rchild;//����ȥ���Һ��ӣ�ֱ��Ϊ��ָ��
	}
	return T;//���ص��ǿ�ָ��������ҽ��
	
	//����Ϊ�ݹ����
	//
	//if (!T || key == T->data)
	//{	*p = T;
	//	return T; 
	//}	
	//else if (key < T->data)
	//	SearchBST(T->lchild, key, p);
	//	SearchBST(T->rchild, key, p);
}
//�����������Ĳ���
bool InsertBST(BsTree *T,ElemType key)
{
	if (*T == NULL)
	{
		(*T) = (BsTree)calloc(1, sizeof(BSTNode));//����Ϊ��ʱ�򣬵�һ��ֵ�ͷ�������
		if(*T){ 
			(*T)->data = key;
			return true;
		}
		
	}
	else if (key == (*T)->data)
	{
		return false;//��ͬԪ���򲻲��룬����false
	}
	else if (key < (*T)->data)//�����ֵС�ڵ�ǰ�����������ӣ��ݹ����
		return InsertBST(&(*T)->lchild, key);
		return InsertBST(&(*T)->rchild, key);//�����ֵ���ڵ�ǰ�������뵽�Һ��ӣ��ݹ����
}
//�����������������
void Inorder(BsTree T)
{
	if (T)
	{
		Inorder(T->lchild);
		printf("%d ", T->data);
		Inorder(T->rchild);
	}
}
//ɾ������������ֵΪkey�Ľ��
bool  DeleteBSTNode(BsTree* T, ElemType key)
{
	if (!*T){
		return false;//����Ϊ�գ�����û��ֵ������FALSE
	}
	else if (key < (*T)->data) {
		DeleteBSTNode(&(*T)->lchild,key);//Ҫɾ���ıȵ�ǰ�ڵ�С����ȥ�����ӣ�
		return true;
	}
	else if (key > (*T)->data) {
		DeleteBSTNode(&(*T)->rchild, key);//�ȵ�ǰ����ȥ���Һ���
		return true;
	}
	else {//��ǰ����ֵǡ����Ҫɾ����
		if (NULL==(*T)->lchild) {//���˽ڵ��������Ϊ�գ������Һ����滻�˽ڵ�
			BsTree TempNode = *T;
			(*T) = (*T)->rchild;
			free(TempNode);
			return true;
		}
		else if (NULL == (*T)->rchild) {
			BsTree TempNode = *T;
			(*T) = (*T)->lchild;
			free(TempNode);
			return true;
		}
		else {//�ý�����Һ��Ӿ���Ϊ�գ����Ҵ˽ڵ������������ҽڵ����������������ڵ��ֵ����˽ڵ㣬Ȼ���ٰ��������ң����ɾ��
			BsTree TempNode = (*T)->rchild;//�˴���������������������ʵ�ֲ���
			while (TempNode->lchild!=NULL) {
				TempNode = TempNode->lchild;//Ѱ��������������ڵ�
			}
			(*T)->data = TempNode->data;
			DeleteBSTNode(&(*T)->rchild, TempNode->data);
			return true;
		}
	}
}
int main()
{
	BsTree T;
	BsTree parent = NULL;
	BsTree search = NULL;
	InitBST(&T);
	ElemType str[] = { 412,115,121,412,452,41,33,15 };
	int i = 0;
	for (i = 0; i < sizeof(str)/sizeof(ElemType); i++)
	{
		InsertBST(&T,str[i]);
	}
	Inorder(T);
	printf("\n");
	DeleteBSTNode(&T, 115);
	Inorder(T);
	return 0;
}