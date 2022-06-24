#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 50
#define isletter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))//�ж��Ƿ�����ĸ
#define length(a)  (sizeof(a)/sizeof(a[0])) //���㳤��
typedef char VertexType;//��������
//ͼ���ڽӱ��ʾ������ṹ
typedef struct LNode
{
	int ivex;//ָ��ĵ���±�
	struct Lnode* next_edge;//��һ������ָ��
}LNode,*PLNode;
//ͼ���ڽӱ��ʾ�Ķ���ṹ
typedef struct Vnode
{
	VertexType data;//ͼ����
	PLNode first_edge;//ָ���һ�������ö���Ļ�

}Vnode;
//�ڽӱ�
typedef struct Graph
{
	int vexnum;//������
	int edgenum;//����
	Vnode vex[MAX];//��������	
}Graph;

//��ȡһ����ĸ
char read_char()
{
	char c = 0;
	do {
		c = getchar();
	} while (!isletter(c));
	return c;
}
//��ȡ��ĸ�ڶ��������е��±�
int pos(Graph G,char c)
{
	int i = 0;
	for (i = 0; i < G.vexnum; i++)//������������
		if (G.vex[i].data == c)//���ظ���ĸ�±�
			return i;
	return -1;

}

//������������β
void last(PLNode L,PLNode node)
{
	PLNode p = L;
	while (p->next_edge)
		p = p->next_edge;
	p->next_edge = node;
}
//����ͼ�Ĵ���
Graph* creatgraph()
{
	int v = 0, e = 0;//�涥�����ͱ���
	int i = 0;//��ʱ������������
	char c1 = 0, c2 = 0;//��ʼ����ʱʹ��
	int p1 = 0, p2 = 0;//��ʼ����ʱ��Ŷ����±�
	PLNode node1 = NULL, node2 = NULL;//��ʼ����������ڵ��ߵ���������
	Graph* G;
	if (NULL == (G = (Graph*)calloc(1, sizeof(Graph))))//����ռ���0
		return NULL;
	printf("���붥������������\n");
	i = scanf("%d%d",&v,&e);
	G->vexnum = v;//����
	G->edgenum = e;//��
	for (i = 0; i < G->vexnum; i++)//��ʼ���ڽӱ�Ķ���
	{
		printf("���붥��%d��\n",i+1);
		G->vex[i].data = read_char();//��ȡ��ȷ����ĸ
	}
	for (i = 0; i < G->edgenum; i++)//��ʼ����
	{
		printf("��%d\n", i+1);
		c1 = read_char();//�涥��
		c2 = read_char();//�涥��
		p1 = pos(*G,c1);//�����±�
		p2 = pos(*G,c2);//�����±�
		node1 = (PLNode)calloc(1, sizeof(LNode));//����ڵ�
		node1->ivex = p2;//��ͷ
		if (G->vex[p1].first_edge == NULL)
			G->vex[p1].first_edge = node1;//��p1λ�õĶ���û�е�һ���ߡ���node1���ں���
		else  //����node1���������
			last(G->vex[p1].first_edge, node1);
		//����ͼ��������һ������ͬ���Ĳ���
		node2 = (PLNode)calloc(1, sizeof(LNode));//����ڵ�
		node2->ivex = p1;//��ͷ
		if (G->vex[p2].first_edge == NULL)
			G->vex[p2].first_edge = node2;//��p1λ�õĶ���û�е�һ���ߡ���node1���ں���
		else  //����node1���������
			last(G->vex[p2].first_edge, node2);
	}
	return G;
}
//����ͼ���ֶ�����
Graph* mycreatgraph()
{
	Graph* G;
	if (NULL == (G = (Graph*)calloc(1, sizeof(Graph))))
		return NULL;
	char vex[] = { 'a','b','c','d','e','f'};//��ʼ��������
	char edge[][2] = 
	{
	{'a','f'},{'e','c'}, {'b','c'}, {'e','f'}, {'d','e'}
	};//��ʼ����

	int vlen = length(vex);//��ȡ�������
	int elen = length(edge);//��ȡ�ߵĸ���
	//��������������ݽ�ͼ,���ֶ�����һ��
	int i = 0,p1 = 0, p2 = 0;
	char c1 = 0, c2 = 0;
	PLNode node1 = NULL, node2 = NULL;
	G->vexnum = vlen;
	G->edgenum = elen;
	for (i = 0; i < G->vexnum; i++)//��ʼ������
	{
		G->vex[i].data = vex[i];
	}
	for (i = 0; i < G->edgenum; i++)//��ʼ���ڽӱ�ı�
	{
		c1 = edge[i][0];
		c2 = edge[i][1];//��ȡ���Ķ���
		p1 = pos(*G,c1);
		p2 = pos(*G,c2);//��ȡ�±�
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
//��������ͼ	
Graph* createdirgraph()
{
	int i = 0, p1 = 0, p2 = 0;
	PLNode node = NULL;
	char c1 = 0, c2 = 0;
	Graph* G;
	if(NULL==(G=(Graph*)calloc(1,sizeof(Graph))))
		return NULL;
	int v = 0, e = 0;
	printf("�����붥������ͱߵ�������\n");
	scanf("%d%d", &v, &e);
	G->vexnum = v;
	G->edgenum = e;
	for (i = 0; i < G->vexnum; i++)
	{
		printf("�����붥��%d��\n", i+1);
		G->vex[i].data = read_char();
	}
	for (i = 0; i < G->edgenum; i++)
	{
		printf("�������%d:\n", i+1);
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
//�������ݴ�������ͼ
Graph* mycreatedirgraph()
{
	Graph* G;
	if (NULL == (G = (Graph*)calloc(1, sizeof(Graph))))
		return NULL;
	char vex[] = { 'a','b','c','d','e','f' };//��ʼ��������
	char edge[][2] =
	{
	{'a','b'},{'a','c'}, {'b','d'}, {'e','a'}, {'d','e'}
	};//��ʼ����

	int vlen = length(vex);//��ȡ�������
	int elen = length(edge);//��ȡ�ߵĸ���
	//��������������ݽ�ͼ,���ֶ�����һ��
	int i = 0, p1 = 0, p2 = 0;
	char c1 = 0, c2 = 0;
	PLNode node1 = NULL, node2 = NULL;
	G->vexnum = vlen;
	G->edgenum = elen;
	for (i = 0; i < G->vexnum; i++)//��ʼ������
	{
		G->vex[i].data = vex[i];
	}
	for (i = 0; i < G->edgenum; i++)//��ʼ���ڽӱ�ı�
	{
		c1 = edge[i][0];
		c2 = edge[i][1];//��ȡ���Ķ���
		p1 = pos(*G, c1);
		p2 = pos(*G, c2);//��ȡ�±�
		node1 = (PLNode)calloc(1, sizeof(LNode));
		node1->ivex = p2;
		if (G->vex[p1].first_edge == NULL)
			G->vex[p1].first_edge = node1;
		else
			last(G->vex[p1].first_edge, node1);
	}
	return G;
}
//��ӡͼ���ڽӱ�
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
//DFS�ĵݹ�ʵ��
void DFS(Graph G,int i,int visited[])
{
	PLNode node = NULL;
	visited[i] = 1;
	printf("%c ", G.vex[i].data);//Ҫ���ʵ�ǰ���,��ӡ
	node = G.vex[i].first_edge;//�õ�ǰ���ĺ�һ�����
	while (node)
	{
		if (!visited[node->ivex])//ֻҪ��Ӧ���û�з��ʹ������뵽��һ��������
			DFS(G,node->ivex,visited);
		node = node->next_edge;//ĳ��������һ����
	}
}
//ͼ�������������
void DFStraverse(Graph* G)
{
	int i = 0;
	int visited[MAX];//������ʱ��
	for (i = 0; i < G->vexnum; i++)//��ʼ�����ж��㶼δ�����ʣ���Ϊ0
		visited[i] = 0;
	printf("DFS: ");
	for (i=0;i<G->vexnum;i++)//�ӵ�һ������Ķ������DFS����
	{
		if (!visited[i])
			DFS(*G,i,visited);
	}
	printf("\n");
}
//�����������
void BFStraverse(Graph G)
{
	int head = 0, rear = 0;//���е�ͷβ��ָ�롱
	int queue[MAX];//��������
	int i = 0, j = 0, k = 0;
	int visited[MAX];//������ʱ��
	PLNode node = NULL;
	for (i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	printf("BFS:");
	for (i = 0; i < G.vexnum; i++)//�ӵ�һ������Ķ��㿪ʼ�߱���
	{
		if (!visited[i])
		{
			visited[i] = 1;
			printf("%c ", G.vex[i].data);//��ӡ�˶���
			queue[rear++] = i;//��ӣ�βָ�����
		}
		while (head != rear)//��ӡ��ĳ����������ı�
		{
			j = queue[head++];//����
			node = G.vex[j].first_edge;//ȡ����һ���ߵĽ��
			while (node)
			{
				k = node->ivex;//ȡ���˽��Ķ����ڶ���������±�
				if (!visited[k])
				{
					visited[k] = 1;
					printf("%c ", G.vex[k].data);//��ӡ�˶���
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
	//G = creatgraph();//��׼���봴������ͼ
	G = mycreatgraph();//�����������ݴ�������ͼ
	//G = createdirgraph();//��׼���봴������ͼ
	//G = mycreatedirgraph();//�����������ݴ�������ͼ 
	printgraph(G);//��ӡͼ���ڽӱ�
	DFStraverse(G);//���������������
	BFStraverse(*G);//�����������


	return 0;
}