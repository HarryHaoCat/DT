#ifndef _STACK_H_
#define _STACK_H_
#define MAXSIZE 5
typedef int ElementType;
typedef struct STACK{
	ElementType* array;
	int Top;
	int len;
}Stack;

Stack* CreateStack();						//create stack
void Push(Stack* PtrS, ElementType item);	//insertion
ElementType Pop(Stack* PtrS);				//departion
int IsEmpty(Stack* S);						//
void ClearStack(Stack* PtrS);				
#endif
