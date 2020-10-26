#ifndef _BST_H_
#define _BST_H_

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *left;
	struct Node *rigt;
	struct Node *pare;
}BSTNode, BSTree;

extern BSTree *InitBST(BSTree *);
extern BSTNode *InitBSTNode(BSTNode *, ElemType);

extern BSTNode *InsertBSTNode(BSTree *, BSTNode *);
extern BSTNode *FindBSTNode(BSTree *, ElemType);
extern int DeleteBSTNode(BSTree *, BSTNode *);

extern void ShowPrefix(BSTree *);
extern void ShowInfix(BSTree *);
extern void ShowPostfix(BSTree *);
#endif
