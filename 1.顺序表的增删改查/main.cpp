#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef int ElemType;//˳����У�Ԫ�ص�����
//��̬����
typedef struct 
{
  ElemType data[MaxSize];//��������飬������Ԫ��
  int length;//��ǰ˳������ж���Ԫ��
}Sqlist;

//��ʼ��˳���
void  InitList(Sqlist&L) 
{
	L.length = 0;
	
}
//i��������λ�ã���1��ʼ��eҪ�����Ԫ��
bool ListInsert(Sqlist& L, int i, ElemType e)
{
	  if(i<1||i>L.length+1)//�ж�Ҫ�����λ���Ƿ�Ϸ�
		return false;

	  if (L.length >= MaxSize)//Ԫ�ش洢�����������ռ���
		return false;

	  if(i <= L.length)
	  { 
		  for (int j = L.length; j >= i-1; j--)//�ƶ�˳����е�Ԫ��
		  L.data[j] = L.data[j - 1]; }
 
	  L.data[i - 1] = e;//�����±��0��ʼ�������һ��λ�ã����ʵ��±�Ϊ0
	  L.length++;
	  return true;//�ߵ�����˵������ɹ�������true
}

//ɾ��ʹ��Ԫ��e�����õ�Ŀ�����ó���Ӧ��ֵ
bool ListDelete(Sqlist& L, int i, ElemType & e)
{
  if (i<1 || i>L.length)//�ж�Ҫɾ����λ���Ƿ�Ϸ�
	return false;
  e = L.data[i - 1];//��ȡ˳����ж�Ӧ��Ԫ�أ���ֵ��e
  for (int j = i; j < L.length; j++)//��i��λ�ã����ΰ�Ԫ����ǰ����
  {
	L.data[j - 1] = L.data[j];
  }
  L.length--;//ɾ��һ��Ԫ�أ�˳����ȼ�һ
  return true;
}



//��ӡ˳���Ԫ��
void PrintList(Sqlist& L)
{
  for (int i = 0; i < L.length; i++)
  {
	printf("%-3d", L.data[i]);//Ҫ������Ԫ�ش�ӡ��һ��
  }
  printf("\n");
}

//���ҳɹ�������λ�ã�λ�ô�1��ʼ������ʧ�ܣ�����0
int LocateElem(Sqlist& L, ElemType e)
{
  int i;
  for (i = 0; i < L.length; i++)
  {
	if (L.data[i] == e)
	{
	  return i + 1;//��һ����Ԫ����˳����е�λ��
	}
  }
	return 0;
  
}
//��e����L�е�i��Ԫ�ص�ֵ��ע��i��λ��,�����±�ӦΪi-1
bool GetElem(Sqlist& L, int i, ElemType& e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return false;
	e = L.data[i-1];
	return true;
}
//��L��Ϊ�ձ�
bool ClearList(Sqlist &L)
{
	L.length = 0;
	return true;
}
//����L������Ԫ�ظ���
int ListLength(Sqlist L)
{
	return L.length;

}
/*�����е������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��*/
void unionL(Sqlist& La, Sqlist Lb)
{
	int La_len, Lb_len, i;
	ElemType e;                        /*������La��Lb��ͬ������Ԫ��e*/
	La_len = ListLength(La);            /*�����Ա�ĳ��� */
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, e);              /*ȡLb�е�i������Ԫ�ظ���e*/
		if (!LocateElem(La, e))        /*La�в����ں�e��ͬ����Ԫ��*/
			ListInsert(La, La_len++, e); /*����*/
	}
}
int main()
{
  Sqlist L;//˳��������
  Sqlist Lb;//�ڶ���˳���
  bool ret;//�鿴����ֵ����������True������False
  ElemType del;//������Ҫɾ����Ԫ��
  InitList(L);
  //�����ֶ���˳�����ǰ����Ԫ�ظ�ֵ
  //L.data[0] = 1;			
  //L.data[1] = 2;
  //L.data[2] = 3;
  //L.length = 3;//�ܼ�����Ԫ��
  //int quantity;//����Ҫ��ʼ����Ԫ������
  //printf("������Ҫ��ʼ�����Ա������:\n");
  //scanf("%d", &quantity);
    int j;
	
	     for(j=1;j<=5;j++)
		 ListInsert(L,1,j);
		
		printf("��ǰ˳���Ϊ��\n");
		PrintList(L);
  ret = ListInsert(L, 2, 6);//���ڶ���λ�ò���'60'���Ԫ��
  if (ret)
  {
	printf("����ɹ�\n");
	printf("��ǰ˳���Ϊ��\n");
	PrintList(L);//��ӡ�ɹ����˳���
  }
  else {
	printf("����ʧ��\n");
	printf("��ǰ˳���Ϊ��\n");
	PrintList(L);
  }
  ret = ListDelete(L, 1, del);//ɾ����һ��λ�õ�Ԫ�أ�����Ԫ��ֵ���
  if (ret)
  {
	printf("ɾ���ɹ�\n");
	printf("ɾ����ֵΪ%d\n", del);
	printf("��ǰ˳���Ϊ��\n");
	PrintList(L);//��ӡ�ɹ����˳���
  }
  else
  {
	printf("ɾ��ʧ��");
	printf("��ǰ˳���Ϊ��\n");
	PrintList(L);
  }
  int elem_pos,a;
  printf("������Ҫ���ҵ�Ԫ��\n");
  scanf("%d", &a);
  elem_pos = LocateElem(L,a);
  printf("���ҵ�Ԫ��Ϊ%d\n", a);
  if (elem_pos)
  {
	printf("���ҳɹ�\n");
	printf("Ԫ��λ��Ϊ%d\n", elem_pos);
	printf("��ǰ˳���Ϊ��\n");
	PrintList(L);
  }
  else
  {
	printf("����ʧ��\n");
	printf("��ǰ˳���Ϊ��\n");
	PrintList(L);
  }
  int i;
  printf("������Ҫ���ҵ�Ԫ��λ��\n");
  scanf("%d", &i);
  ret = GetElem(L, i, del); 
  if (ret)
  {
	  printf("���ҳɹ����鵽��Ԫ��Ϊ��\n");
	  printf("%d\n", del);
	  printf("��ǰ˳���Ϊ��\n");
	  PrintList(L);
  }
  else
  {
	  printf("����ʧ��\n");
	  printf("��ǰ˳���Ϊ��\n");
	  PrintList(L);
  }
  InitList(Lb);
  for (j = 6; j <= 15; j++)
	  i = ListInsert(Lb, 1, j);
  printf("�µ�˳���Lb������ʾ��\n");
  PrintList(Lb);
  unionL(L, Lb);
  printf("��������ϲ���Lb��L��Ԫ�أ�\n");
  PrintList(L);
  return 0;
}