/*
	time:2014-10-05 00.03
	author:halfopen
	version: 1

*/
#include <stdio.h>
#include <stdlib.h>
#include "readInput.h"
#include "SqList.h"
bool DelList(SqList *&L,int s,int e);
int main()
{	int length,*a,s,e;
	SqList *L;

	length = readInput(a); //get the list from input.txt
	InitList(L);
	CreateList(L,a,length);
	//printf("test: %d,%d  ",L->data[4],a[4]);
	DispList(L);
	while(1)
	{	puts("Please input 2 intergers,[a,b]");
		scanf("%d%d",&s,&e);
		if( DelList( L, s, e) )break; //no errors,break;
		puts("illegal input");
	}
	DispList(L);
	return 0;
}
bool DelList(SqList *&L,int s,int e) 
{	int k=0,i=0;
	if( s > e )return false;
	while( i < L->length)
	{	if( L->data[i] >= s && L->data[i] <= e)++k;
		else L->data[i-k] = L->data[i];	//move left
		++i;
	}
	L->length -= k;
	return true;
}


