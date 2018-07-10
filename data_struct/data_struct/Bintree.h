#ifndef _BINTREE_H_
#define _BINTREE_H_
typedef int ElementType;
typedef struct bnode {
	ElementType Data;
	struct bnode* leftChild;
	struct bnode* rightChild;
}BitNode,*BinTree;
void CreateBinTree(BinTree* t);
void PreOrderTraverse(BinTree t);
void InOrderTraverse(BinTree t);
void PostOrderTraverse(BinTree t);
#endif // !_BINTREE_H_
