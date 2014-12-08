#include "Queue.h"

void Initqueue(SqQueue *&q)
{	q= (SqQueue *)malloc( sizeof(SqQueue));
	q->front = q->rear = 0;
}

void DestroyQueue(SqQueue *&q)
{	free(q);
}

bool QueueEmpty( SqQueue * q)
{	return (q->front == q->rear);
}

bool enQueue( SqQueue *&q, ElemType e)
{	if( (q->rear+1)%MaxSize == q->front)
		return false;
	q->data=(q->rear+1)%MaxSize;
	e = data[q->rear] = e;
	return true;
}

bool deQueue( SqQueue *&q, ElemType &e)
{	if(q->front == q->rear)
		return false;
	q->front = (q->front+1)%MaxSize;
	e = q->data[q->front];
	return true;
}

