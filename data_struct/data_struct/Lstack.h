#ifndef _Lstack_H_
#define _Lstack_H_
#define MAXSIZE 1000
typedef int ElementType;
typedef struct node {
	ElementType  Data;
	struct node* Next;
}NODE;
typedef struct
{
	NODE* Top;
	NODE* Bottom;
	int size;
}Lstack; 
Lstack* CreateLstack(); //建栈
void PushLstack(Lstack* PtrS, ElementType item); //进栈；
ElementType PopLstack(Lstack * PtrS);  //出栈；
ElementType LstackIsEmpty(Lstack* S);   //判断栈是否为空；
void PrintStack(Lstack* p);
void ClearLstack(Lstack* p);
#endif 
