//顺序表的实现
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"


List* MakeEmpty()
{
	List *Ptrl = (List*)malloc(sizeof(List));
	Ptrl->array = (ElementType*)malloc(MAXSIZE * sizeof(ElementType));  
	Ptrl->Last = -1; 
	Ptrl->len = MAXSIZE; 
	return Ptrl;
}
//Insertion
void Insert(ElementType data, int i, List* Ptrl)
{
	
	if (Ptrl->Last >= MAXSIZE - 1)
	{
		int L = Ptrl->len;
		ElementType *array = (ElementType*)malloc((L + MAXSIZE) * sizeof(ElementType));
        memcpy(array, Ptrl->array, L * sizeof(ElementType));
        ElementType* fs = Ptrl->array;
        Ptrl->array = array;
        Ptrl->len = L + MAXSIZE; 
        free(fs);
	}

	if (i < 0 || i > Ptrl->Last + 2)
	{
		printf("index is illegal\n!");
	}
	else
   
		for (int j = Ptrl->Last; j > i; j--)
		{
			Ptrl->array[j] = Ptrl->array[j - 1];
		}
		Ptrl->array[i] = data;
		Ptrl->Last++;
		printf("Insert element %d success! \n",data);
   
}
 

int Search(ElementType X, List* Ptrl)
{
	int cur = 0;
	while (cur <= Ptrl->Last)
	{
		if (Ptrl->array[cur] == X)
		{
			return cur; 
			break;
		}
		cur++;
	}
	if (cur > Ptrl->Last)
	{
		printf("There is not %d\n", X);
		return -1;
	}
}

int Len(List *p)
{
	return (p->Last) + 1;
}

void Remove(List *Ptrl)
{
	free(Ptrl);
}

void Delete(int i, List *Ptrl)
{
	if (Ptrl->Last == -1)
		printf("There is nothing!\n");
	else
	{
		if(i < 0 || i > Ptrl->Last)
		{
			printf("Delete is illegal!");
		}
		int cur = i;
		for (int j = cur; j < Ptrl->Last; j++)
		{
			Ptrl->array[j] = Ptrl->array[j + 1];
		}
		Ptrl->Last--;
		printf("Delete success\n");
	}
	
}
void traverse(List* Ptrl)
{
	if(Ptrl->Last == -1)
	{
		printf("This is a empty list!\n");
	}
	else
	{
		for(int i = 0; i<=Ptrl->Last; i++)
		{
			printf("%d->",Ptrl->array[i]);
		}
	}
}
