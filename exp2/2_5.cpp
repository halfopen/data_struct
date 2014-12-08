/*
	time:2014-10-05 00.03
	author:halfopen
	version: 1

*/
#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"
#include "readInput.h"
void LocateNode(DLinkList *&L,ElemType x);

int main()
{	DLinkList *L;
	int choice;
	InitList(L);
	int length;
	ElemType *a;
	length = readInput(a);
	CreateList(L , a ,length);
	DispList(L);
	while(1 == scanf("%d",&choice))
	{	LocateNode(L,choice);
		DispList(L);
	}
	
	return 0;
}
void LocateNode(DLinkList *&L, ElemType x)
{	DLinkList *p = L->next, *t,*a,*b,*c;
	while(p !=NULL)
	{	//printf("1,%p,%d f:%d next,%p\n",p,p->data,p->freq,p->next);
		//getchar();
		t = p->next;
		if(x == p->data)
		{	//printf("2,%p,%d f:%d next,%p\n",p,p->data,p->freq,p->next);
			++p->freq;
			while(p!=L->next && p->freq > p->prior->freq)//error
			{	//printf("3,%p,%d f:%d next,%p\n",p,p->data,p->freq,p->next);	
				a = p->prior->prior;
				b = p->prior;
				c = p->next;
				if(a!=NULL)
				{	a->next = p;
					p->prior = a;
				}
				else break;
				p->next = b;
				b->prior = p;
				b->next = c;
				if(c!=NULL)c->prior = b;
				p = a->next;//move to right			
			}				
		}
		p = t;
		
	}

}
