#include "bst.h"
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>

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
	if(tree->data == -1)
	{
		tree->data = node->data;
		return tree;
	}

	BSTNode *p = tree;
	p = Search(tree, node->data);    //find node
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
	BSTNode *best = Search(tree, data);
	if(best->left != NULL && best->left->data == data)
		best = best->left;	
	else if(best->right != NULL && best->rigt->data == data)
		best = best->rigt;
	else if(best->data == data)
		best = best;	
	else best = NULL;
	
	if(best != NULL)
	{
		if( p->pare->left == p )
		{
			if( p->rigt != NULL  )
			{
				p->rigt->pare = p->pare;
				p->pare->left = p->rigt;

				p->left->pare = p->rigt;
				
			}
		}
	}
}

int ds[10][10];
void ShowPrefix(BSTree *tree)
{
	static int i=-1, j=-1;
	if(tree != NULL)
	{
		i++;
		ShowPrefix(tree->left);
		j++;
		ds[i][j] = tree->data;
		i--;
		ShowPrefix(tree->rigt); 
		j--;
	}
}
void ShowInfix(BSTree *tree){}
void ShowPostfix(BSTree *tree){}
void Show(BSTree *tree)
{

	for(int i =0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			ds[i][j] = -1;
		}
	}
	/*
	Queue q;
	int i=0, j = 0;
	BSTNode *old = NULL;
	InitQueue(&q);
	Entry(&q, (qlm_t)tree);
	while(!q.isEmpty)
	{
		BSTNode *p = (BSTNode *)Out(&q);
		if(p->pare == NULL)    //root
		{
			ds[0][0] = p->data;
		}
		else if( p->pare == old )
		{
			ds[i][++j] = p->data;
		}
		else
		{
			j=0;
			ds[++i][j] = p->data;
			old = p->pare;
		}
		if(p->left != NULL) Entry(&q, (qlm_t)p->left);
		if(p->rigt != NULL) Entry(&q, (qlm_t)p->rigt);
	}*/

	ShowPrefix(tree);
	/*
	for(int i =0; i <= 9; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(ds[i-j][j] == -1) printf("    ");
			else printf(" %2d ", ds[i-j][j]);
		}
		printf("\r\n");
	}*/
	for(int i =0; i <= 9; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			if(ds[i][j] == -1) printf("     ");
			else printf("%-2d%s", ds[i][j], \
				(ds[i][j+1] != -1) ? "---": "   ");
		}
		printf("\r\n");
		for(int j = 0; i<9 && j <= 9; j++)
		{
			if(ds[i+1][j] == -1) 
				printf("     ");
			else if(ds[i][j] != -1) 
				printf("|    ");
		}
		printf("\r\n");
	}
}
