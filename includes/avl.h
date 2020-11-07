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
	ElemType data;
	struct avl_node *left;
	struct avl_node *rigt;
	struct avl_node *pare;
    int height;
}AVLNode;

typedef struct avl_tree
{
	int layout;
	struct avl_node *head;
}AVLTree;



extern AVLTree *InitAVLTree(AVLTree *);
extern AVLNode *InitAVLNode(AVLNode *, ElemType);
extern AVLNode *InsertAVLNode(AVLTree *, AVLNode *);
extern int DeleteAVLNode(AVLTree *, ElemType);


#endif