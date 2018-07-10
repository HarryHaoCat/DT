#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Lstack.h"

Lstack* CreateLstack() //½¨Õ»
{
	Lstack* s = (Lstack*)malloc(sizeof(Lstack));
	NODE* n = (NODE*)malloc(sizeof(NODE));
	n->Data = 0;
	n->Next = NULL;
	s->Top = n;
	s->Bottom = s->Top;
	s->size = 0;
	return s;
}
//extern Lstack* Top;
void PushLstack(Lstack* s, ElementType item) //½øÕ»£»
{
	//assert(s->size <= MAXSIZE, "Õ»ÒÑÂú£¡" );
	NODE *P = (NODE*)malloc(sizeof(NODE));
	P->Data = item;
	P->Next = s->Top;
	s->Top = P;
	s->size++;
	printf("%d Push success!\n",item);
}

ElementType PopLstack(Lstack * s)  //³öÕ»£»
{
	if(s->Top == s->Bottom) 
	printf("This is a empty stack!");
	ElementType data = s->Top->Data;
	//Lstack *fs = s->Top;
	s->Top = s->Top->Next;
	printf("%d Pop success!\n", data);
	//free(&fs);
	return data;
}

ElementType LstackIsEmpty(Lstack* S)   //ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ£»
{
	if (S->Top == S->Bottom)
	{
		printf("This is a empty stack!\n");
		return 1;
	}
	else{	
		printf("This isn't a empty stack!\n");
		return 0;
	}
}
void PrintStack(Lstack* p)
{
	if(p->Top == p->Bottom) 
	printf("This is a empty stack!");
	NODE* s= p->Top;
	while (s->Next != p->Bottom)
	{
		printf("%d->",s->Data);
		s = s->Next;
	}
	printf("%d",s->Data);

}
void ClearLstack(Lstack* p)
{
	
		while(p->Top != p->Bottom)
		{
			NODE* f = p->Top;
			p->Top = p->Top->Next;
			free(f);
		}
		printf("ClearLstack success!\n");
}		


