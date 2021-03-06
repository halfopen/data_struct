/*
**	求复杂表达式的值
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

#endif
