#include <graphics.h>
#include "function.h"
#include <conio.h>
#include <time.h>
#include <stdio.h>

int fkm[10][10];	//�����Թ�

typedef struct
{	int i;
	int j;
	int pre;
}Box;				//ÿ��������Ϣ
typedef struct{
	Box data[120];
	int front, rear;
}QuType;			//���ж���
bool mgpath(int xi,int yi,int xe,int ye);
void print(QuType qu, int front);
void main(void)
{
sta:
	reset();
	puts("\t\t\t\t˵����\n");
	puts("1��������������ǽ�ڣ��Ҽ�ȡ�����");
	puts("2��˫�����Ͻ���S��ʼ���Թ�");
	puts("3�����س�������һ��\n");
	for(int i=0;i<10;i++)
	{	for(int j=0;j<10;j++)
				if(fkm[j][i]!=0)printf(" %2d ",fkm[j][i]);
				else printf("    ");
		puts("");

	}
	while(1)
	{	if(mousemove()==1)
		{	puts("�Թ���");
			for(int i=0;i<10;i++)
			{	for(int j=0;j<10;j++)
					if(fkm[j][i]!=0)printf(" %2d ",fkm[j][i]);
					else printf("    ");
					puts("");
			}
			if(mgpath(1,1,8,8))
			{	int ret;ret=MessageBox(NULL,"�ҵ������ˣ��Ƿ������","�Թ�",MB_YESNO | MB_SYSTEMMODAL );
				if(ret==IDYES)goto sta;
				else break;
			}
			else
			{	int ret;ret=MessageBox(NULL,"û���ҵ����ڣ��Ƿ������","�Թ�",MB_YESNO | MB_SYSTEMMODAL );
				if(ret==IDYES)goto sta;
				else break;
			}
		}
	}
	closegraph();                 /*ͼ�ν���*/
}

bool mgpath(int xi,int yi,int xe,int ye)
{	int j,i,di,find=0;
	QuType qu;
	qu.rear = qu.front = -1;
	qu.rear ++;
	qu.data[qu.rear].i = xi; qu.data[qu.rear].j = yi;
	qu.data[qu.rear].pre = -1;
	fkm[xi][yi] = -1;
	puts("\t\t���س���ʼ���Թ�");
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
		if(i==xe && j==ye)		//�ҵ�����
		{	find = 1;
			printf("��·��");
			print(qu, qu.front);
			return true;
		}
		puts("");
		for(di = 0;di<4;di++)
		{	switch(di)
			{	case 3:i=qu.data[qu.front].i-1;j=qu.data[qu.front].j;break;//�ĸ�����
				case 2:i=qu.data[qu.front].i;j=qu.data[qu.front].j+1;break;
				case 1:i=qu.data[qu.front].i+1;j=qu.data[qu.front].j;break;
				case 0:i=qu.data[qu.front].i;j=qu.data[qu.front].j-1;break;				
			}
			printf("��ǰ����: %d ��ǰλ��:(%d,%d)\n",di,i,j);
			if(fkm[i][j] == 0)
			{	if(i==xe && j==ye)	//�ҵ�����
				{	printf("fff %d %d\n",qu.front,qu.rear);
					for(int l=qu.front;l<=qu.rear;l++)
					{	showFk(qu.data[l].i*30+50,qu.data[l].j*30+100,0);
						printf("%d,%d\n",qu.data[l].i, qu.data[l].j);
						setcolor(BLUE);
						rectangle(qu.data[l].i*30+50+4,qu.data[l].j*30+100+4,qu.data[l].i*30+50+24,qu.data[l].j*30+100+24);
					}
					printf("���·��");
					print(qu, qu.front);
					return true;
				}
				qu.rear++;
				qu.data[qu.rear].i = i; qu.data[qu.rear].j=j;
				qu.data[qu.rear].pre = qu.front;
				printf("����%d %d\n",i,j);
				showFk(qu.data[qu.rear].i*30+50,qu.data[qu.rear].j*30+100,-1);
				showFk(qu.data[qu.rear].i*30+50,qu.data[qu.rear].j*30+100,5);
				fkm[i][j] = -1;
				getch();		
			}
		}
	}
	return false;

}
void print(QuType qu, int front)			//��ӡ·��
{	int k = front,j,ns = 0;
	printf("\n");
	do
	{	j = k;
		k = qu.data[k].pre;
		qu.data[j].pre = -1;
	}while(0 != k);
	puts("�Թ�·������");
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