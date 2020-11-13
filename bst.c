#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ds.h"


static void ReleaseBSTNode(BSTNode * node)
{
	if(node != NULL)
	{
		ReleaseBSTNode(node->left);
		ReleaseBSTNode(node->rigt);
		free(node);
	}
}

#pragma region Interfaces
BSTNode *Search(BSTNode *head, ElemType data)
{
	BSTNode *p = head;
	if(p != NULL)
	{
		if(p->data < data) 	return Search(p->rigt, data); 
		else if(p->data > data) return Search(p->left, data);		
	}
	return p;
}

BSTNode *SearchParent(BSTNode *head, ElemType data)
{
	BSTNode *p = head;
	if(p != NULL)
	{
		BSTNode *ret = NULL;
		if(p->data < data) ret = SearchParent(p->rigt, data);
		else if(p->data > data) ret = SearchParent(p->left, data);
		else if(p->data == data) return NULL;		
		return ret ? ret : p;
	}
	return p;
}

BSTTree *InitBSTTree(BSTTree *tree)
{ 
	tree->head = NULL; 	
	tree->name = BST;
	return tree;
}

BSTNode *InitBSTNode(BSTNode *node, ElemType data)
{
	node->data = data;
	node->left = NULL;
	node->rigt = NULL;
	return node;
}

BSTNode *InsertBSTNode(BSTTree *tree, BSTNode *node)
{
	if( Search(tree->head, node->data) == NULL )
	{
		if(tree->head == NULL)
		{
			tree->head = node;
			return node;
		}

		BSTNode *p = SearchParent(tree->head, node->data);    //find node
		if( sureLeft(p, node) )    //left
		{
			node->left = p->left;
			p->left = node;
		}
		else if( sureRigt(p, node) )
		{
			node->rigt = p->rigt;
			p->rigt = node;
		}
	}
}

void DeleteBSTNode(BSTTree *tree, ElemType data)
{
	BSTNode *p = Search(tree->head, data);
	if(p != NULL)
	{
		if(tree->head->data == data)    // root node.
		{
			if(haveLeftChild(p) && !haveRigtChild(p)) tree->head = p->left;
			else if(haveRigtChild(p) && !haveLeftChild(p)) tree->head = p->rigt;
		}
		else    // not root node.
		{
			BSTNode * pare = SearchParent(tree->head, p->data);
			if(haveLeftChild(p) && !haveRigtChild(p))
			{
				if(isLeftChild(pare, p))
					pare->left = p->left;
				else
					pare->rigt = p->left;
			}
			else if(haveRigtChild(p) && !haveLeftChild(p))
			{
				if(isLeftChild(pare, p))	
					pare->left = p->rigt;
				else	
					pare->rigt = p->rigt;
			}
			else if(!haveRigtChild(p) && !haveLeftChild(p)){
				if(isLeftChild(pare, p))	
					pare->left = NULL;
				else	
					pare->rigt = NULL;
			}
		}
		if( haveLeftChild(p) && haveRigtChild(p) )    // have two child.
		{
			//quary apposite node.
			BSTNode *pl = p->rigt;
			while( pl->left != NULL && pl->left->left != NULL ) 
				pl = pl->left;
			BSTNode *pls = pl->left;    //apposite node. 
			if(pls == NULL)    //
			{
				p->rigt = pl->rigt;
				p->data = pl->data;
				p=pl;
			}
			else
			{
				pl->left = pls->rigt;
				p->data = pls->data;
				p=pls;
			}
		}
		free(p);
	}
}

void ReleaseBSTTree(BSTTree *tree)
{
	ReleaseBSTNode(tree->head);
}

void ShowBSTTree(BSTTree *tree)
{
	ProductTreePicture(tree->head);
}
#pragma endregion