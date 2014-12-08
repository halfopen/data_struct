#include <stdio.h>
#include <stdlib.h>

#include "SqList.h"


void CreateList( SqList *&L , ElemType a[] , int n )
{	int i;
	L = (SqList *)malloc( sizeof(SqList) );
	for(i=0;i<n;++i)
	{	L->data[i] =a[i];	}
	L->length = n;
}

void InitList( SqList * &L)
{	L = (SqList *)malloc( sizeof(SqList) );
	L->length = 0;
}

void DestoryList( SqList *&L)
{	free(L);
}

bool ListEmpty( SqList *L )
{	return (L->length == 0);
}
int ListLength( SqList *L )
{	return (L->length);
}
void DispList( SqList *L )
{	int i;
	for(i=0;i< L->length;++i)
	{	printf(" %d ",L->data[i]);	}
	puts("");
}

bool GetElen( SqList *L , int i , ElemType &e)
{	if( i<1 || i>L->length+1)
		return false;
	e = L->data[i-1];
	return true;
}
int LocateElem( SqList *L , ElemType e)
{	int i = 0;
	while( i < L->length   &&  L->data[i] != e)
		++i;		
	if( i >= L->length)
		return 0;		
	else return i+1;
}
bool ListInsert( SqList *&L , int i , ElemType e)
{	int j;
	if( i<1 || i>L->length+1)
		return false;
	--i;
	for( j=L->length; j>i ; --j)
		L->data[j] = L->data[j-1];
	L->data[i] = e;
	++L->length;
	return true; 
}
bool ListDelete( SqList *&L , int i, ElemType &e );
