#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "Bintree.h"

void  CreateBinTree(BinTree* t)     //����������(����ǰ������ķ���)
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
		*t = (BinTree*)malloc(sizeof(BitNode)); //tΪָ��ָ����һ������ӵĵ�ַ��*tΪ���ӵ����ݣ���ʱ����һ����㣬*tΪָ����һ����ַ��ָ��
		//printf("%d\n",*t);
		//printf("%d\n",t);
		(*t)->Data = data;
		//printf("%d\n",t == *t);
		//printf("%s\n",);
		CreateBinTree(&((*t)->leftChild));   //��ʱ����Ĳ���Ϊ����ָ��ĵ�ַ������ʱ��ָ��ָ�����ӵĵ�ַ
		CreateBinTree(&((*t)->rightChild));
	}
}

void PreOrderTraverse(BinTree t)   //����ǰ���������ӡ
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

