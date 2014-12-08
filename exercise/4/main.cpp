/*
**数据结构综合实验题4
**主函数
**By:秦贤康
**2014－12－03 22:26
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"


int visited[MAXV];

void printMenu();

int main()
{	int path[MAXV], u = 1,v = 4,i,j;			//path路径,u,v起终点,i,j计数
	char choose,req[MAXV],nreq[MAXV],c;			//req必过点,nreq必不过点
	MGraph g;
	ALGraph *G;
	g.n = 15;g.e = 20;					//节点数和边数

	int A[MAXV][MAXV] = {					//图的邻接矩阵表示
	//行\列0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14
	/* 0*/{0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/* 1*/{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
	/* 2*/{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	/* 3*/{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	/* 4*/{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	/* 5*/{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
	/* 6*/{0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
	/* 7*/{0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
	/* 8*/{0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
	/* 9*/{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0},
	/*10*/{0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
	/*11*/{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
	/*12*/{0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
	/*13*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
	/*14*/{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0}
	};

	for(i = 0;i<g.n;i++)
		for(j = 0;j<g.n;j++)
			g.edges[i][j] = A[i][j];		//输入图
	MatToList(g, G);					//矩阵转邻接表
	memset(visited, 0, sizeof(visited));			//重置visited
    	while(printMenu(),puts("enter you choice "),choose=getchar())
	{	
		switch(choose)
		{	case '1':				//输出菜单
			{	DispAdj(G);
				puts("show map completed");
			}break;
			case '2':				//输出路径
			{	getchar();
				puts("input a start node u and end node v,blank space to depart them,enter to end input");
				//fflush(stdin);
				scanf("%d%d",&u,&v);
                                getchar();
				u = u % g.n; v = v % g.n;
                                puts("input the nodes must cross");					//必须经过的点的输入
                                i = 0;memset(req,0,sizeof(req));
                                while(scanf("%c",&choose),choose !='\n')	
                                {       choose = choose -'0';						//g++不支持fflush(stdin);
                                        while(c = getchar(),c!='\n')choose = choose*10+c-'0';           //把字符转为数字                  
                                        req[i] = choose;
                                        i++;
                                }
                                puts("input the nodes don's cross");					//必不过的点的输入
                                i = 0;memset(nreq,0,sizeof(nreq));
                                while(scanf("%c",&choose),choose !='\n')
                                {       choose = choose -'0';
                                        while(c = getchar(),c!='\n')choose = choose*10+c-'0';           
                                        nreq[i] = choose;
                                        i++;
                                }
				printf("ways from %d to %d\n",u,v);
				PathAll(G,u,v,path,-1,req,nreq);					//输出路径
				puts("show ways completed!");
			}break;
			case '0':				//退出
			{exit(0);
			}break;
			default:				//有可能考虑的其他情况,保留下来
			{continue;}
		}
		puts("press any key to continue");getchar();getchar();
	}
	return 0;
}

//输出菜单
void printMenu()
{	puts("----------------------exercise 4.Map--------------");
	puts("-\t1.show the map");
	puts("-\t2.input a start node u and end node v");
	puts("-\t0.quit");
	puts("------------------------------------------------");
}
