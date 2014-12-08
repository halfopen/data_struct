/**	
**	数据结构综合实验1-链表算法设计
**	time:2014-10-06 21:43
**	author:halfopen
**	version:1
**/
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "fileOperate.h"
void readData( LinkList *&L)
{	FILE *f;
	int no=-1,depno=-1,salary=0;
	char name[24];
	f = fopen("emp.dat","r");
	InitList( L );
	//fscanf(f,"%d",&n);
	//printf("%d",n);
	while(fscanf(f,"%d %s %d %d",&no,name,&depno,&salary) != EOF)
	{	
		//printf("read:%d %s %d %d",no,name,depno,salary);
		InsertList( L,no,name,depno,salary);
	}
	fclose(f);
}
void clearData()
{	FILE *f = fopen("emp.dat","w+");
	if( f==NULL)puts("Not Cleared");
	else puts("Cleared");
	fclose(f);
}
void writeData( LinkList *L)
{	FILE *f = fopen("emp.dat","w+");
	LinkList *p = L->next;
	while(p!=NULL)
	{	fprintf(f,"%d %s %d %d\n",p->no,p->name,p->depno,p->salary);
		p = p->next;
	}
	fclose(f);
}


