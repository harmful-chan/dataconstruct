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
extern int DeleteBSTNode(BSTree *, ElemType);

extern void ShowPrefix(BSTree *);
extern void ShowInfix(BSTree *);
extern void ShowPostfix(BSTree *);

extern void Show(BSTree *);
#endif
