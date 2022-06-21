#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int  ElemType;
//二叉排序树的二叉链表的结点结构抽象数据类型定义
typedef struct BSTNode
{
	ElemType data;//结点数据
	struct BSTNode* lchild, * rchild;//左右孩子指针
}BSTNode, * BsTree;

//二叉排序树初始化
void InitBST(BsTree* T)
{
	*T = NULL;
}

//查找某个值并返回结点位置
BsTree SearchBST(BsTree T, ElemType key, BsTree* p)//树根，值，双亲结点
{
	//以下为非递归查找
	while (T->data != key && T != NULL)//当当前结点T的值不为要查找的值时候进入循环
	{
		*p = T;//进入循环，先更新p的指针，因为下面T会变成T的孩子，此时p就是双亲结点
		if (key < T->data)//小于当前结点的值，就去左孩子找，递归
			T = T->lchild;
		T = T->rchild;//否则去找右孩子，直到为空指针
	}
	return T;//返回的是空指针或所查找结点
	
	//以下为递归查找
	//
	//if (!T || key == T->data)
	//{	*p = T;
	//	return T; 
	//}	
	//else if (key < T->data)
	//	SearchBST(T->lchild, key, p);
	//	SearchBST(T->rchild, key, p);
}
//二叉排序树的插入
bool InsertBST(BsTree *T,ElemType key)
{
	if (*T == NULL)
	{
		(*T) = (BsTree)calloc(1, sizeof(BSTNode));//树根为空时候，第一个值就放在树根
		if(*T){ 
			(*T)->data = key;
			return true;
		}
		
	}
	else if (key == (*T)->data)
	{
		return false;//相同元素则不插入，返回false
	}
	else if (key < (*T)->data)//插入的值小于当前结点则放在左孩子，递归插入
		return InsertBST(&(*T)->lchild, key);
		return InsertBST(&(*T)->rchild, key);//插入的值大于当前结点则插入到右孩子，递归插入
}
//中序遍历二叉排序树
void Inorder(BsTree T)
{
	if (T)
	{
		Inorder(T->lchild);
		printf("%d ", T->data);
		Inorder(T->rchild);
	}
}
//删除二叉排序树值为key的结点
bool  DeleteBSTNode(BsTree* T, ElemType key)
{
	if (!*T){
		return false;//树根为空，树上没有值，返回FALSE
	}
	else if (key < (*T)->data) {
		DeleteBSTNode(&(*T)->lchild,key);//要删除的比当前节点小，则去找左孩子，
		return true;
	}
	else if (key > (*T)->data) {
		DeleteBSTNode(&(*T)->rchild, key);//比当前结点大，去找右孩子
		return true;
	}
	else {//当前结点的值恰好是要删除的
		if (NULL==(*T)->lchild) {//若此节点的左子树为空，则用右孩子替换此节点
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
		else {//该结点左右孩子均不为空，则找此节点左子树的最右节点或者右子树的最左节点的值代替此节点，然后再把最左（最右）结点删除
			BsTree TempNode = (*T)->rchild;//此处采用找右子树的最左结点实现操作
			while (TempNode->lchild!=NULL) {
				TempNode = TempNode->lchild;//寻找右子树的最左节点
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