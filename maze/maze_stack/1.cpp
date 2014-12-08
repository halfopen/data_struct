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
	{
		if(mousemove()==1)
		{	//MessageBox(NULL, "按回车开始走迷宫，每次走一步", "通知", MB_OK);
			puts("迷宫：");
				for(int i=0;i<10;i++)
		{	for(int j=0;j<10;j++)
				if(fkm[j][i]!=0)printf(" %2d ",fkm[j][i]);
				else printf("    ");
			puts("");

		}
			
			if(mgpath(1,1,8,8))
			{int ret;ret=MessageBox(NULL,"找到出口了，是否继续？","迷宫",MB_YESNO | MB_SYSTEMMODAL );
				if(ret==IDYES)
				{
						goto sta;
				}
				else
					break;
			}
			else
				{int ret;ret=MessageBox(NULL,"没有找到出口，是否继续？","迷宫",MB_YESNO | MB_SYSTEMMODAL );
				if(ret==IDYES)
				{
						goto sta;
				}
				else
					break;
			}
		}
	}

	


	closegraph();                 /*图形结束*/
}

bool mgpath(int xi,int yi,int xe,int ye)
{	int j,i,di,find;
	StType st;
	st.top = -1;
	st.top++;
	st.data[st.top].i=xi;st.data[st.top].j=yi;
	st.data[st.top].di=-1;fkm[xi][yi]=-1;//-1表示不可走
	puts("\t\t按回车开始走迷宫");
	for( i=80;i<320;i+=30)
		for(j=130;j<370;j+=30)
		{	setcolor(BLUE);
			showFk(i,j,6);
			rectangle(i+4,j+4,i+24,j+24);
		}

	while(st.top>-1)
	{	i = st.data[st.top].i;j = st.data[st.top].j;
		di = st.data[st.top].di;
		if(i==xe && j==ye)//找到出口
		{	puts("最终路径：");for(int k=0;k<=st.top;k++)
			{	printf("\t(%d, %d)",st.data[k].i,st.data[k].j);
			}
			return true;
		}
		puts("当前栈内元素：");for(int k=0;k<=st.top;k++)
			{	printf("\t(%d, %d)",st.data[k].i,st.data[k].j);
			}
		puts("");
		find = 0;
		while(di<4 && find == 0)
		{	di++;
			switch(di)
			{	case 3:i=st.data[st.top].i-1;j=st.data[st.top].j;break;//四个方向
				case 2:i=st.data[st.top].i;j=st.data[st.top].j+1;break;
				case 1:i=st.data[st.top].i+1;j=st.data[st.top].j;break;
				case 0:i=st.data[st.top].i;j=st.data[st.top].j-1;break;				
			}
			printf("当前方向: %d 当前位置:(%d,%d)\n",di,i,j);
			if(fkm[i][j] == 0)
			{
				find = 1;//可走
			}
		}
		//printf("i:%d j:%d\n",i,j);
		if(find ==1)
		{	st.data[st.top].di=di;
			st.top++;//下一个可走方块进栈
			st.data[st.top].i = i;st.data[st.top].j=j;
			st.data[st.top].di = -1;
			getch();
			//printf("可走%d %d ",i*30+50,i*30+100);
			showFk(st.data[st.top].i*30+50,st.data[st.top].j*30+100,-1);
			if(st.top>=1)showFk(st.data[st.top-1].i*30+50,st.data[st.top-1].j*30+100,6);
			showFk(st.data[st.top].i*30+50,st.data[st.top].j*30+100,5);
			fkm[i][j] = -1;//这个暂时不可走，避免重复走到该方块
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