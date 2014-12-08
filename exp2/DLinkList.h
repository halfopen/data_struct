/*
	time:2014-10-05 00.23
	author:halfopen
	version: 1

*/
#ifndef DLINKLIST_H_
#define DLINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DLNode
{	ElemType data;
	DLNode *prior;
	DLNode *next;
	int freq;
}DLinkList;
void DestoryList( DLinkList *L );
void InitList(DLinkList *&L);
void CreateList( DLinkList *&L, ElemType a[], int n);
bool ListInsert( DLinkList *&L, int i, ElemType e);
bool ListDelete( DLinkList *&L, int i, ElemType e);
void DispList( DLinkList *L );
#endif
