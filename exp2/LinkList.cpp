/**	
**	数据结构综合实验1-链表算法设计
**	time:2014-10-06 21:43
**	author:halfopen
**	version:1
**/
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
void CreateList( LinkList *&L , ElemType a[] , int n )
{	LinkList *s,*r;
	int i;
	L = (LinkList *)malloc( sizeof( LinkList ) );
	r = L;
	for(i= 0; i<n ;i++)
	{	s = (LinkList *)malloc( sizeof( LinkList ) );
		s->data = a[i];
		r->next =s;
		r = s;
	}
	r->next = NULL;
}

void CreateCList( LinkList *&L , ElemType a[] , int n )
{	LinkList *s,*r;
	int i;
	L = (LinkList *)malloc( sizeof( LinkList ) );
	r = L;
	for(i= 0; i<n ;i++)
	{	s = (LinkList *)malloc( sizeof( LinkList ) );
		s->data = a[i];
		r->next =s;
		r = s;
	}
	r->next = L;
}
void InitList(LinkList *&L)
{	L = (LinkList *)malloc( sizeof( LinkList ) );
	L->next = NULL;
}
void InitCList(LinkList *&L)
{	L = (LinkList *)malloc( sizeof( LinkList ) );
	L->next = L;
}
void DestoryList( LinkList *L )
{	LinkList *p = L,*t;
	while(p != NULL)
	{	t = p->next;
		free(p);
		p = t;
	}
	free(p);
}
void DestoryCList( LinkList *L )
{	LinkList *p = L->next,*t;
	while(p != L)
	{	t = p->next;
		free(p);
		p = t;
	}
	free(p);
}
bool ListEmpty( LinkList *L )
{	return (L->next==NULL);
}
int ListLength( LinkList *L )
{	int n = 0;
	LinkList *p = L->next;
	while( p != NULL)
	{	++n;
		p = p->next;
	}
	return n;
}

void DispList( LinkList *L )
{	LinkList *p = L->next;
	while(p!=NULL)
	{	printf(" %d ",p->data);
		p = p->next;
	}
	puts("");
}
void DispCList( LinkList *L )
{	LinkList *p = L->next;
	while(p!=L)
	{	printf(" %d ",p->data);
		p = p->next;
	}
	puts("");
}
bool GetElen( LinkList *L , int i , ElemType &e)
{	int j = 0;
	LinkList *p = L;
	while(j < i && p != NULL)
	{	++j;
		p = p->next;
	}
	if( NULL == p)
		return (false);
	else
	{	e = p->data;
		return (true);
	}
}
int LocateElem( LinkList *L , ElemType e)
{	int i = 0;
	LinkList *p = L->next;
	while( p!=NULL && p->data!=e)
	{	p = p->next;
		++i;
	}
	if( p == NULL)
		return (0);
	else return (i);
}
bool ListInsert( LinkList *&L , int i , ElemType e)
{	int j = 0;
	LinkList *p = L, *s;
	while( j < i-1 && p!=NULL)
	{	++j;
		p = p->next;
	}
	if(p == NULL)return false;
	else
	{	s = (LinkList *)malloc( sizeof(LinkList));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}

}
bool ListDelete( LinkList *&L , int i, ElemType &e )
{	int j = 0;
	LinkList *p = L,*q;
	while( j < i-1 && p != NULL)
	{	q = p->next;
		if( q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}





