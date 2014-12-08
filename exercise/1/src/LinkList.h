/**	
**	数据结构综合实验1-链表算法设计
**	time:2014-10-06 21:43
**	author:halfopen
**	version:1
**/
#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Emp{
	int no;
	char *name;
	int depno;
	int salary;
	Emp *next;
}LinkList;
void swap(int *a,int *b);
void InitList( LinkList *&L);
void CreateList( LinkList *&L, int no[], char name[][24], int depno[], int salary[], int n);
void InsertList( LinkList *&L, int no, char name[], int depno, int salary);
void DispList( LinkList *&L);
void noSort( LinkList *&L);
void depSort( LinkList *&L);
void salSort( LinkList *&L);
void DestroyList( LinkList *&L);
void sortList( LinkList *&L, int type);
#endif
