#include <graphics.h>
#include "function.h"
#include <conio.h>
#include <time.h>
#include <stdio.h>

int fkm[10][10];	//保存迷宫

typedef struct
{	int i;
	int j;
	int pre;
}Box;				//每个方块信息
typedef struct{
	Box data[120];
	int front, rear;
}QuType;			//队列定义
bool mgpath(int xi,int yi,int xe,int ye);
void print(QuType qu, int front);
void main(void)
{
sta:
	reset();
	puts("\t\t\t\t说明：\n");
	puts("1、鼠标左键点击添加墙壁，右键取消添加");
	puts("2、双击左上角在S开始走迷宫");
	puts("3、按回车键走下一步\n");
	for(int i=0;i<10;i++)
	{	for(int j=0;j<10;j++)
				if(fkm[j][i]!=0)printf(" %2d ",fkm[j][i]);
				else printf("    ");
		puts("");

	}
	while(1)
	{	if(mousemove()==1)
		{	puts("迷宫：");
			for(int i=0;i<10;i++)
			{	for(int j=0;j<10;j++)
					if(fkm[j][i]!=0)printf(" %2d ",fkm[j][i]);
					else printf("    ");
					puts("");
			}
			if(mgpath(1,1,8,8))
			{	int ret;ret=MessageBox(NULL,"找到出口了，是否继续？","迷宫",MB_YESNO | MB_SYSTEMMODAL );
				if(ret==IDYES)goto sta;
				else break;
			}
			else
			{	int ret;ret=MessageBox(NULL,"没有找到出口，是否继续？","迷宫",MB_YESNO | MB_SYSTEMMODAL );
				if(ret==IDYES)goto sta;
				else break;
			}
		}
	}
	closegraph();                 /*图形结束*/
}

bool mgpath(int xi,int yi,int xe,int ye)
{	int j,i,di,find=0;
	QuType qu;
	qu.rear = qu.front = -1;
	qu.rear ++;
	qu.data[qu.rear].i = xi; qu.data[qu.rear].j = yi;
	qu.data[qu.rear].pre = -1;
	fkm[xi][yi] = -1;
	puts("\t\t按回车开始走迷宫");
	for( i=80;i<320;i+=30)
		for(j=130;j<370;j+=30)
		{	setcolor(BLUE);
			//showFk(i,j,6);
			rectangle(i+4,j+4,i+24,j+24);
		}
	while(qu.front != qu.rear && !find)
	{	qu.front++;
		showFk(qu.data[qu.front].i*30+50,qu.data[qu.front].j*30+100,0);
		printf("ij %d %d\n",i,j);
		if(i==xe && j==ye)		//找到出口
		{	find = 1;
			printf("打到路径");
			print(qu, qu.front);
			return true;
		}
		puts("");
		for(di = 0;di<4;di++)
		{	switch(di)
			{	case 3:i=qu.data[qu.front].i-1;j=qu.data[qu.front].j;break;//四个方向
				case 2:i=qu.data[qu.front].i;j=qu.data[qu.front].j+1;break;
				case 1:i=qu.data[qu.front].i+1;j=qu.data[qu.front].j;break;
				case 0:i=qu.data[qu.front].i;j=qu.data[qu.front].j-1;break;				
			}
			printf("当前方向: %d 当前位置:(%d,%d)\n",di,i,j);
			if(fkm[i][j] == 0)
			{	if(i==xe && j==ye)	//找到出口
				{	printf("fff %d %d\n",qu.front,qu.rear);
					for(int l=qu.front;l<=qu.rear;l++)
					{	showFk(qu.data[l].i*30+50,qu.data[l].j*30+100,0);
						printf("%d,%d\n",qu.data[l].i, qu.data[l].j);
						setcolor(BLUE);
						rectangle(qu.data[l].i*30+50+4,qu.data[l].j*30+100+4,qu.data[l].i*30+50+24,qu.data[l].j*30+100+24);
					}
					printf("打出路径");
					print(qu, qu.front);
					return true;
				}
				qu.rear++;
				qu.data[qu.rear].i = i; qu.data[qu.rear].j=j;
				qu.data[qu.rear].pre = qu.front;
				printf("进队%d %d\n",i,j);
				showFk(qu.data[qu.rear].i*30+50,qu.data[qu.rear].j*30+100,-1);
				showFk(qu.data[qu.rear].i*30+50,qu.data[qu.rear].j*30+100,5);
				fkm[i][j] = -1;
				getch();		
			}
		}
	}
	return false;

}
void print(QuType qu, int front)			//打印路径
{	int k = front,j,ns = 0;
	printf("\n");
	do
	{	j = k;
		k = qu.data[k].pre;
		qu.data[j].pre = -1;
	}while(0 != k);
	puts("迷宫路径如下");
	k = 0;
	while( k <64)
	{	if(qu.data[k].pre == -1)
		{	ns ++;
			printf("\t( %d, %d)",qu.data[k].i, qu.data[k].j);
			showFk(qu.data[k].i*30+50,qu.data[k].j*30+100,5);
			showFk(qu.data[k].i*30+50,qu.data[k].j*30+100,9);
			if(ns % 5==0)printf("\n");
		}
		k++;
	}
	printf("\n");
}