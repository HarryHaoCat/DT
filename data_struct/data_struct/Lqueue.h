#ifndef _Lqueue_H_
#define _Lqueue_H_
typedef int ElementType;
#define MAXSIZE 1000
typedef struct qnode {
	ElementType  Data;
	struct qnode* Next;
}qnode;
typedef struct
{
	qnode* rear;  //¶ÓÎ²
	qnode* front; //¶ÓÊ×
	ElementType size;
}Lqueue;
Lqueue* QueueCreate();
void Enqueue(Lqueue* lq, ElementType item);
ElementType Dequeue(Lqueue* lq);
ElementType Length_queue();
void PrintEqueue(Lqueue* lq);
#endif 
