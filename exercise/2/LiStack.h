/*
**	Expression value
**	time:2014-10-07-13:53
**	author:halfopen
**	version:1
*/
#ifndef LISTACK_H_
#define LISTACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct linknode
{	ElemType data;
	struct linknode *next;
}LiStack;

void InitStack( LiStack *&s);
void DestroyStack( LiStack *&s);
bool StackEmpty( LiStack *&s);
void Push( LiStack *&s, ElemType e);
bool Pop( LiStack *&s, ElemType &e);
bool GetTop( LiStack *s, ElemType &e);
void DispStack( LiStack *s);


typedef struct linknode2
{	double data;
	struct linknode2 *next;
}LiStack2;

void InitStack2( LiStack2 *&s);
void DestroyStack2( LiStack2 *&s);
bool StackEmpty2( LiStack2 *&s);
void Push2( LiStack2 *&s, double e);
bool Pop2( LiStack2 *&s, double &e);
bool GetTop2( LiStack2 *s, double &e);
void DispStack2( LiStack2 *s);

#endif
