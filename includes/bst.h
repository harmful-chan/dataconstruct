#ifndef _BST_H_
#define _BST_H_

#include "typedef.h"

#define isLeftChild(pare, p) ( pare != NULL && pare->left != NULL && pare->left == p )
#define isRigtChild(pare, p) ( pare != NULL && pare->rigt != NULL && pare->rigt == p ) 

#define haveLeftChild(p) ( p!=NULL && p->left != NULL)
#define haveRigtChild(p) ( p!=NULL && p->rigt != NULL)

#define sureLeft(pare, child) ( child->data < pare->data )
#define sureRigt(pare, child) ( pare->data < child->data )

#define F_INIT_TREE(stype, tree) (stype *)InitBSTTree((BSTTree *)(tree))
#define F_INIT_NODE(stype, node, data) (stype *)InitBSTNode((BSTNode *)(node), data)
#define F_INSERT_NODE(stype, tree, node) (stype *)InsertBSTNode((BSTTree *)(tree), (BSTNode *)(node))
#define F_DELETE_NODE(stype, tree, data) DeleteBSTNode((BSTTree *)(tree), data)
#define F_RELEASE_TREE(stype, tree) ReleaseBSTTree((BSTTree *)(tree))
#define F_SHOW_TREE(stype, tree) ShowBSTTree((BSTTree *)tree)
#define F_S(stype, node, data) (stype *)Search((BSTNode *)node, data)
#define F_SPARE(stype, node, data) (stype *)SearchParent((BSTNode *)node, data)


typedef struct bst_node
{
	COM_NODE_INFO(struct bst_node)
}BSTNode;

typedef struct bst_tree
{
	COM_HEAD_INFO(struct bst_node)
}BSTTree;


extern BSTTree *InitBSTTree(BSTTree *);
extern BSTNode *InitBSTNode(BSTNode *, ElemType);
extern BSTNode *InsertBSTNode(BSTTree *, BSTNode *);
extern void DeleteBSTNode(BSTTree *, ElemType);
extern void ReleaseBSTTree(BSTTree *);
extern void ShowBSTTree(BSTTree *);
extern void PrintBSTNodeDetail(BSTNode *);


BSTNode *Search(BSTNode *, ElemType);
BSTNode *SearchParent(BSTNode *, ElemType);



#endif
