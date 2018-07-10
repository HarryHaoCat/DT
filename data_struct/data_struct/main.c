#include<stdio.h>
#include<stdlib.h>
//#include"Lstack.h"
#include"List.h"
//#include"Chain_List.h"
//#include"stack.h"
//#include"Lqueue.h"
//#include"Bintree.h"



int main()
{
	List *p;
	int cur = 0;
	p = MakeEmpty();
	for (int t = 0; t < 10000; t++)
	{
		Insert(t, t, p);
	}
	cur = Search(66, p);
	if (cur != -1)
		printf("can't find the element!\n");
	traverse(p);
	Delete(10, p);
	printf("The length is:%d\n", Len(p));
	Remove(p);

	//单向链表
	/*Clist *p;
	p = CreateNode();
	p = Clinsert( 6, 1, p);
	p = Clinsert( 16, 2, p);
	p = Clinsert( 22, 3, p);
	printf("%d   %p\n",p->Next->Next->Data, p->Next->Next);
	printf("第二个位置的指针%p\n", FindKth(2,p));
	printf("元素%d位置的地址为%p\n", 10, Clfind(10, p));
	Cldelete(1, p);
	PrintNode(p);*/

	//顺序栈
	/*Stack* p = CreateStack();
	for (int i = 0; i < 1500; i++)
	{
		Push(p,(int)i);
	}
	for (int i = 0; i < 1500; i++)
	{
			printf("%d Pop success!\n", Pop(p));
	}
	IsEmpty(p);
	ClearStack(p);*/
	//Lstack
	/*Lstack *p;
	
	p = CreateLstack();
	for (int i = 0; i < 1000; i++)
	{
		PushLstack(p, i);
	}
	//PushLstack(p, &2);
	PrintStack(p);
	printf("\n");
	for (int i = 0; i < 1000; i++)
	{
		PopLstack(p);
	}
	//PopLstack(p);
	//PopLstack(p);
	//PopLstack(p);
	//PopLstack(p);
	LstackIsEmpty(p); 
	ClearLstack(p);
*/
	//链队
	/*Lqueue* lq = QueueCreate();
	Enqueue(lq, 10);
	Enqueue(lq, 12);
	Enqueue(lq, &11);
	Enqueue(lq, &45);
	Dequeue(lq);
	PrintEqueue(lq);*/

	//二叉树
	/*int level = 1;
	BinTree* t = (BinTree*)malloc(sizeof(BitNode));
	CreateBinTree(t);
	printf("Construct tree succeed!\n");
	printf("PreOderTraverse:\n");
	PreOrderTraverse(*t);
	printf("InOderTraverse:\n");
	InOrderTraverse(*t);
	printf("PostOderTraverse:\n");
	PostOrderTraverse(*t);
	system("pause");*/
	return 0;
}
