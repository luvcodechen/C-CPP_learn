#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef char VertexType;//��������
typedef int EdgeType;//���ϵ�Ȩֵ����
#define MAXVEX 10 //��󶥵���
#define INFINITY 65536 //������ʾ�������

//ͼ���ڽӾ��������������
typedef struct
{
	VertexType vexs[MAXVEX];//���㼯
	EdgeType arc[MAXVEX][MAXVEX];//�ڽӾ���
	int numNodes, numEdges;//ͼ�е�ǰ�������ͱ���
}MGraph;

//������Ȩ����ͼ���ڽӾ����ʾ
void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("�����붥�����ͱ�����\n");
	scanf("%d %d",&G->numNodes,&G->numEdges);//���붥�����ͱ���
	getchar();
	printf("�����붥�㣬�ÿո������\n");
	for (i=0;i<G->numNodes;i++)//���������
	{
		scanf("%c", &G->vexs[i]);
	}
	for (i = 0; i < G->numNodes; i++)
		for (j = 0; j < G->numNodes; j++)
			G->arc[i][j] = INFINITY;	/* �ڽӾ����ʼ�� */
	for (k = 0; k < G->numEdges; k++) /* ����numEdges���ߣ������ڽӾ��� */
	{
		printf("�����(vi,vj)�ϵ��±�i���±�j��Ȩw:\n");
		scanf("%d,%d,%d", &i, &j, &w); /* �����(vi,vj)�ϵ�Ȩw */
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j]; /* ��Ϊ������ͼ������Գ� */
	}
}





int main()
{
	MGraph G;
	CreateMGraph(&G);



	return 0;

}