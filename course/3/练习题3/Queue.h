#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct
{	ElemType data[MaxSize];
	int front,rear;
}SqQueue;


void Initqueue(SqQueue *&q);

void DestroyQueue(SqQueue *&q);

bool QueueEmpty( SqQueue * q);

bool enQueue( SqQueue *&q, ElemType e);

bool deQueue( SqQueue *&q, ElemType &e);

#endif


