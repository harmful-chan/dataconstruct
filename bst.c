#include "bst.h"
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>
#include <string.h>
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

static BSTNode *ds[21][21] ={NULL};
void ProductTree(BSTree *tree)
{
	static int i=-1, j=-1;
	if(tree != NULL)
	{
		i++;
		ProductTree(tree->left);
		j++;
		if(ds[i][j] != NULL)
		{
			
			for(int l = 0; l < 21-i; l++)
			{
				for(int m = 0; m < 21; m++)
				{
					ds[20-l][m] = ds[19-l][m];
				}
			}
			for(int l = 0; l < 21; l++) ds[i][l] = NULL;
		}
		ds[i][j] = tree;
		i--;
		ProductTree(tree->rigt); 
		j--;
	}
}

void PrintArray(BSTNode *dist[21][21], int row)
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < 21; j++)
		{
			if(dist[i][j] == NULL) printf(" - ");
			else printf(" %-2d", dist[i][j]->data);
		}printf("\r\n");
	}
}

void PrintTree(BSTNode *dist[21][21])
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

#define EQUAL(s1, s2, r1, r2) \
	(s1) ? s1->data == (s2) ? (r1) : (r2) : (r2)
void PrintTree1(BSTNode *dist[21][21])
{
	for(int i =0 ; i< 21; i++)
	{
		char next[21];	
		memset(next, '-', 21);
		for(int j = 1; j < 20; j++)
		{
			if(dist[i][j] != NULL)
			{
				if(next[j-1] != '\\')
				{
					int k = 0;
					for(int l = 0; l < j; j++)
					{
						//TODO
					}
				}
					next[j-1]=EQUAL(dist[i][j]->left, dist[i+1][j-1]->data, \
					'/', '-');
				next[j+1]=EQUAL(dist[i][j]->rigt, dist[i+1][j+1]->data, '\\', '-');
			}
		}
		for(int j = 0; j < 21; j++)
		{
			if(dist[i][j] == NULL) printf(" - ");
			else printf(" %-2d", dist[i][j]->data);
		}
		printf("\r\n");
		for(int j = 0; j < 21; j++)
		{
			if(next[j] == '-') printf(" %c ", next[j]);
			else if(next[j] == '/') printf("  %c", next[j]);
			else if(next[j] == '\\') printf("%c  ", next[j]);
		}
		printf("\r\n");
	}
}
void Change(BSTree *tree)
{
	ProductTree(tree);
	PrintTree(ds);
	//rotate -90 angle	
	BSTNode *ds1[21][21] = {NULL};
	for(int i = 0; i < 21; i++)
	{
		for(int j = 0; j < 21; j++)
		{
			ds1[j][20-i] = ds[i][j];
		}
	}
	PrintArray(ds1, 21);
	printf("\r\n");
	//rotate 45 angle
	BSTNode *ds2[21][21] = {NULL};
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			ds2[j][10-i+j] =  ds1[j][20-i];
		}
	}
	PrintArray(ds2, 21);
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
	PrintArray(ds3, 21);
		printf("\r\n");
	PrintTree1(ds3);
}
void ShowTree(BSTree *tree)
{
	Change(tree);
}
