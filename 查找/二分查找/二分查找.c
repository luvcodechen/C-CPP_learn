#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

typedef int ElemType;
//��̬�����ڴ��һά����
typedef struct {
	ElemType* elem;//����ָ��
	int ArrLen;//�����ʼ����
}Arr;
//��ʼ�����鲢����Ҫ��ʼ���ĸ���
bool InitArr(Arr* s, int len) {
//	s->ArrLen = len + 1;//������һ���ռ����ڱ�
	s->ArrLen = len;
	s->elem = (ElemType*)calloc(s->ArrLen, sizeof(ElemType));
	if (!s->elem)
	{
		return false;
	}
	int i = 0;
	for (i = 0; i < s->ArrLen; i++)
	{
		s->elem[i] = rand() % 100 + 1;
	}
	return true;
}
//��ӡ����
void PrintArr(Arr s)
{
	int i = 0;
	for (i = 0; i < s.ArrLen; i++) {
		printf("%d ", s.elem[i]);
	}
	printf("\n");
}
//���ֲ���
int Binary_Search(Arr s,ElemType key)
{
	int left=0, right=s.ArrLen-1,mid=0;
	int i = 0;
	while (left <= right)
	{
		
		i++;
		mid = (left + right) / 2;
		if (s.elem[mid] == key)
		{
			printf("���Ҵ���Ϊ;\n");
			printf("%d\n", i);
			return mid + 1;
		}
		else if (key < s.elem[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int compare(const void* left, const void* right)
{
	return *(ElemType*)left - *(ElemType*)right;
}
int main()
{
	srand((unsigned)time(NULL));
	Arr s;
	InitArr(&s, 20);
	PrintArr(s);
	ElemType key;
	qsort(s.elem,s.ArrLen,sizeof(ElemType),compare);//��������
	PrintArr(s);
	printf("������Ҫ���ҵ�Ԫ�ص�ֵ��\n");
	int j =scanf("%d", &key);
	int pos = Binary_Search(s, key);
	if (pos>=0) {
		printf("���ҳɹ���Ԫ��λ��Ϊ;%d\n",pos);
	}
	else
		printf("����ʧ�ܣ�Ԫ�ز�����\n");
	return 0;

}