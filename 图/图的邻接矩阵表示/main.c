#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef char VertexType;//顶点类型
typedef int EdgeType;//边上的权值类型
#define MAXVEX 10 //最大顶点数
#define INFINITY 65536 //用来表示正无穷∞

//图的邻接矩阵抽象数据类型
typedef struct
{
	VertexType vexs[MAXVEX];//顶点集
	EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
	int numNodes, numEdges;//图中当前顶点数和边数
}MGraph;

//建立带权无向图的邻接矩阵表示
void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("请输入顶点数和边数：\n");
	scanf("%d %d",&G->numNodes,&G->numEdges);//输入顶点数和边数
	getchar();
	printf("请输入顶点，用空格隔开：\n");
	for (i=0;i<G->numNodes;i++)//建立顶点表
	{
		scanf("%c", &G->vexs[i]);
	}
	for (i = 0; i < G->numNodes; i++)
		for (j = 0; j < G->numNodes; j++)
			G->arc[i][j] = INFINITY;	/* 邻接矩阵初始化 */
	for (k = 0; k < G->numEdges; k++) /* 读入numEdges条边，建立邻接矩阵 */
	{
		printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
		scanf("%d,%d,%d", &i, &j, &w); /* 输入边(vi,vj)上的权w */
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j]; /* 因为是无向图，矩阵对称 */
	}
}





int main()
{
	MGraph G;
	CreateMGraph(&G);



	return 0;

}