/*
**	求复杂表达式的值
**	time:2014-10-07-13:53
**	author:halfopen
**	version:1
*/
#include <stdio.h>
#include <stdlib.h>
#include "LiStack.h"
void InitStack( LiStack *&s)
{	s = (LiStack *)malloc( sizeof(LiStack));
	s->next = NULL;
}
void DestroyStack( LiStack *&s)
{	LiStack *p = s,*t;
	while(NULL != p)
	{	t = p;
		free(p);
		p = t->next;
	}
	free(p);
}
bool StackEmpty( LiStack *&s)
{	return (NULL == s->next);
}
void Push( LiStack *&s, ElemType e)
{	LiStack *p = (LiStack *)malloc( sizeof(LiStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}
bool Pop( LiStack *&s, ElemType &e)
{	LiStack *p = s->next;
	if(NULL == p)return false;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}
bool GetTop( LiStack *s, ElemType &e)
{	if( NULL == s->next)
		return false;
	e = s->next->data;
	return true;
}
void DispStack( LiStack *s)
{	LiStack *p = s->next;
	while(NULL != p)
	{	printf("%c",p->data);
		p = p->next;
	}
	if(NULL == s->next)puts("Empty");
	else puts("");
}
