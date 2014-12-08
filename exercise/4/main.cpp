/*
**���ݽṹ�ۺ�ʵ����4
**������
**By:���Ϳ�
**2014��12��03 22:26
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"


int visited[MAXV];

void printMenu();

int main()
{	int path[MAXV], u = 1,v = 4,i,j;			//path·��,u,v���յ�,i,j����
	char choose,req[MAXV],nreq[MAXV],c;			//req�ع���,nreq�ز�����
	MGraph g;
	ALGraph *G;
	g.n = 15;g.e = 20;					//�ڵ����ͱ���

	int A[MAXV][MAXV] = {					//ͼ���ڽӾ����ʾ
	//��\��0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14
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
			g.edges[i][j] = A[i][j];		//����ͼ
	MatToList(g, G);					//����ת�ڽӱ�
	memset(visited, 0, sizeof(visited));			//����visited
    	while(printMenu(),puts("enter you choice "),choose=getchar())
	{	
		switch(choose)
		{	case '1':				//����˵�
			{	DispAdj(G);
				puts("show map completed");
			}break;
			case '2':				//���·��
			{	getchar();
				puts("input a start node u and end node v,blank space to depart them,enter to end input");
				//fflush(stdin);
				scanf("%d%d",&u,&v);
                                getchar();
				u = u % g.n; v = v % g.n;
                                puts("input the nodes must cross");					//���뾭���ĵ������
                                i = 0;memset(req,0,sizeof(req));
                                while(scanf("%c",&choose),choose !='\n')	
                                {       choose = choose -'0';						//g++��֧��fflush(stdin);
                                        while(c = getchar(),c!='\n')choose = choose*10+c-'0';           //���ַ�תΪ����                  
                                        req[i] = choose;
                                        i++;
                                }
                                puts("input the nodes don's cross");					//�ز����ĵ������
                                i = 0;memset(nreq,0,sizeof(nreq));
                                while(scanf("%c",&choose),choose !='\n')
                                {       choose = choose -'0';
                                        while(c = getchar(),c!='\n')choose = choose*10+c-'0';           
                                        nreq[i] = choose;
                                        i++;
                                }
				printf("ways from %d to %d\n",u,v);
				PathAll(G,u,v,path,-1,req,nreq);					//���·��
				puts("show ways completed!");
			}break;
			case '0':				//�˳�
			{exit(0);
			}break;
			default:				//�п��ܿ��ǵ��������,��������
			{continue;}
		}
		puts("press any key to continue");getchar();getchar();
	}
	return 0;
}

//����˵�
void printMenu()
{	puts("----------------------exercise 4.Map--------------");
	puts("-\t1.show the map");
	puts("-\t2.input a start node u and end node v");
	puts("-\t0.quit");
	puts("------------------------------------------------");
}
