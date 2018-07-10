#ifndef _CHAIN_LIST_H
#define _CHAIN_LIST_H
#define MAXSIZE 1000
typedef int ElementType;
//����ṹ��
typedef struct Node{
	ElementType Data;
	struct Node *Next;
}Clist;
Clist* CreateNode();						//��������,����һ��ֵΪ�������ͷ
Clist* FindKth(int K, Clist* Ptrl);			//���ص�K��ָ��,û�оͷ���NULL
Clist* Clfind(ElementType X, Clist *Ptrl);	//��ֵ����
Clist* Clinsert(ElementType X, int i, Clist* Ptrl); //���ն�λ��Ų���
void Cldelete(int i, Clist *Ptrl);			//ɾ��ָ��λ��Ԫ��
void PrintNode(Clist* Ptrl);                 //��ӡ����         
#endif
