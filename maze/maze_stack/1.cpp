#include <graphics.h>
#include "function.h"
#include <conio.h>
#include <time.h>
#include <stdio.h>

int fkm[10][10];

typedef struct
{	int i;
	int j;
	int di;
}Box;
typedef struct
{	Box data[120];
	int top;
}StType;
bool mgpath(int xi,int yi,int xe,int ye);
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
	{
		if(mousemove()==1)
		{	//MessageBox(NULL, "���س���ʼ���Թ���ÿ����һ��", "֪ͨ", MB_OK);
			puts("�Թ���");
				for(int i=0;i<10;i++)
		{	for(int j=0;j<10;j++)
				if(fkm[j][i]!=0)printf(" %2d ",fkm[j][i]);
				else printf("    ");
			puts("");

		}
			
			if(mgpath(1,1,8,8))
			{int ret;ret=MessageBox(NULL,"�ҵ������ˣ��Ƿ������","�Թ�",MB_YESNO | MB_SYSTEMMODAL );
				if(ret==IDYES)
				{
						goto sta;
				}
				else
					break;
			}
			else
				{int ret;ret=MessageBox(NULL,"û���ҵ����ڣ��Ƿ������","�Թ�",MB_YESNO | MB_SYSTEMMODAL );
				if(ret==IDYES)
				{
						goto sta;
				}
				else
					break;
			}
		}
	}

	


	closegraph();                 /*ͼ�ν���*/
}

bool mgpath(int xi,int yi,int xe,int ye)
{	int j,i,di,find;
	StType st;
	st.top = -1;
	st.top++;
	st.data[st.top].i=xi;st.data[st.top].j=yi;
	st.data[st.top].di=-1;fkm[xi][yi]=-1;//-1��ʾ������
	puts("\t\t���س���ʼ���Թ�");
	for( i=80;i<320;i+=30)
		for(j=130;j<370;j+=30)
		{	setcolor(BLUE);
			showFk(i,j,6);
			rectangle(i+4,j+4,i+24,j+24);
		}

	while(st.top>-1)
	{	i = st.data[st.top].i;j = st.data[st.top].j;
		di = st.data[st.top].di;
		if(i==xe && j==ye)//�ҵ�����
		{	puts("����·����");for(int k=0;k<=st.top;k++)
			{	printf("\t(%d, %d)",st.data[k].i,st.data[k].j);
			}
			return true;
		}
		puts("��ǰջ��Ԫ�أ�");for(int k=0;k<=st.top;k++)
			{	printf("\t(%d, %d)",st.data[k].i,st.data[k].j);
			}
		puts("");
		find = 0;
		while(di<4 && find == 0)
		{	di++;
			switch(di)
			{	case 3:i=st.data[st.top].i-1;j=st.data[st.top].j;break;//�ĸ�����
				case 2:i=st.data[st.top].i;j=st.data[st.top].j+1;break;
				case 1:i=st.data[st.top].i+1;j=st.data[st.top].j;break;
				case 0:i=st.data[st.top].i;j=st.data[st.top].j-1;break;				
			}
			printf("��ǰ����: %d ��ǰλ��:(%d,%d)\n",di,i,j);
			if(fkm[i][j] == 0)
			{
				find = 1;//����
			}
		}
		//printf("i:%d j:%d\n",i,j);
		if(find ==1)
		{	st.data[st.top].di=di;
			st.top++;//��һ�����߷����ջ
			st.data[st.top].i = i;st.data[st.top].j=j;
			st.data[st.top].di = -1;
			getch();
			//printf("����%d %d ",i*30+50,i*30+100);
			showFk(st.data[st.top].i*30+50,st.data[st.top].j*30+100,-1);
			if(st.top>=1)showFk(st.data[st.top-1].i*30+50,st.data[st.top-1].j*30+100,6);
			showFk(st.data[st.top].i*30+50,st.data[st.top].j*30+100,5);
			fkm[i][j] = -1;//�����ʱ�����ߣ������ظ��ߵ��÷���
		}
		else
		{	fkm[ st.data[st.top].i][st.data[st.top].j]=0;
			getch();
			showFk(st.data[st.top].i*30+50,st.data[st.top].j*30+100,2);
			st.top--;
		}
	}
	return false;

}