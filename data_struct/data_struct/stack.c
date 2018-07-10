#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "stack.h"

Stack* CreateStack() //建栈,第一个位置从0开始；
{
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->array = (ElementType*)malloc(MAXSIZE*sizeof(ElementType));
	for (int i = 0; i < MAXSIZE; i++)
	{
		p->array[i] = 0;
	}
	p->Top = -1; 
	p->len = MAXSIZE;  
	return p;
}
void Push(Stack* PtrS, ElementType item) 
{
	//assert(PtrS->Top <= MAXSIZE - 1,"The stack is full");
	if(PtrS->Top >= PtrS->len)
	{
		ElementType *array =  (ElementType*)malloc((PtrS->Top + 1 + MAXSIZE)*sizeof(ElementType));
		//printf("array size = %lx\n", sizeof(array)/sizeof(array[0]));
		//int top = PtrS->Top;
		int L = PtrS->len;
		memcpy(array, PtrS->array, L * sizeof(ElementType));
		free(PtrS->array);
		PtrS->array = array;
		//PtrS->Top = top;
		PtrS->len = L + MAXSIZE;
		
	}
	PtrS->array[PtrS->Top++] = item;
	printf("%d Push success!\n", PtrS->array[PtrS->Top - 1]);
	
}
ElementType Pop(Stack * PtrS)  //出栈；
{
	if(PtrS->Top == 0)
	{
		printf("This is a empty stack!");
		return 0;
	}
	int data =  PtrS->array[PtrS->Top - 1];
	PtrS->Top = PtrS->Top - 1;
	return data;
}
int IsEmpty(Stack* S)   //判断栈是否为空；
{
	if (S->Top == -1)
	{
		
		printf("This is a empty stack!\n");
		return 1;
	}
	else
	{
		printf("This is not a empty stack!\n");
		return 0;
	}
}
void ClearStack(Stack* PtrS)
{
	free(PtrS);
	printf("ClearStack success!\n");
}
