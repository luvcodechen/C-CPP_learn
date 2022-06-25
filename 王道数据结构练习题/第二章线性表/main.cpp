#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20
typedef int ElemType;
//˳���ṹ��
typedef struct
{
	ElemType data[MaxSize];
	int length;
}Sqlist;//˳���

//��ʼ��˳���
void InitList(Sqlist &L)
{
	L.length = 0;
}
//ɾ����СԪ��,��������ֵ���ճ���λ�������һ��Ԫ���  ------�ڶ��µ�һ��
bool DeleteMinElem(Sqlist &L,ElemType &e)
{
	int i = 0;
	ElemType elem = 0;
	int pos = 0;
	if (0 == L.length)
	{
		printf("˳���Ϊ��");
		return false;
	}		
	elem = L.data[0];
	for (i = 1; i < L.length; i++)
	{
		if (L.data[i] < elem)//�ҵ���Сֵ���±�
		{
			elem = L.data[i];
			e = L.data[i];
			pos = i;
		}
	}
	L.data[pos] = L.data[L.length - 1];//�޸�ֵ
	L.length--;
	return true;
}

//���һ����Ч�㷨����Ԫ�����ã�Ҫ��ռ临�Ӷ�o(1��-------�ڶ���
void reverselist(Sqlist &L)
{
	int i,j;
	ElemType temp = 0;
	for (i = 0, j = L.length - 1; i <j; i++, j--)//����
	{
		temp = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = temp;
	}
}
//�Գ���Ϊn��˳���L,дһ��ʱ�临�Ӷ�n���ռ�1�㷨��ɾ������ֵΪx��Ԫ��------ ������
void deletex(Sqlist &L,ElemType x)
{
	int count = 0;//����
	int i = 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] != x)
		{
			L.data[count] = L.data[i];
			count++;
		}
	}
	L.length = count;
}

//������˳���ɾ��ֵ�ڸ���ֵs��t֮�������Ԫ�أ�s<t,s����t���������Ϊ�ո�����Ӧ��----------������
bool deletest(Sqlist &L,int s,int t)
{
	if (s >= t || L.length == 0)
		return false;
	int low=0, high=0;
	int minus;
	int i = 0;
	for (i = 0; i < L.length && L.data[i] <= s; i++);//�ҵ���s�����С�������±�
	if (i >= L.length)//��������sС
		return false;
		low = i;
	for (i = low; i < L.length && L.data[i] < t; i++);//�ҵ�����tС����С�������±�
		high = i;
	minus = high - low;//����Ӧ��ɾ�����ٸ���
	for (i = high; i <L.length; i++)//��û��ɾ������ǰ��
	{
		L.data[i - minus] = L.data[i];
	}
	L.length -= minus;
	return true;
}

//������˳���ɾ��ֵ�ڸ���ֵs��t֮�������Ԫ�أ�s<t,s����t���������Ϊ�ո�����Ӧ��----------������
bool delete_s_t(Sqlist &L,int s,int t)
{
	if (s >= t || L.length == 0)
		return false;//����
	int i = 0;
	int count = 0;
	for (i = 0; i < L.length - 1; i++){
		if (L.data[i]<=s || L.data[i]>=t)//���ںſ����Ƿ�����߽�
		{
			L.data[count] = L.data[i];
			count++;
		}
	}//for
	L.length = count;
	return true;
}

//��ӡ˳���
void PrintList(Sqlist L)
{
	int i = 0;
	if (L.length)
		for (i = 0; i < L.length; i++)
			printf("%d ", L.data[i]);
	printf("\nL.length=%d", L.length);
	printf("\n");
}
int main()
{

	int i = 0;
	ElemType e;
	Sqlist L;
	InitList(L);
	int arr1[] = { 10,20,30,40,50,51,55,60,66,70,80,90};
	int arr2[] = { 11,12,30,7,5,51,21,26,24,65,1,46};
	for (i = 0; i < sizeof(arr1)/sizeof(ElemType); i++)
	{
		L.data[i] = arr1[i];//�����������˳����ʼ��
	}
	L.length = sizeof(arr1) / sizeof(ElemType);
	//DeleteMinElem(L,e);//ɾ����СԪ�ز���e������ֵ
	//reverselist(L);//��Ԫ������
	//deletex(L,11);//ɾ��ֵΪ11����
	//delete_s_t(L,10,30);//ɾ��ֵ��20��30֮�����
	deletest(L,10,100);//���������ɾ��ֵ��19-49��ֵ���������߽�
	PrintList(L);
	return 0;
}