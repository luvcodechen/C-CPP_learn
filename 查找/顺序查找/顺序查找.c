#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef int ElemType;
//��̬�����ڴ��һά����
typedef struct {
	ElemType* elem;//����ָ��
	int ArrLen;//�����ʼ����
}Arr;
//��ʼ�����鲢����Ҫ��ʼ���ĸ���
bool InitArr(Arr* s, int len) {
	s->ArrLen = len + 1;//������һ���ռ����ڱ�
	s->elem = (ElemType*)calloc(s->ArrLen,sizeof(ElemType));
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
		printf("%d ",s.elem[i]);
	}
	printf("\n");
}
//˳�����,����λ��
int Search_Seq(Arr s,ElemType key) {
	s.elem[0] = key;//�ڱ�
	int i = 0;
	for (i = s.ArrLen - 1; s.elem[i] != key; i--);
		return i;
	
}
int main()
{
	srand((unsigned)time(NULL));
	Arr s;
	InitArr(&s,10);
	PrintArr(s);
	ElemType key;
	printf("������Ҫ���ҵ�Ԫ�ص�ֵ��\n");
	scanf("%d", &key);
	if (Search_Seq(s, key))
	{
		printf("���ҳɹ���Ԫ��λ��Ϊ%d\n", Search_Seq(s, key));
	}
	else { 
		printf("����ʧ��"); }

	//qsort();
	return 0;

}