#ifndef _BST_H_
#define _BST_H_

#define isLeftChild(child) ( child != NULL && child->pare != NULL && child->pare->left == child )
#define isRigtChild(child) ( child != NULL && child->pare != NULL && child->pare->rigt == child ) 

#define haveLeftChild(p) ( p!=NULL && p->left != NULL)
#define haveRigtChild(p) ( p!=NULL && p->rigt != NULL)

#define sureLeft(pare, child) ( child->data < pare->data )
#define sureRigt(pare, child) ( pare->data < child->data )
typedef int ElemType;

typedef struct bst_node
{
	ElemType data;
	struct bst_node *left;
	struct bst_node *rigt;
	struct bst_node *pare;
}BSTNode;

typedef struct bst_tree
{
	int layout;
	struct bst_node *head;
}BSTree;




extern BSTree *InitBSTree(BSTree *);
extern BSTNode *InitBSTNode(BSTNode *, ElemType);

extern BSTNode *InsertBSTNode(BSTree *, BSTNode *);
extern int DeleteBSTNode(BSTree *, ElemType);

BSTNode *Search(BSTNode *, ElemType);
BSTNode *SearchParent(BSTNode *, ElemType);

extern void ShowTree(BSTree *);


#endif
