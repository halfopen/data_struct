/*
	time:2014-10-05 00.03
	author:halfopen
	version: 1

*/
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "readInput.h"

void transpLinkList(LinkList *&L);
int main()
{	
	int length,*a,s,e;
	LinkList *L;
	
	//get the list
	length = readInput(a);
	//printf(" a: %d\n",a[2]);
	InitList(L);
	CreateList(L,a,length);
	//printf("test: %d,%d  ",L->data[4],a[4]);
	DispList(L);
	puts("transposition");
	transpLinkList(L);
	DispList(L);
	DestoryList(L);
	return 0;
}

void transpLinkList(LinkList *&L)
{	LinkList *p,*temp = L->next,*f;
	p = temp->next;	//store temp->next
	temp->next = NULL;
	f = temp;
	//printf("%p %p %p\t",f,temp,p);
	while(p!=NULL)
	{	
		temp = p;//move to next node
		p = temp->next;//store temp->next
		temp->next = f;//turn position
		f = temp;
		//printf("%p %p %p\t",f,temp,p);
	}
	L->next=temp;
}
