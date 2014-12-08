#ifndef SQLIST_H_
#define SQLIST_H_

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 1024
typedef int ElemType;
typedef struct SqNode{	
	ElemType data[MaxSize];
	int length;
}SqList;



void CreateList( SqList *&L , ElemType a[] , int n );
void InitList( SqList * &L);
void DestoryList( SqList *&L);
bool ListEmpty( SqList *L );
int ListLength( SqList *L );
void DispList( SqList *L );

bool GetElen( SqList *L , int i , ElemType &e);
int LocateElem( SqList *L , ElemType e);
bool ListInsert( SqList *&L , int i , ElemType e);
bool ListDelete( SqList *&L , int i, ElemType &e );
#endif
