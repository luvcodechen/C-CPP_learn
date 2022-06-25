#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 30
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
//�������ɾ���ظ�Ԫ�أ�ʹ����Ԫ�ز�ͬ--------------������
void deletesame(Sqlist &L)
{
	int i = 0,j = 0;
	for (i = 0; i < L.length; i++)
		if (L.data[i] != L.data[i + 1])
			L.data[j++] = L.data[i];//ǰ��ͬ�����
	L.length = j;
}

//�����ĺϲ�------------------------������
Sqlist un( Sqlist La, Sqlist Lb)
{
	Sqlist Lc;
	int i = 0,j = 0,k = 0,lena = La.length,lenb=Lb.length;
	for (i = 0,j = 0; i < lena&&j<lenb;)
	{
		if (La.data[i] <= Lb.data[j])
			Lc.data[k++] = La.data[i++];
		else
			Lc.data[k++] = Lb.data[j++];
	}
	while (i < lena)
		Lc.data[k++] = La.data[i++];
	while (j < lenb)
		Lc.data[k++] = Lb.data[j++];
	Lc.length = k;
	return Lc;
}
//��֪һά����A[m+n]������������Ա�a1��a2��������am��b1��b2������bn��������˳�򻥻�----------�ڰ���
void change(ElemType B[], int m, int n)
{
	Sqlist Lm, Ln;
	int i = 0,j = 0;
	for (i = 0; i < m; i++)
		Lm.data[i] = B[i];
	Lm.length = m;
	for (; i < m + n; i++)
		Ln.data[j++] = B[i];
	Ln.length = n;
	for (i = 0; i < n; i++)
		B[i] = Ln.data[i];
	j = 0;
	for (; i < m + n; i++)
		B[i] = Lm.data[j++];

}
//���Ա��������������㷨����ʱ���ҵ�ĳֵ�����ҵ�������λ�ý�������û�У������----------�ھ���

//�۰����
int BinarySearch(Sqlist L,ElemType e)
{
	int low = 0, high = L.length-1,mid = 0;
	while(low <= high)
	{
		mid = (low+high) / 2;
		if (L.data[mid] == e)return mid;
		else if (L.data[mid] < e)low = mid + 1;
		else high = mid - 1;
	}
	return mid;
}
//��λ�ò���
bool InsertList(Sqlist&L,int pos,ElemType e)
{
	if (pos<1 || pos>L.length + 1 || L.length == MaxSize)
		return false;//�Ƿ�
	int i = 0;
	for (i = L.length - 1; i >= pos - 1; i--)
	{
		L.data[i + 1] = L.data[i];
	}
	L.data[pos - 1] = e;
	L.length++;
	return true;
}
//�ھ������ʵ��
void search_change(Sqlist&L,ElemType x)
{
	int ret=BinarySearch(L,x);
	if (L.data[ret] == x&&ret!=L.length-1)
	{
		ElemType temp = L.data[ret];
		L.data[ret] = L.data[ret + 1];
		L.data[ret + 1] = temp;
		return;
	}
	if (L.data[ret] > x)
		InsertList(L, ret+1, x);
	else if(L.data[ret]<x)
		InsertList(L, ret + 2, x);
}
//n��������һά����R�С���r�б��������ѭ������p��0<p<n,-------------------��ʮ��
void cirleftmove(ElemType *R, int p) {
	int n = 10;
	int i = 0, k = 0;
	ElemType arr[10] ;
	for (i = 0; i < n; i++)
	{
		arr[(i + n - p)%n] = R[i];//ѭ�����ƹ�ʽ
	}
	for (i = 0; i < n; i++)
	{
		R[i] = arr[i];//�ռ临�ӶȺ�ʱ�临�ӶȾ�Ϊo(n).
	}
}
//��ʮ�⣬�ռ�o(1)ʵ��
//���������±�s-t֮�����,�����߽�
void reverse(int *A,int s,int t)
{
	int i = 0, temp = 0,j = 0;
	for (i = s,j = 0; i < (t-j); i++, j++)
	{
		temp = A[i]; A[i] = A[t - j]; A[t - j] = temp;
	}
}
void cirleftmove1(ElemType* R, int p)
{
	int n = 10;
	reverse(R,0,p-1);
	reverse(R,p,n-1);
	reverse(R,0,n-1);
}

//��ӡ˳���
void PrintList(Sqlist L)
{
	int i = 0;
	if (L.length)
		for (i = 0; i < L.length; i++)
			printf("%d ", L.data[i]);
	printf("\nlength=%d", L.length);
	printf("\n");
}
int main()
{

	int i = 0;
	ElemType e = 0;
	Sqlist L;
	Sqlist Lb;
	Sqlist Lc;
	InitList(L);
	InitList(Lb);
	ElemType A[] = { 10,20,50,51,60,66,8,11,30,51};
	int arr1[] = { 10,20,20,20,50,51,51,60,66,66,80,90};
	int arr3[] = { 1,2,3,4,5,15,20,30,65,75,80,95};
	int arr2[] = { 11,12,30,7,5,51,21,26,24,65,1,46};
	for (i = 0; i < sizeof(arr1)/sizeof(ElemType); i++)
	{
		L.data[i] = arr1[i];//�����������˳����ʼ��
	}
	L.length = sizeof(arr1) / sizeof(ElemType);
	for (i = 0; i < sizeof(arr3)/sizeof(ElemType); i++)
	{
		Lb.data[i] = arr3[i];//�����������˳����ʼ��
	}
	Lb.length = sizeof(arr3) / sizeof(ElemType);
	//DeleteMinElem(L,e);//ɾ����СԪ�ز���e������ֵ
	//reverselist(L);//��Ԫ������
	//deletex(L,11);//ɾ��ֵΪ11����
	//delete_s_t(L,10,30);//ɾ��ֵ��20��30֮�����
	//deletest(L,10,10);//���������ɾ��ֵ��19-49��ֵ���������߽�
	//deletesame(L);//ɾ����������ظ�Ԫ��ʹ����Ԫ�ز�ͬ
	//change(A,10,8);//�����������������Ϊ10��8�����Ա��λ��
	//for (i = 0; i < sizeof(A) / 4; i++)
	//	printf("%d ", A[i]);
	//printf("\n");
	//PrintList(Lb);
	//Lc = un(L,Lb);//�����ĺϲ�
	//PrintList(Lc);
	//PrintList(L);
	//printf("%d\n", BinarySearch(L, 90));
	//search_change(L,90);//������в���90�����У����̽��������ޣ�����
	//cirleftmove1(A,5);
	//for (int i = 0; i < 01; i++)
		//printf("%d ", A[i]);
	PrintList(L);

	return 0;
}