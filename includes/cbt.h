#ifndef _CBT_H_
#define _CBT_H_

#include "bst.h"

typedef struct cbt_node
{
	COM_NODE_INFO(struct cbt_node)
	int ltag, rtag;
	
}CBTNode;

typedef struct cbt_tree
{
	COM_HEAD_INFO(struct cbt_node)
	struct cbt_node super;
}CBTTree;


extern CBTTree *InitCBTTree(CBTTree *);
extern CBTNode *InitCBTNode(CBTNode *, ElemType);
extern CBTNode *InsertCBTNode(CBTTree *, CBTNode *);
extern void DeleteCBTNode(CBTTree *, ElemType);
extern void ReleaseCBTTree(CBTTree *);
extern void ShowCBTTree(CBTTree *);
extern void PrintCBTNodeDetail(CBTNode *);


CBTNode *FindCBTNode(CBTTree *, ElemType);


#endif
