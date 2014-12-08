#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#include "readInput.h"
void ConList(LinkList *&ha, LinkList *&hb, LinkList *&hc);

int main()
{	int length;
	ElemType *a;	
	LinkList *ha, *hb ,*hc;

	InitCList(ha);
	InitCList(hb);
	length = readInput( a);	
	CreateCList( ha, a, length);
	CreateCList( hb, a, 5);
	//printf("test: %d,%d  ",L->data[4],a[4]);
	puts("ha");
	DispCList( ha );
	puts("hb");
	DispCList( hb );
	ConList( ha, hb, hc);
	puts("hc");
	//printf("%d",hc->next->data);
	DispCList( ha );
	//puts("destory LinkList");
	DestoryCList( hc );
	
	return 0;
}



void ConList(LinkList *&ha, LinkList *&hb, LinkList *&hc)
{	LinkList *pa = ha->next,*pb = hb->next;

	while( pa->next != ha)pa = pa->next;
	while( pb->next != hb)pb = pb->next;
	//printf("end:%d %d\n",pa->data,pb->data);
	pb->next = ha;
	pa->next = hb->next;
	free(hb); //free the head of hb
	hc = ha;
}
