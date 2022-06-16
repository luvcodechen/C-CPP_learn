#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>

//链表结构表示的多项式结构体
typedef struct Poly
{
	float coef;//系数
	int expn;//指数	
	struct Poly* next;
}LinkList_Polynomial,*poly;

//多项式链表的初始化
bool InitPoly(poly *P)
{
	*P = (poly)malloc(sizeof(LinkList_Polynomial));
	if (NULL == *P)
	{
	//	perror(InitPoly);
		return false;//申请内存失败
	}
	(*P)->coef = 0;
	(*P)->expn = 0;
	(*P)->next = NULL;
	return true;
}


//获取指数小于等于给定数值的节点
poly LikeE(poly p, int e)
{
	if (NULL == p)
	{
		return NULL;//若p为空则说明未初始化返回空指针
	}
	poly q;
	for (q = p; q->next != NULL; q = q->next)//
	{
		if (q->next->expn >= e)//从第一个结点开始，若下个结点的指数大于给定指数，则返回当前结点
		{
			return q;
		}
	}
	return q;//没有找到比给定指数大的节点，则要么多项式为空返回p此时为头结点，要么指数都较小，此时p结点指向最后一个结点
}

//获取指数为e的项的节点
poly GetE(poly p, int e)
{
	poly s;
	s = p->next;
	while (s)
	{
		if (e == s->expn)
		{
			return s;
		}
		s = s->next;
	}
	return NULL;
}
//插入新的项，如果没有相同次方则插入到合适位置保持多项式根据指数次序的排列，若有则合并同类项
bool  InsertPoly(poly* p, float c, int e)
{
	poly q;
	if (q = GetE(*p, e))//寻找是否有相同指数的项
	{
		//j = q->expn;//用j临时存储该项的指数
		q->coef += c;//将常数项相加即可
		if (-0.000001 < q->coef && q->coef < 0.000001)//系数为零
		{
			//释放之前不能断链,找到q前面的结点，接上链
			poly tem = LikeE(*p, e);
			tem->next = q->next;
			free(q);
			return true;
		}
	}
	else
	{
		poly s = (poly)malloc(sizeof(LinkList_Polynomial));//创键新节点
		if (NULL == s)
		{
			return false;
		}
		s->coef = c; //存放常数项
		s->expn = e;//存放指数
		poly r = LikeE(*p, e);//获取指数比e小的结点		
		s->next = r->next;//按照链表插入操作即可
		r->next = s;

	}
	return true;
}

//多项式的创建，传入头指针和多项式的项数
bool CreatPoly(poly*p,int n)
{
	poly s = (poly)malloc(sizeof(LinkList_Polynomial));
	if (NULL == s)
	{
		return false;//申请内存失败
	}
	int i, e = 0;
	float c = 0.0;
	for (i = 0; i < n; i++)
	{
		int k =scanf("%f %d", &c, &e);				
		if (!InsertPoly(p, c, e))
		{
			return false;
		}
	}
	return true;
}

//多项式相加
bool add(poly*pa,poly *pb)
{
	poly p =(*pa)->next, q = (*pb)->next;
	poly s = *pa;//pa的头结点
	poly tmp = NULL;
	while (p && q)//当p和q都不为空指针
	{
		if (p->expn < q->expn)
		{
			s->next = p;//若p的指数小，则将p放在多项式中
			s = p;//s指向表尾
			p = p->next;//继续指向下一个结点
		}
		else if (p->expn > q->expn)
		{
			s->next = q;//同上
			s = q;
			q = q->next;
		}
		else if (p->expn == q->expn)
		{
			p->coef += q->coef;
			if (0 == p->coef )//系数为则释放结点，并将指针指向下一个结点
			{
				tmp = p->next;
				free(p);
				p = tmp;
				tmp = q->next;
				free(q);
				q = tmp;
			}
			else
			{
				s->next = p;
				s = p;
				p = p->next;
				tmp = q->next;
				free(q);
				q = tmp;
			}
		}
	}
	s->next = p ? p : q;
	return true;
}

//打印多项式
bool pritnt(poly p)
{
	if (NULL == p)
	{
		return false;//未初始化
	}
	poly q = p->next;
	if (!q)
	{
		return false;
	}
	while (q)
	{
		printf("%1.1f", q->coef);
		if (q->expn)
		{
			printf("*x^%d", q->expn);
		}
		if (q->next && q->next->coef > 0)
		{
			printf("+");
		}
		q = q->next;
	}
	printf("\n");
	return true;
}
int main()
{
	poly Pa;
	poly Pb;
	InitPoly(&Pa);
	InitPoly(&Pb);
	//CreatPoly(&Pa,3);
	bool status = 0;
	if (!(status = pritnt(Pa)))
	{
		printf("没有元素\n");
	}
	//CreatPoly(&Pb,2);
	//InsertPoly(&Pb,2.5,4);
	InsertPoly(&Pa,2.5,4);
	InsertPoly(&Pa,3.1,5);
	InsertPoly(&Pa,1.0,3);
	InsertPoly(&Pa,-2.5,4);
	InsertPoly(&Pa,4.1,9);
	pritnt(Pa);
	printf("\n");
	InsertPoly(&Pb,3.1,5);
	InsertPoly(&Pb,1.0,3);
	InsertPoly(&Pb,-2.5,4);
	InsertPoly(&Pb,4.1,9);
	pritnt(Pb);
	printf("\n");
	add(&Pa, &Pb);
	pritnt(Pa);
//	pritnt(Pa);
	//InsertPoly(&Pb,1,1);
	return 0;
}