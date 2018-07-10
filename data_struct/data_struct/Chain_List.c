#include<stdio.h>
#include<stdlib.h>
#include "Chain_List.h"

Clist* CreateNode()
{
	Clist* p = (Clist*)malloc(sizeof(Clist));
	p->Data = 0;
	p->Next = NULL;
	return p;
}

Clist* Clinsert(ElementType X, int i, Clist* Ptrl) //按照定位序号插入
{
	if (i < 1)
	{
		printf("位置非法");
	}
	if (i == 1)
	{
		Clist *s = (Clist *)malloc(sizeof(Clist));
		s->Data = X;
		s->Next = Ptrl->Next;
		Ptrl->Next = s;
		printf("插入成功!!\n");
		//Ptrl = NULL;
		return Ptrl;
	}
	else
	{
		Clist *l = Ptrl->Next;
		for (int j = 1; j < i-1; j++)
		{
			l = l->Next;
		}
		//此时l指向Ptrl->Data[i-1];
		Clist *s = (Clist *)malloc(sizeof(Clist));
		s->Data = X;
		s->Next = l->Next;
		l->Next = s;
		printf("插入成功！\n");
		return Ptrl;
	}
}

Clist* FindKth(int K, Clist* Ptrl)			//返回第K个指针,没有就返回NULL
{
	Clist *p = Ptrl;
	if (Ptrl->Next == NULL)
		return NULL;
	else
	{
		for (int i = 1; i <= K; i++)
		{
			p = p->Next;
		}
		return p;
	}
}

Clist* Clfind(ElementType X, Clist *Ptrl)	 //按值查找
{
	Clist* p = Ptrl;
	while (p->Data != X)
	{
		if (p->Next == NULL)
		{
			printf("没有此元素！");
			break;
		}
		p = p->Next;
	}
	if (p->Data == X)
		return p;
	else return NULL;//没有找到就返回空指针
}

void Cldelete(int i, Clist *Ptrl)   //删除指定位序元素
{
	Clist* p = NULL;
	Clist* s = NULL;
	p = FindKth(i - 1, Ptrl);
	s = p->Next;
	p->Next = p->Next->Next;
	free(s);
	printf("删除成功！");

}

void PrintNode(Clist* Ptrl)                 //打印链表 
{
	Clist* p = Ptrl;
	do
	{
		printf("%d->", p->Data);
		p = p->Next;
	}while (p->Next != NULL);
	printf("%d\n", p->Data);
}