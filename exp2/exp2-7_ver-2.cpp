/*
	time:2014-10-06 11:20
	author:halfopen
	version: 2

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
//LinkList* ListFind( LinkList *&L, int e);
void Add( LinkList *&L1, LinkList *&L2);
//main/////////////////////////////////////////////////////////////////////////////////////
int main()
{	LinkList *L1,*L2;
	int b,e;
	InitList( L1 );
	InitList( L2 );
	puts("Add ax^b to L1,please input \"a b\"");
//input
	while(scanf("%d%d",&b,&e) == 2)	// get L1
	{	if( 0 == b)break;
		InsertList( L1, b, e);
		printf("\tL1:  ");DispList( L1);
		puts("input \"a b\"");
	}
	puts("Add ax^b to L2,please input \"a b\"");
	while(scanf("%d%d",&b,&e) == 2)	// get L2
	{	if( 0 == b)break;
		InsertList( L2, b, e);
		printf("\tL2:  ");DispList( L2);
		puts("input \"a b\"");
	}
//output	
	printf("End inputs:\n");
	printf("\tL1:  ");DispList( L1);
	printf("\tL2:  ");DispList( L2);
	puts("Add:"); 
	Add( L1, L2);
	printf("\ttotal:  ");DispList( L1);
	return 0;
}
//main end////////////////////////////////////////////////////////////////////////////////////////////////////
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
	L->e = 0;
	L->next = NULL;
}

bool InsertList( LinkList *&L, int b, int e)
{	LinkList *p = L, *s;
	while(p->next != NULL)
	{	if(e == p->e && p->b !=0 )//1
		{	p->b += b;//printf("\tup:p->b:%d:%d,%p\n",p->b,p->next->b,p->next);
			if( p->b == 0)
			{	s->next = p->next;
				free(p);
			}
			return false;
		}
		if(p->next != NULL && p->next->e <e)break;//move to the right place
		s = p;
		p = p->next;
		if( (p->next == NULL) && (e == p->e) )//2 here error fail to insert when e==0
		{	p->b += b;//printf("\tdown:p->b:%d:%p\n",p->b,p->next);
			if( p->b == 0)
			{	s->next =NULL;
				free(p);
			}
			return false;
		}
	}
	s = (LinkList *)malloc( sizeof( LinkList)); //create a new node ,and insert it after p
	if(p->next != NULL)
		s->next = p->next;	//link to the next node if it exists
	else 	s->next = NULL;
	p->next = s;
	s->b = b;
	s->e = e;
	return true;
}
/*
LinkList* ListFind( LinkList *&L, int e)// find e in L
{	LinkList *p = L->next;
	while(NULL != p->next)
	{	if( e == p->e)return p;	
		p = p->next;
	}	
	return NULL;
}
*/
void DispList( LinkList *&L)//ok
{	LinkList *p = L->next;
	while( p !=  NULL)
	{	//printf("%dx%d  ",p->b,p->e);
		if(p != L->next && p->b > 0)printf("+");
		if(p->b != 1)
		{	if(p->b == -1 )printf("-");
			else printf("%d",p->b);
		}
		if(p->e == 1)printf("x");
		else if(p->e!=0)printf("x^%d",p->e);
		p = p->next;		
	}
	puts("");
	
}
