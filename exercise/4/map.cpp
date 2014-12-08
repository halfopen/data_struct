/*
**���ݽṹ�ۺ�ʵ����4
**ͼ��ʵ��Դ�ļ���ͼ����Ļ������ܵ�ʵ��
**By:���Ϳ�
**2014��12��03 22:26
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

//��ӡ�ڽӱ�
void DispAdj(ALGraph *G)
{	int n = G->n, i;
	ArcNode *p;
	for(i=0;i<n ;i++)
	{	p = G->adjlist[i].firstarc;
		printf("\t%d: ",i);
		while(p!=NULL)
		{	printf("%2d ",p->adjvex);
			p = p->nextarc;
		}
		puts("");
	}
}

//�ڽӾ���ת�ڽӱ�
void MatToList(MGraph g, ALGraph * &G)
{	int i,j;
	ArcNode *p;
	G = (ALGraph * )malloc(sizeof(ALGraph));
	for(i= 0; i<g.n; i++)
	{	G->adjlist[i].firstarc = NULL; };
	for(i= 0;i<g.n; ++i)
	{	for(j = g.n-1;j>=0;--j)
		{	if(g.edges[i][j] != 0)
			{	p = (ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->n = g.n;
	G->e = g.e;
};
void ListToMat(ALGraph *G, MGraph &g)
{	int i;
	ArcNode *p;
	for(i = 0;i<G->n; ++i)
	{	p = G->adjlist[i].firstarc;
		while(NULL !=p)
		{	g.edges[i][p->adjvex] = 1;
			p = p->nextarc;
		}
	}
	g.n = G->n;
	g.e = G->e;
}

void DFS(ALGraph *G, int v)
{	ArcNode * p;
	visited[v] = 1;
	printf("%d", v);
	p = G->adjlist[v].firstarc;
	while(NULL !=p)
	{	if(0 == visited[p->adjvex] )
		{	DFS(G,p->adjvex);}
		p = p->nextarc;
	}
}
void BFS(ALGraph *G, int v);

//���·��
void PathAll(ALGraph * G, int u,int v,int path[],int d, char req[], char nreq[])
{   int w, i, reqlen=0,nreqlen=0,j,flag = 1,has=0;
    ArcNode *p;
    visited[u] = 1;								//����Ѿ�����
    d++;path[d] = u;
    if(u == v )									//�ҵ�һ��·��
    { 		if(strlen(nreq)>0 || strlen(req)>0 )				//������⾭����Ͳ��������Ҫ��
		{	j = d;
			//printf("%d %d",nreqlen,reqlen);
			while(j-->0 && flag == 1)				//�����еĵ�
			{	nreqlen = strlen(nreq);
				while(nreqlen-- >0)				//�������ܾ����ĵ�
				{	if(path[j] == *(nreq+nreqlen)){flag = 0;break;};
				}
			}
			reqlen = strlen(req);
			while(reqlen-->0)					//���뾭���ĵ�
			{	j = d;has = 0;
				while(j--)					//ɨ��һ��path,path�����Ҫ��req�ĵ�һ��
				{	if(path[j] == *(req+reqlen)){has=1;continue;}
				}
				if(has ==0){flag = 0;break;}
				//puts("has");
			}
			//printf("\tflag:%d\n",flag);
		}
		if(flag == 1)							//���·��
		{	printf(" ");
			for(i=0;i<=d;i++)
			{   printf(" %2d",path[i]);
			}
			printf("\n");
			flag = true;
		}
    }
    p = G->adjlist[u].firstarc;
    while(NULL !=p)
    {   w = p->adjvex;
        if(0== visited[w])
            PathAll(G,w,v,path,d, req, nreq);
        p = p->nextarc;
    }
    visited[u]=0;
}
