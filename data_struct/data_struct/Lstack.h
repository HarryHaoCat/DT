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
Lstack* CreateLstack(); //��ջ
void PushLstack(Lstack* PtrS, ElementType item); //��ջ��
ElementType PopLstack(Lstack * PtrS);  //��ջ��
ElementType LstackIsEmpty(Lstack* S);   //�ж�ջ�Ƿ�Ϊ�գ�
void PrintStack(Lstack* p);
void ClearLstack(Lstack* p);
#endif 
