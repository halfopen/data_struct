#include <graphics.h>
#include "function.h"
#include <conio.h>
#include <time.h>
#include <stdio.h>
bool inreset=false;
bool instart =false;
int inbox(int a,int b,int c,int d,int x,int y)//在方块之内 
{	if(x<a&&x>c&&y<b&&y>d)return 1;
	return 0;
}
bool SetWindowTransparent(HWND hwnd, COLORREF crkcolor, BYTE bAlpha, DWORD dwFlags)
{	HINSTANCE hm = GetModuleHandle(_T("USER32.DLL"));
    if (hm)
    {	FARPROC fun = GetProcAddress(hm, "SetLayeredWindowAttributes");
        bool(WINAPI * SetLayeredWindowAttributes) (HWND, COLORREF, BYTE, DWORD) =
            (bool(WINAPI *) (HWND, COLORREF, BYTE, DWORD)) fun;
        if (SetLayeredWindowAttributes)
        {	 LONG ret = GetWindowLong(hwnd, GWL_EXSTYLE);
            SetWindowLong(hwnd, GWL_EXSTYLE, ret);
            SetLayeredWindowAttributes(hwnd, crkcolor, bAlpha, dwFlags);
        }
        FreeLibrary(hm);
        return true;
    }
    else
        return false;
}

void Frametransparent(HWND hwnd, bool frame)    //
{	long style = GetWindowLong(hwnd, GWL_STYLE);
    if (frame)
        style |= WS_CAPTION;
    else
        style &= ~WS_CAPTION;
    SetWindowLong(hwnd, GWL_STYLE, style);
}

bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)
{	HANDLE hFile = CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        return false;
    HRSRC hRes = FindResource(NULL, strResName, strResType);
    HGLOBAL hMem = LoadResource(NULL, hRes);
    DWORD dwSize = SizeofResource(NULL, hRes);
    DWORD dwWrite = 0;
    WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
    CloseHandle(hFile);
    return true;
}

void Image(char a[],char b[],int x,int y)//在定点处显示图片
{	IMAGE img;
	loadimage(&img,a,b);
	putimage(x,y, &img);
}

int mousemove()//给方块上加边框
{	//if(win==-1)return -1;
	//if(win==1)return 1;
	//Image("gif","R0",50,20);
	//Image("gif","S0",180,20);
	int mx=50,my=350;
	FlushMouseMsgBuffer();
	MOUSEMSG m;
	m = GetMouseMsg();
	int r,t;
	mx=((int)(  (m.x-50)/30  )  )*30+50;
	my=((int)((m.y-100)/30))*30+100;
	if(m.x>50&&m.x<350&&m.y>100&&m.y<400){
	r=(m.x-50)/30;t=(m.y-100)/30;
	if(m.uMsg==WM_LBUTTONDOWN)
	{	
		if(fkm[r][t]==8)return 1;
		if(r!=0 && r !=9 && t !=0 &&t !=100)
		{	
			fkm[r][t]=1;
			showFk(mx,my,fkm[r][t]);
		}
		puts("当前输入：");
		for(int i=0;i<10;i++)
		{	for(int j=0;j<10;j++)
				if(fkm[j][i]!=0)printf(" %2d ",fkm[j][i]);
				else printf("    ");
			puts("");

		}
		puts("");
	}
	else if(m.uMsg==WM_RBUTTONUP)
	{	
		fkm[(m.x-50)/30][(m.y-100)/30]=0;
			showFk(mx,my,fkm[(m.x-50)/30][(m.y-100)/30]);
	}
	}

	if(m.x>50&&m.x<350&&m.y>100&&m.y<400)
	{	for(int i=mx-30;i<=mx+30;i+=30)
			for(int j=my-30;j<=my+30;j+=30)
				if(i>=50&&i<350&&j>=100&&j<400)
				{		setcolor(BLUE);
						rectangle (  i+4  ,j+4 ,i+24,  j+24);
				}
		setcolor(WHITE);
		rectangle(  mx+4  ,my+4  ,mx+24,  my+24 );
	}

	fkm[1][1] = fkm[8][8] = 0;
	showFk(80,130,-1);
	showFk(50+30*8,100+30*8,-1);
	return 0;
}
void showFk(int x,int y,int type)//显示方块
{	char s1[20];
	sprintf(s1, "FK%d",type);	
	Image("gif",s1,x,y);
}//////////////////////////////////////////////////////////////

int reset(void)//重置界面
{	memset(fkm,0,sizeof(fkm));
	int w= GetSystemMetrics(SM_CXSCREEN);//1366
	int l= GetSystemMetrics(SM_CYSCREEN);//768
	initgraph(400,450,SHOWCONSOLE);
    cleardevice();  
	HWND hwnd = GetHWnd();
    SetWindowPos(hwnd, HWND_TOP, w/2-300,2 , 0, 0, SWP_NOSIZE);/*图形驱动*/
	Image("gif","BG",0,0);
	//Image("gif","S0",180,20);
	//Image("gif","R0",50,20);
	int i;
	for(i = 0;i<10;i++)
		for(int j=0;j<10;j++)
		{	if(i==0||j==0||i==9||j==9)
				fkm[i][j] =1;
			else fkm[i][j] = 0;
		}
	fkm[0][0] = 8;
	for( i=50;i<350;i+=30)
		for(int j=100;j<400;j+=30)
		{	setcolor(BLUE);
			showFk(i,j,fkm[(i-50)/30][(j-100)/30]);
			rectangle(i+4,j+4,i+24,j+24);
		}
	return 0;
}
