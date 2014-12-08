/*
	time:2014-10-05 00.03
	author:halfopen
	version: 1

*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next; 
}LinkList;
void CreateList( LinkList *&L , ElemType a[] , int n );
void CreateCList( LinkList *&L , ElemType a[] , int n );
void InitList( LinkList *&L);
void InitCList( LinkList *&L);
void DestoryList( LinkList *L );
void DestoryCList( LinkList *L );
bool ListEmpty( LinkList *L );
int ListLength( LinkList *L );
void DispList( LinkList *L );
void DispCList( LinkList *L );
bool GetElen( LinkList *L , int i , ElemType &e);
int LocateElem( LinkList *L , ElemType e);
bool ListInsert( LinkList *&L , int i , ElemType e);
bool ListDelete( LinkList *&L , int i, ElemType &e );
