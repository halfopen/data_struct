/*	
**	数据结构综合实验1-链表算法设计
**	time:2014-10-06 21:43
**	author:halfopen
**	version:1
*/


#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "fileOperate.h"

void printMenu();
int main()
{	LinkList *L;
	char choose,name[1024];
	int no,depno,salary;
	InitList( L);
	//char a[1024];
	while(printMenu(),puts("Enter your choice"),choose=getchar())
	{	fflush(stdin);
		switch(choose)
		{	case '1':
			{	
			}break;
			case '2':
			{	readData(L);
				puts("read from emp.dat");
			}break;
			case '3':
			{	puts("Please input: no(int) name(varchar) depno(int) salary(int)");
				scanf("%d %s %d %d",&no,name,&depno,&salary);
				InsertList(L,no,name,depno,salary);
				puts("Added");
			}break;
			case '4':case '5':case '6':
			{	choose -= 3 +'0';
				sortList(L,choose);
				puts("Sorted");
				
			}break;
			case '7':
			{	clearData();
				puts("Cleared");
			}break;
			case '8':
			{	writeData(L);
				puts("Saved");
			}break;
			case '0':
			{DestroyList(L);exit(0);}
		}DispList(L);
		puts("press any key to continue");fflush(stdin);getchar();getchar();
		fflush(stdin);
	}
	DestroyList(L);
	return 0;
}

void printMenu()
{	puts("");
	puts("\t1.show employer list");
	puts("\t2.read emplist from emp.dat");
	puts("\t3.insert a new emplist");
	puts("\t4.sort employer list by no");
	puts("\t5.sort employer list by depno");
	puts("\t6.sort employer list by salary");
	puts("\t7.clear emp.dat");
	puts("\t8.save LinkList L to emp.dat");
	puts("\t0.exit");
}



