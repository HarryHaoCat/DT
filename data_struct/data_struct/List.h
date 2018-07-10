#include<stdio.h>
#include<stdlib.h>

#ifndef _LIST_H_
#define LIST_H_
#define MAXSIZE  3
typedef int ElementType;

typedef struct {
	ElementType* array;
	int Last;   //���һ��λ�õ�����
	int len;
}List;
List* CreateList();    //����һ���յ��б� 
void Insert(ElementType X, int i, List* Ptrl); //��˳�������ĳһ��iλ�ò���һ��Ԫ��
int Search(ElementType X, List* Ptrl);
void traverse(List* Ptrl);
void Delete(int i, List *Ptrl);
int Len(List* Ptrl);
void Remove(List *Ptrl);  //�Ƴ�����
#endif 
