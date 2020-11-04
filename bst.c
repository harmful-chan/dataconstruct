#include "bst.h"
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>
#include <string.h>
#include "ds.h"


static BSTNode *Search(BSTNode *head, ElemType data)
{
	BSTNode *p = head;
	if(p != NULL)
	{
		if(p->data < data) 	return Search(p->rigt, data); 
		else if(p->data > data) return Search(p->left, data);		
	}
	return p;
}

static BSTNode *SearchParent(BSTNode *head, ElemType data)
{
	BSTNode *p = head;
	if(p != NULL)
	{
		BSTNode *ret = NULL;
		if(p->data < data) ret = SearchParent(p->rigt, data);
		else if(p->data > data) ret = SearchParent(p->left, data);
		
		return ret ? ret : p;
	}
	return p;
}

BSTree *InitBST(BSTree *tree)
{ 
	tree->head = NULL; 
	tree->layout = 0;
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
	if(tree->head == NULL)
	{
		tree->head = node;
		tree->layout = 1;
		return node;
	}

	BSTNode *p = SearchParent(tree->head, node->data);    //find node
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
	tree->layout++;
}

int DeleteBSTNode(BSTree *tree, ElemType data)
{
	BSTNode *p = Search(tree->head, data);
	if(p != NULL)
	{
		if(p->pare == NULL){
			if( p->left != NULL && p->rigt != NULL)
			{
				BSTNode *pl = p->rigt;
				while( pl->left != NULL) pl = pl->left;
				if(pl->rigt != NULL) pl->rigt->pare = pl->pare;
				if(pl->pare != NULL && pl->pare->rigt == pl) pl->pare->rigt = pl->rigt;
				if(pl->pare != NULL && pl->pare->left == pl) pl->pare->left = pl->rigt;
				p->data = pl->data;
				p = pl;
			}
			else if(p->left != NULL) tree->head = p->left;
			else if(p->rigt != NULL) tree->head = p->rigt;
		}
		else
		{
			if( p->left != NULL && p->rigt != NULL)
			{
				BSTNode *pl = p->rigt;
				while( pl->left != NULL) pl = pl->left;
				if(pl->rigt != NULL) pl->rigt->pare = pl->pare;
				if(pl->pare != NULL && pl->pare->rigt == pl) pl->pare->rigt = pl->rigt;
				if(pl->pare != NULL && pl->pare->left == pl) pl->pare->left = pl->rigt;

				pl->pare = p->pare;
				pl->left = p->left;
				pl->rigt = p->rigt;

				if(p->pare->rigt == p) p->pare->rigt = pl;
				if(p->pare->left == p) p->pare->left = pl;
				if(p->left != NULL) p->left->pare = pl;
				if(p->rigt != NULL) p->rigt->pare = pl;
			}
			else if(p->left != NULL)
			{
				p->left->pare = p->pare;
				if(p->pare->rigt == p) p->pare->rigt = p->left;
				if(p->pare->left == p) p->pare->left = p->left;
			}
			else if(p->rigt != NULL)
			{
				p->rigt->pare = p->pare;
				if(p->pare->rigt == p) p->pare->rigt = p->rigt;
				if(p->pare->left == p) p->pare->left = p->rigt;
			}
			else{
				if(p->pare->rigt == p) p->pare->rigt = NULL;
				if(p->pare->left == p) p->pare->left = NULL;
			}
		}
		free(p);
		tree->layout--;
	}
	return 1;
}

void ShowTree(BSTree *tree)
{
	ProductTreePicture(tree->head);
}