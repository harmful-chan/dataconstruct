#include "bst.h"
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>

static inline 
BSTNode *SearchParent(BSTree *tree, ElemType data)
{
	BSTNode *p = tree;
	
	if(data < p->data && p->left != NULL)
		p = SearchParent(p->left, data);
	else if(data > p->data && p->rigt != NULL)
		p = SearchParent(p->rigt, data);
	
	return p;
}

static inline
BSTNode *Search(BSTree *tree, ElemType data)
{
	BSTNode *p = tree;
	if(p != NULL)
	{
		p = SearchParent(tree, data);
		BSTNode *ret = NULL;
		ret=(p->data == data)?p:NULL;
		ret=p->left?(p->left->data == data)?p->left:NULL:NULL;
		ret=p->rigt?(p->rigt->data == data)?p->rigt:NULL:NULL;
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
	BSTNode *p = Search(tree, data);
	if(tree == p)
	{
		//TODO
	}else
	{

	}
}


void ShowInfix(BSTree *tree){}
void ShowPostfix(BSTree *tree){}

static BSTNode *ds[10][10] ={NULL};
void ProductTree(BSTree *tree)
{
	static int i=-1, j=-1;
	if(tree != NULL)
	{
		i++;
		ProductTree(tree->left);
		j++;
		ds[i][j] = tree;
		i--;
		ProductTree(tree->rigt); 
		j--;
	}
}
void PrintTree(BSTNode *dist[10][10])
{

	for(int i =0; i <= 5; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			if(ds[i][j] == NULL) printf("     ");
			else printf("%-2d%s", dist[i][j]->data, \
				(dist[i][j+1] != NULL) ? "---": "   ");
		}
		printf("\r\n");
		for(int j = 0; i<9 && j <= 9; j++)
		{
			if(dist[i+1][j] == NULL) 
				printf("     ");
			else if(dist[i][j] != NULL) 
				printf("|    ");
		}
		printf("\r\n");
	}
}

void Change(BSTree *tree)
{
	ProductTree(tree);
	PrintTree(ds);
	//rotate -90 angle	
	BSTNode *ds1[10][10] = {NULL};
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			ds1[j][9-i] = ds[i][j];
		}
	}
	for(int i =0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(ds1[i][j] != NULL)
				printf(" %-2d", ds1[i][j]->data);
			else printf(" - ");
		}printf("\r\n");
	}	
	printf("\r\n");
	//rotate 45 angle
	BSTNode *ds2[10][21] = {NULL};
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			ds2[j][10-i+j] =  ds1[j][9-i];
		}
	}
	for(int i =0; i < 10; i++)
	{
		for(int j = 0; j < 21; j++)
		{
			if(ds2[i][j] != NULL)
				printf(" %-2d", ds2[i][j]->data);
			else printf(" - ");
		}printf("\r\n");
	}
	
	printf("\r\n");
	//search
	BSTNode *ds3[21][21] = {NULL};
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			ds3[10-i+j][i+j] = ds2[j][i+j];
		}
	}
	for(int i = 0; i < 10; i++)
		ds3[i][10+i] =  ds2[i][10+i];
	for(int i =0; i < 21; i++)
	{
		for(int j = 0; j < 21; j++)
		{
			if(ds3[i][j] != NULL)
				printf(" %-2d", ds3[i][j]->data);
			else printf(" - ");
		}printf("\r\n");
	}
		printf("\r\n");
}
void ShowTree(BSTree *tree)
{
	for(int i =0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			ds[i][j] = NULL;
		}
	}
	ProductTree(tree);
		printf("\r\n");
}
