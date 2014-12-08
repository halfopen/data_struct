/*
	time:2014-10-05 08.49
	author:halfopen
	version: 1

*/
#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"

void DestoryList( DLinkList *L )
{	DLinkList *p = L,*t;
	while(p != NULL)
	{	t = p->next;
		free(p);
		p = t;
	}
	free(p);
}

void InitList(DLinkList *&L)
{	L = (DLinkList *)malloc( sizeof(DLinkList));
	L->freq = 0;
	L->prior = NULL;
	L->next = NULL;
}
void CreateList( DLinkList *&L, ElemType a[], int n)
{	DLinkList * s, *r;
	int i;
	L = (DLinkList *)malloc( sizeof(DLinkList));
	r = L; // r point to the tail
	for(i = 0; i<n; ++i)
	{	s = (DLinkList *)malloc( sizeof(DLinkList));//create a new node
		s->data = a[i];
		r->next = s;
		s->prior = r;
		s->freq = 0;
		r = s;	// r point to the tail
	}
	r->next = NULL;
}
bool ListInsert( DLinkList *&L, int i, ElemType e)
{	int j = 0;
	DLinkList *p = L,*s;
	while(j<i-1 && p != NULL)
	{	++j;
		p = p->next;
	}
	if(NULL == p)
		return false;
	s = (DLinkList *)malloc( sizeof(DLinkList));//create a new node
	s->data = e;
	s->next = p->next;
	if(p->next != NULL)
		p->next->prior = s;
	p->next = s;
	s->prior = p;
	return true;
}
bool ListDelete( DLinkList *&L, int i, ElemType e)
{	int j = 0;
	DLinkList *p = L, *q;
	while( j < i-1 && p != NULL)
	{	++j;
		p = p->next;
	}
	if(NULL == p)
		return false;
	q = p->next;
	if( NULL == q)
		return false;
	e = q->data;
	p->next = q->next;
	if( p->next != NULL)
		p->next->prior  = p;
	free(q);
	return true;
}
void DispList( DLinkList *L )
{	DLinkList *p = L->next ;
	while(p != NULL)
	{	printf(" %d:%d  ",p->data,p->freq);
		p = p->next;
	}
	puts("");
}
