#include "bst.h"
#include <stdlib.h>

static inline BSTNode *Search(BSTree *tree, ElemType data)
{
	BSTNode *p = tree;
	
	if(data < p->data && p->left != NULL)
		p = Search(p->left, data);
	else if(data > p->data && p->rigt != NULL)
		p = Search(p->rigt, data);
	return p;
}

BSTree *InitBST(BSTree *tree)
{
	tree->data = -1;
	tree->left = NULL;
	tree->rigt = NULL;
	tree->pare = NULL;
	return tree;
}

BSTNode *InitBSTNode(BSTNode *node, ElemType data)
{
	node->data = data;
	node->left = NULL;
	node->rigt = NULL;
	node->pare = NULL;
	return node;
}

 BSTNode *InsertBSTNode(BSTree *tree, BSTNode *node)
{
	BSTNode *p = tree;
	p = Search(tree, node->data);    //find node
	
	if(node->data < p->data)    //left
	{
		node->left = p->left;
		p->left = node;
	}
	else if(node->data > p->data)
	{
		node->rigt = p->rigt;
		p->rigt = node;
	}
}

BSTNode *FindBSTNode(BSTree *tree, ElemType data)
{}

int DeleteBSTNode(BSTree *tree, BSTNode *node)
{
}
void ShowPrefix(BSTree *tree){}
void ShowInfix(BSTree *tree){}
void ShowPostfix(BSTree *tree){}
