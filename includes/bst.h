#ifndef _BST_H_
#define _BST_H_


#define isLeftChild(pare, p) ( pare != NULL && pare->left != NULL && pare->left == p )
#define isRigtChild(pare, p) ( pare != NULL && pare->rigt != NULL && pare->rigt == p ) 



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
}BSTNode;

typedef struct bst_tree
{
	int layout;
	struct bst_node *head;
}BSTree;




extern BSTree *InitBSTree(BSTree *);
extern BSTNode *InitBSTNode(BSTNode *, ElemType);
extern BSTNode *InsertBSTNode(BSTree *, BSTNode *);
extern void DeleteBSTNode(BSTree *, ElemType);
extern void ReleaseBSTree(BSTree *);
extern void ShowBSTree(BSTree *);

BSTNode *Search(BSTNode *, ElemType);
BSTNode *SearchParent(BSTNode *, ElemType);



#endif
