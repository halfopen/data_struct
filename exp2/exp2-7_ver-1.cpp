/*
	time:2014-10-06 00.17
	author:halfopen
	version: 1

*/
#include <stdio.h>
#include <stdlib.h>



typedef struct eNode{
	int b;
	int e;
	eNode *next;
}LinkList;

void InitList( LinkList *&L );
bool InsertList( LinkList *&L, int b, int e);
void DispList( LinkList *&L);
LinkList* ListFind( LinkList *&L, int e);
void Add( LinkList *&L1, LinkList *&L2);
int main()
{	LinkList *L1,*L2;
	int b,e;
	InitList( L1 );
	InitList( L2 );
	puts("Add ax^b to L1,please input \"a b\"");
	while(scanf("%d%d",&b,&e) == 2)
	{	if( 0 == b)break;
		InsertList( L1, b, e);
		DispList( L1);
		puts("input \"a b\"");
	}
	puts("Add ax^b to L2,please input \"a b\"");
	while(scanf("%d%d",&b,&e) == 2)
	{	if( 0 == b)break;
		InsertList( L2, b, e);
		DispList( L2);
		puts("input \"a b\"");
	}
	printf("End inputs:\n");
	printf("1:  ");DispList( L1);
	printf("2:  ");DispList( L2);
	puts("Add:");
	Add( L1, L2);
	DispList( L1);
	return 0;
}
void Add( LinkList *&L1, LinkList *&L2)
{	LinkList *p = L2->next;
	while(p!=NULL)
	{	InsertList( L1, p->b,p->e);
		p = p->next;
	}
	//DispList(L1);
}
void InitList( LinkList *&L )
{	L = ( LinkList *)malloc( sizeof(LinkList));
	L->b = 0;
	L->e = -9999999;
	L->next = NULL;
}

bool InsertList( LinkList *&L, int b, int e)
{	LinkList *p = L, *s;
	while(p->next != NULL)
	{	if(e == p->e)//1
		{	p->b += b;//printf("\tup:p->b:%d:%d,%p\n",p->b,p->next->b,p->next);
			return false;
		}
		if(p->next != NULL && p->next->e <e)break;//move to the right place
		p = p->next;
		if( (p->next == NULL) && (e == p->e) )//2 here error fail to insert when e==0
		{	p->b += b;//printf("\tdown:p->b:%d:%p\n",p->b,p->next);
			return false;
		}
	}
	s = (LinkList *)malloc( sizeof( LinkList)); //create a new node ,and insert it after p
	s->next = NULL;
	if(p->next != NULL)
		s->next = p->next;	//link to the next node if it exists
	p->next = s;
	s->b = b;
	s->e = e;
	return true;
}

LinkList* ListFind( LinkList *&L, int e)// find e in L
{	LinkList *p = L->next;
	while(NULL != p->next)
	{	if( e == p->e)return p;	
		p = p->next;
	}	
	return NULL;
}

void DispList( LinkList *&L)//ok
{	LinkList *p = L->next;
	while( p !=  NULL)
	{	//printf("%d %d +",p->b,p->e);	
		if(p->b != 1)printf("%d",p->b); // x
		if(p->e != 0)	// if p->e == 0, it should be only a number
		{	if(p->e == 1)printf("x");
			else printf("x^%d",p->e);
		}
		if(p->b == 1 && p->e == 0)printf("1");
		if( p->next !=NULL)printf(" + ");// if it need to add +
		else{ puts("");break;}
		p = p->next;		
	}
	
}
