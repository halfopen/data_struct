/**	
**	数据结构综合实验1-链表算法设计
**	time:2014-10-06 21:43
**	author:halfopen
**	version:1
**/


#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
void swap(int *a,int *b)
{  	int temp;  
    	temp=*a;  
    	*a=*b;  
    	*b=temp;  
}  
void InitList( LinkList *&L)
{	L = ( LinkList *)malloc( sizeof(LinkList) );
	L->next = NULL;
}
void CreateList( LinkList *&L, int no[], char name[][24], int depno[], int salary[], int n);
void InsertList( LinkList *&L, int no, char name[], int depno, int salary)
{	LinkList *p = L, *s;
	unsigned int i;
	while(p->next!=NULL)
	{	
		p = p->next;
	}
	s =(LinkList *)malloc( sizeof(LinkList));
	p->next = s;
	s->no = no;
	s->name = (char *)malloc( (strlen(name)+1)*sizeof(char));
	for(i=0;i<=strlen(name);++i)	//copy /0
	{	s->name[i] = name[i];
	}
	s->depno = depno;
	s->salary = salary;
	s->next = NULL;

}
void DispList( LinkList *&L)
{	LinkList *p = L->next;
	puts("\n--dempList-------------------------------------------");
	while(p!=NULL)
	{	printf("\tno:%-8d name:%-18s\tdepno:%-8d\tsalary:%-8d\n",p->no,p->name,p->depno,p->salary);
		p = p->next;
	}
	if(NULL == L->next)puts("\tEmpty");
	puts("\n-----------------------------------------------------");
}
void sortList( LinkList *&L, int type)
{
	LinkList *p,*pre, *tp;
	int a=0,b=0;
	if(NULL == L->next)return ;
	p = L->next->next;
	L->next->next = NULL;
	while( NULL != p)
	{	//puts("before noSort");DispList(L);	
		pre = L;// start from L
		tp = p->next;// remember the position of p
		//printf("%d:%p  %d:%p\n",pre->next->no,pre->next,p->no,p->next);
		switch(type)
		{	case 1:
			{	a = p->no;
				b = pre->next->no;
			}break;
		}
		while( NULL != pre->next)
		{	switch(type)
			{	case 1:
				{	a = p->no;
					b = pre->next->no;
				}break;
				case 2:
				{	a = p->depno;
					b = pre->next->depno;
				}break;
				default:
				{	a = p->salary;
					b = pre->next->salary;
				}break;
			}
			if(a<b)break;			
			pre = pre->next;
			//puts("pre moved");
			//getchar();
		}
		p->next = pre->next;
		pre->next = p;
		p = tp;
	}
	DispList(L);
}
void noSort( LinkList *&L)
{	LinkList *p,*pre, *tp;
	if(NULL == L->next)return ;
	p = L->next->next;
	L->next->next = NULL;
	while( NULL != p)
	{	//puts("before noSort");DispList(L);	
		pre = L;// start from L
		tp = p->next;// remember the position of p
		//printf("%d:%p  %d:%p\n",pre->next->no,pre->next,p->no,p->next);
		while( NULL != pre->next && p->no > pre->next->no)
		{	pre = pre->next;
			//puts("pre moved");
			//getchar();
		}
		p->next = pre->next;
		pre->next = p;
		p = tp;
	}
}
void depSort( LinkList *&L);
void salSort( LinkList *&L);
void DestroyList( LinkList *&L)
{	LinkList *p = L,*t;
	while( p->next != NULL)
	{	t = p;
		free(p);
		p = t->next;
	}
	free(p);
}

