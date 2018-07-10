#include<stdio.h>
#include<stdlib.h>

#ifndef _LIST_H_
#define LIST_H_
#define MAXSIZE  3
typedef int ElementType;

typedef struct {
	ElementType* array;
	int Last;   //最后一个位置的索引
	int len;
}List;
List* CreateList();    //创建一个空的列表 
void Insert(ElementType X, int i, List* Ptrl); //在顺序链表的某一个i位置插入一个元素
int Search(ElementType X, List* Ptrl);
void traverse(List* Ptrl);
void Delete(int i, List *Ptrl);
int Len(List* Ptrl);
void Remove(List *Ptrl);  //移除链表
#endif 
