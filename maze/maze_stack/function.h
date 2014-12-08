extern int fkm[10][10];
void Image(char a[],char b[],int x,int y);
bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);
bool SetWindowTransparent(HWND hwnd, COLORREF crkcolor, BYTE bAlpha, DWORD dwFlags);
void Frametransparent(HWND hwnd, bool frame);    //
bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);
void transparent();
void showFk(int x,int y,int type);

void Image(char a[],char b[],int x,int y);

int reset(void);

int inbox(int a,int b,int c,int d,int x,int y);
int hitbox(int a,int b,int c,int d,int x,int y);//вСиосроб
int mousemove();

void playmusic();