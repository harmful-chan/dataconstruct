#include "bst.h"
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>
#include <string.h>
#include "ds.h"

static BSTNode *SearchParent(BSTree *tree, ElemType data)
{
	BSTNode *p = tree;
	
	if(data < p->data && p->left != NULL)
		p = SearchParent(p->left, data);
	else if(data > p->data && p->rigt != NULL)
		p = SearchParent(p->rigt, data);
	
	return p;
}
static BSTNode *Search(BSTree *tree, ElemType data)
{
	BSTNode *p = tree;
	if(p != NULL)
	{
		p = SearchParent(tree, data);
		BSTNode *ret = NULL;
		ret = (p->data == data) ? p : NULL;
		ret = p->left ? (p->left->data == data) ? p->left : NULL : NULL;
		ret = p->rigt ? (p->rigt->data == data) ? p->rigt : NULL : NULL;
		p = ret;
	}
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
	if(tree->data == -1)
	{
		tree->data = node->data;
		return tree;
	}

	BSTNode *p = tree;	
	p = SearchParent(tree, node->data);    //find node
	node->pare = p;
	if(node->data < p->data)    //left
	{
		node->left = p->left;
		if(p->left != NULL) p->left->pare = node;
		p->left = node;
	}
	else if(node->data > p->data)
	{
		node->rigt = p->rigt;
		if(p->rigt != NULL) p->rigt->pare = node;
		p->rigt = node;
	}
}


int DeleteBSTNode(BSTree *tree, ElemType data)
{
}

void ShowTree(BSTree *tree)
{
	ProductTreePicture(tree);
}