#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 50
#define isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))//判断是否是字母
#define length(a)  (sizeof(a)/sizeof(a[0])) //计算长度
typedef char VertexType;//顶点类型
//图的邻接表表示的链表结构
typedef struct LNode
{
	int ivex;//指向的点的下标
	struct Lnode* next_edge;//下一个结点的指针
}LNode,*PLNode;
//图的邻接表表示的顶点结构
typedef struct Vnode
{
	VertexType data;//图顶点
	PLNode first_edge;//指向第一个依附该顶点的弧

}Vnode;
//邻接表
typedef struct Graph
{
	int vexnum;//顶点数
	int edgenum;//边数
	Vnode vex[MAX];//顶点数组	
}Graph;

//读取一个字母
char read_char()
{
	char c = 0;
	do {
		c = getchar();
	} while (!isletter(c));
	return c;
}
//获取字母在顶点数组中的下标
int pos(Graph G,char c)
{
	int i = 0;
	for (i = 0; i < G.vexnum; i++)//遍历顶点数组
		if (G.vex[i].data == c)//返回该字母下标
			return i;
	return -1;

}

//将结点放在链表尾
void last(PLNode L,PLNode node)
{
	PLNode p = L;
	while (p->next_edge)
		p = p->next_edge;
	p->next_edge = node;
}
//无向图的创键
Graph* creatgraph()
{
	int v = 0, e = 0;//存顶点数和边数
	int i = 0;//临时变量用来计数
	char c1 = 0, c2 = 0;//初始化边时使用
	int p1 = 0, p2 = 0;//初始化边时存放顶点下标
	PLNode node1 = NULL, node2 = NULL;//初始化两个链表节点存边的两个顶点
	Graph* G;
	if (NULL == (G = (Graph*)calloc(1, sizeof(Graph))))//申请空间置0
		return NULL;
	printf("输入顶点数，边数：\n");
	i = scanf("%d%d",&v,&e);
	G->vexnum = v;//顶点
	G->edgenum = e;//边
	for (i = 0; i < G->vexnum; i++)//初始化邻接表的顶点
	{
		printf("输入顶点%d：\n",i+1);
		G->vex[i].data = read_char();//读取正确的字母
	}
	for (i = 0; i < G->edgenum; i++)//初始化边
	{
		printf("边%d\n", i+1);
		c1 = read_char();//存顶点
		c2 = read_char();//存顶点
		p1 = pos(*G,c1);//顶点下标
		p2 = pos(*G,c2);//顶点下标
		node1 = (PLNode)calloc(1, sizeof(LNode));//链表节点
		node1->ivex = p2;//弧头
		if (G->vex[p1].first_edge == NULL)
			G->vex[p1].first_edge = node1;//若p1位置的顶点没有第一条边。则node1接在后面
		else  //否则将node1接在其最后
			last(G->vex[p1].first_edge, node1);
		//无向图，所以另一个顶点同样的操作
		node2 = (PLNode)calloc(1, sizeof(LNode));//链表节点
		node2->ivex = p1;//弧头
		if (G->vex[p2].first_edge == NULL)
			G->vex[p2].first_edge = node2;//若p1位置的顶点没有第一条边。则node1接在后面
		else  //否则将node1接在其最后
			last(G->vex[p2].first_edge, node2);
	}
	return G;
}
//无向图的手动创建
Graph* mycreatgraph()
{
	Graph* G;
	if (NULL == (G = (Graph*)calloc(1, sizeof(Graph))))
		return NULL;
	char vex[] = { 'a','b','c','d','e','f'};//初始顶点数组
	char edge[][2] = 
	{
	{'a','f'},{'e','c'}, {'b','c'}, {'e','f'}, {'d','e'}
	};//初始化边

	int vlen = length(vex);//获取顶点个数
	int elen = length(edge);//获取边的个数
	//下面根据已有数据建图,和手动创键一致
	int i = 0,p1 = 0, p2 = 0;
	char c1 = 0, c2 = 0;
	PLNode node1 = NULL, node2 = NULL;
	G->vexnum = vlen;
	G->edgenum = elen;
	for (i = 0; i < G->vexnum; i++)//初始化顶点
	{
		G->vex[i].data = vex[i];
	}
	for (i = 0; i < G->edgenum; i++)//初始化邻接表的边
	{
		c1 = edge[i][0];
		c2 = edge[i][1];//获取弧的顶点
		p1 = pos(*G,c1);
		p2 = pos(*G,c2);//获取下标
		node1 = (PLNode)calloc(1, sizeof(LNode));
		node1->ivex = p2;
		if (G->vex[p1].first_edge == NULL)
			G->vex[p1].first_edge = node1;
		else
			last(G->vex[p1].first_edge,node1);
		node2 = (PLNode)calloc(1, sizeof(LNode));
		node2->ivex = p1;
		if (G->vex[p2].first_edge == NULL)
			G->vex[p2].first_edge = node2;
		else
			last(G->vex[p2].first_edge, node2);
	}
	return G;

}
//创建有向图	
Graph* createdirgraph()
{
	int i = 0, p1 = 0, p2 = 0;
	PLNode node = NULL;
	char c1 = 0, c2 = 0;
	Graph* G;
	if(NULL==(G=(Graph*)calloc(1,sizeof(Graph))))
		return NULL;
	int v = 0, e = 0;
	printf("请输入顶点个数和边的条数：\n");
	scanf("%d%d", &v, &e);
	G->vexnum = v;
	G->edgenum = e;
	for (i = 0; i < G->vexnum; i++)
	{
		printf("请输入顶点%d：\n", i+1);
		G->vex[i].data = read_char();
	}
	for (i = 0; i < G->edgenum; i++)
	{
		printf("请输入边%d:\n", i+1);
		c1 = read_char();
		c2 = read_char();
		p1 = pos(*G,c1);
		p2 = pos(*G,c2);
		node = (PLNode)calloc(1, sizeof(LNode));
		node->ivex = p2;
		if (G->vex[i].first_edge == NULL)
			G->vex[i].first_edge = node;
		else
			last(G->vex[i].first_edge, node);
	}
	return G;
}
//给定数据创建有向图
Graph* mycreatedirgraph()
{
	Graph* G;
	if (NULL == (G = (Graph*)calloc(1, sizeof(Graph))))
		return NULL;
	char vex[] = { 'a','b','c','d','e','f' };//初始顶点数组
	char edge[][2] =
	{
	{'a','b'},{'a','c'}, {'b','d'}, {'e','a'}, {'d','e'}
	};//初始化边

	int vlen = length(vex);//获取顶点个数
	int elen = length(edge);//获取边的个数
	//下面根据已有数据建图,和手动创键一致
	int i = 0, p1 = 0, p2 = 0;
	char c1 = 0, c2 = 0;
	PLNode node1 = NULL, node2 = NULL;
	G->vexnum = vlen;
	G->edgenum = elen;
	for (i = 0; i < G->vexnum; i++)//初始化顶点
	{
		G->vex[i].data = vex[i];
	}
	for (i = 0; i < G->edgenum; i++)//初始化邻接表的边
	{
		c1 = edge[i][0];
		c2 = edge[i][1];//获取弧的顶点
		p1 = pos(*G, c1);
		p2 = pos(*G, c2);//获取下标
		node1 = (PLNode)calloc(1, sizeof(LNode));
		node1->ivex = p2;
		if (G->vex[p1].first_edge == NULL)
			G->vex[p1].first_edge = node1;
		else
			last(G->vex[p1].first_edge, node1);
	}
	return G;
}
//打印图的邻接表
void printgraph(Graph *G)
{
	int i = 0;
	PLNode node = NULL;
	printf("Graph:\n");
	for (i = 0; i < G->vexnum; i++)
	{
		printf("%d(%c): ",i,G->vex[i].data);
		node = G->vex[i].first_edge;
		while (node)
		{
			printf("%d(%c) ",node->ivex,G->vex[node->ivex].data);
			node = node->next_edge;
		}
		printf("\n");
	}
}
//DFS的递归实现
void DFS(Graph G,int i,int visited[])
{
	PLNode node = NULL;
	visited[i] = 1;
	printf("%c ", G.vex[i].data);//要访问当前结点,打印
	node = G.vex[i].first_edge;//拿当前结点的后一个结点
	while (node)
	{
		if (!visited[node->ivex])//只要对应结点没有访问过，深入到下一个结点访问
			DFS(G,node->ivex,visited);
		node = node->next_edge;//某个结点的下一条边
	}
}
//图的深度优先搜索
void DFStraverse(Graph* G)
{
	int i = 0;
	int visited[MAX];//顶点访问标记
	for (i = 0; i < G->vexnum; i++)//初始化所有顶点都未被访问，置为0
		visited[i] = 0;
	printf("DFS: ");
	for (i=0;i<G->vexnum;i++)//从第一个输入的顶点进行DFS遍历
	{
		if (!visited[i])
			DFS(*G,i,visited);
	}
	printf("\n");
}
//广度优先搜索
void BFStraverse(Graph G)
{
	int head = 0, rear = 0;//队列的头尾“指针”
	int queue[MAX];//辅助队列
	int i = 0, j = 0, k = 0;
	int visited[MAX];//顶点访问标记
	PLNode node = NULL;
	for (i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	printf("BFS:");
	for (i = 0; i < G.vexnum; i++)//从第一个输入的顶点开始边遍历
	{
		if (!visited[i])
		{
			visited[i] = 1;
			printf("%c ", G.vex[i].data);//打印此顶点
			queue[rear++] = i;//入队，尾指针后移
		}
		while (head != rear)//打印过某结点后遍历它的边
		{
			j = queue[head++];//出队
			node = G.vex[j].first_edge;//取到第一条边的结点
			while (node)
			{
				k = node->ivex;//取到此结点的顶点在顶点数组的下标
				if (!visited[k])
				{
					visited[k] = 1;
					printf("%c ", G.vex[k].data);//打印此顶点
					queue[rear++] = k;
				}
				node = node->next_edge;
			}
		}
	}
	printf("\n");
}

int main()
{
	Graph *G;
	//G = creatgraph();//标准输入创建无向图
	G = mycreatgraph();//根据已有数据创建无向图
	//G = createdirgraph();//标准输入创建有向图
	//G = mycreatedirgraph();//根据已有数据创建有向图 
	printgraph(G);//打印图的邻接表
	DFStraverse(G);//深度优先搜索遍历
	BFStraverse(*G);//广度优先搜索


	return 0;
}