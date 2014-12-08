/*
**数据结构综合实验题4
**图数据结构的头文件，结构声明
**By:秦贤康
**2014－12－03 22:26
*/
#ifndef _MAP_H_
#define _MAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 64
#define InfoType int
#define Vertex int

extern int visited[MAXV];

typedef struct
{	int no;
	InfoType info;
}VertexType;
typedef struct
{	int edges[MAXV][MAXV];
	int n, e;
	VertexType vexs[MAXV];
}MGraph;


//邻接表
typedef struct ANode
{	int adjvex;
	struct ANode * nextarc;
	InfoType info;
}ArcNode;
typedef struct Vnode
{	Vertex data;
	ArcNode * firstarc;
}VNode;
typedef VNode AdjList[MAXV];
typedef struct
{	AdjList adjlist;
	int n,e;
}ALGraph;

void DispAdj(ALGraph *G);
void MatToList(MGraph g, ALGraph * &G);
void ListToMat(ALGraph *G, MGraph &g);
void DFS(ALGraph *G, int v);
void BFS(ALGraph *G, int v);
void PathAll(ALGraph * G, int u,int v,int path[],int d, char req[], char nreq[]);
#endif
