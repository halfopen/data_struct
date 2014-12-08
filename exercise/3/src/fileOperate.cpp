/**	
**	数据结构综合实验3-二叉树实现家谱的相关运算
**	time:2014-11-26 21:43
**	author:halfopen
**	version:1
**/
#include <stdio.h>
#include <stdlib.h>
#include "fileOperate.h"
void readData(char * s)
{	FILE *f;
	f = fopen("family.dat","r");
	fscanf(f,"%s",s);
	fclose(f);
}
void clearData()
{	FILE *f = fopen("family.dat","w+");
	if( f==NULL)puts("Not Cleared");
	else puts("Cleared");
	fclose(f);
}
void writeData(char * s)
{	FILE *f = fopen("family.dat","w+");
	fprintf(f,"%s",s);
	fclose(f);
}

