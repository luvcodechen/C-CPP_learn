#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdbool.h>

//����ṹ��ʾ�Ķ���ʽ�ṹ��
typedef struct Poly
{
	float coef;//ϵ��
	int expn;//ָ��	
	struct Poly* next;
}LinkList_Polynomial,*poly;

//����ʽ����ĳ�ʼ��
bool InitPoly(poly *P)
{
	*P = (poly)malloc(sizeof(LinkList_Polynomial));
	if (NULL == *P)
	{
	//	perror(InitPoly);
		return false;//�����ڴ�ʧ��
	}
	(*P)->coef = 0;
	(*P)->expn = 0;
	(*P)->next = NULL;
	return true;
}


//��ȡָ��С�ڵ��ڸ�����ֵ�Ľڵ�
poly LikeE(poly p, int e)
{
	if (NULL == p)
	{
		return NULL;//��pΪ����˵��δ��ʼ�����ؿ�ָ��
	}
	poly q;
	for (q = p; q->next != NULL; q = q->next)//
	{
		if (q->next->expn >= e)//�ӵ�һ����㿪ʼ�����¸�����ָ�����ڸ���ָ�����򷵻ص�ǰ���
		{
			return q;
		}
	}
	return q;//û���ҵ��ȸ���ָ����Ľڵ㣬��Ҫô����ʽΪ�շ���p��ʱΪͷ��㣬Ҫôָ������С����ʱp���ָ�����һ�����
}

//��ȡָ��Ϊe����Ľڵ�
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
//�����µ�����û����ͬ�η�����뵽����λ�ñ��ֶ���ʽ����ָ����������У�������ϲ�ͬ����
bool  InsertPoly(poly* p, float c, int e)
{
	poly q;
	if (q = GetE(*p, e))//Ѱ���Ƿ�����ָͬ������
	{
		//j = q->expn;//��j��ʱ�洢�����ָ��
		q->coef += c;//����������Ӽ���
		if (-0.000001 < q->coef && q->coef < 0.000001)//ϵ��Ϊ��
		{
			//�ͷ�֮ǰ���ܶ���,�ҵ�qǰ��Ľ�㣬������
			poly tem = LikeE(*p, e);
			tem->next = q->next;
			free(q);
			return true;
		}
	}
	else
	{
		poly s = (poly)malloc(sizeof(LinkList_Polynomial));//�����½ڵ�
		if (NULL == s)
		{
			return false;
		}
		s->coef = c; //��ų�����
		s->expn = e;//���ָ��
		poly r = LikeE(*p, e);//��ȡָ����eС�Ľ��		
		s->next = r->next;//������������������
		r->next = s;

	}
	return true;
}

//����ʽ�Ĵ���������ͷָ��Ͷ���ʽ������
bool CreatPoly(poly*p,int n)
{
	poly s = (poly)malloc(sizeof(LinkList_Polynomial));
	if (NULL == s)
	{
		return false;//�����ڴ�ʧ��
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

//����ʽ���
bool add(poly*pa,poly *pb)
{
	poly p =(*pa)->next, q = (*pb)->next;
	poly s = *pa;//pa��ͷ���
	poly tmp = NULL;
	while (p && q)//��p��q����Ϊ��ָ��
	{
		if (p->expn < q->expn)
		{
			s->next = p;//��p��ָ��С����p���ڶ���ʽ��
			s = p;//sָ���β
			p = p->next;//����ָ����һ�����
		}
		else if (p->expn > q->expn)
		{
			s->next = q;//ͬ��
			s = q;
			q = q->next;
		}
		else if (p->expn == q->expn)
		{
			p->coef += q->coef;
			if (0 == p->coef )//ϵ��Ϊ���ͷŽ�㣬����ָ��ָ����һ�����
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

//��ӡ����ʽ
bool pritnt(poly p)
{
	if (NULL == p)
	{
		return false;//δ��ʼ��
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
		printf("û��Ԫ��\n");
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