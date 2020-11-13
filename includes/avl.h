#ifndef _AVL_H_
#define _AVL_H_

#include "bst.h"

enum WHIRL_MODE
{
	WHIRL_MODE_LL = 0,   
	WHIRL_MODE_LR,
	WHIRL_MODE_RL,
	WHIRL_MODE_RR,
	WHIRL_MODE_CP = 100,
};

typedef struct avl_node
{
	COM_NODE_INFO(struct avl_node)
    int height;
}AVLNode;

typedef struct avl_tree
{
	COM_HEAD_INFO(struct avl_node)	
}AVLTree;



extern AVLTree *InitAVLTree(AVLTree *);
extern AVLNode *InitAVLNode(AVLNode *, ElemType);
extern AVLNode *InsertAVLNode(AVLTree *, AVLNode *);
extern void DeleteAVLNode(AVLTree *, ElemType);
extern void ReleaseAVLTree(AVLTree *);

extern void ShowAVLTree(AVLTree *);


#endif