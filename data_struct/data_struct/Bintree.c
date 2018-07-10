#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "Bintree.h"

void  CreateBinTree(BinTree* t)     //建立二叉树(采用前序遍历的方法)
{
	ElementType data;
	printf("Please input a data of node:");
	scanf("%d", &data);
	printf("\n");
	if (data == 0)
	{
		*t = NULL;
	}
	else {
		*t = (BinTree*)malloc(sizeof(BitNode)); //t为指针指向上一结点左孩子的地址，*t为孩子的内容，此时申请一个结点，*t为指向下一结点地址的指针
		//printf("%d\n",*t);
		//printf("%d\n",t);
		(*t)->Data = data;
		//printf("%d\n",t == *t);
		//printf("%s\n",);
		CreateBinTree(&((*t)->leftChild));   //此时传入的参数为左孩子指针的地址，即此时的指针指向左孩子的地址
		CreateBinTree(&((*t)->rightChild));
	}
}

void PreOrderTraverse(BinTree t)   //树的前序遍历并打印
{
	if (t)
	{
		printf("%d\n", t->Data);
		PreOrderTraverse(t->leftChild);
		PreOrderTraverse(t->rightChild);
	}
}

void InOrderTraverse(BinTree t)
{
	if (t == NULL)
	{
		return;
	}
	InOrderTraverse(t->leftChild);
	printf("%d\n", t->Data);
	InOrderTraverse(t->rightChild);
}
void PostOrderTraverse(BinTree t)
{

	if (t == NULL)
	{
		return;
	}
	PostOrderTraverse(t->leftChild);
	PostOrderTraverse(t->rightChild);
	printf("%d\n", t->Data);

}

