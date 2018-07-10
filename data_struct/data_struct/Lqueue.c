#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Lqueue.h"

Lqueue* QueueCreate()
{
	Lqueue* lq = (Lqueue*)malloc(sizeof(Lqueue));
	lq->front = (qnode*)malloc(sizeof(qnode));
	lq->size = 0;
	lq->front->Data = 0;
	lq->front->Next = NULL;
	lq->rear = lq->front;
	return lq;
}
void Enqueue(Lqueue* lq, 	ElementType item)
{
	//assert(lq->size <= MAXSIZE, "队列已满！\n");
	lq->rear->Next = (qnode*)malloc(sizeof(qnode));
	lq->rear = lq->rear->Next;
	lq->rear->Data = item
	lq->rear->Next = NULL;
	lq->size++;
	printf("%d Enqueue success!\n",item);
}
ElementType Dequeue(Lqueue* lq)
{
	//assert(lq->rear == lq->front, "这是一个空队列！\n");
	ElementType data = lq->front->Next->Data;
	qnode* fl= lq->front->Next;
	lq->front->Next = lq->front->Next->Next;
	free(fl);
	lq->size--;
	printf("%d Dequeue success!\n", data);
	return data;
}
ElementType Length_queue(Lqueue* lq)
{
	return lq->size;
}

void PrintEqueue(Lqueue* lq)
{
	printf("The elements of the stack is:");
	if (lq->front == lq->rear)
	{
		printf("The stack is empty!");
	}
	qnode* qn = lq->front->Next;
	while (qn != lq->rear)
	{
		printf("%d->",qn->Data);
		qn = qn->Next;

	}
	printf("%d\n", qn->Data);
}
