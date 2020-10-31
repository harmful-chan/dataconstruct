#include "bst.h"
#include <stdlib.h>
#include "queue.h"
#include <stdio.h>
#include <string.h>
#include "ds.h"

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

	BSTNode *p = tree;	p = SearchParent(tree, node->data);    //find node
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
/*
void PrintTree(BSTNode *d[21][21])
{
	for(int i =0; i <= 5; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			if(ds[i][j] == NULL) printf("     ");
			else printf("%-2d%s", d[i][j]->data, \
				(d[i][j+1] != NULL) ? "---": "   ");
		}
		printf("\r\n");
		printf("\r\n");
	}
}

#define EQUAL(s1, s2, r1, r2) \
	(s1) ? s1->data == (s2) ? (r1) : (r2) : (r2)

int EqualData(BSTNode *s1, BSTNode *s2)
{
	if( s1 == NULL || s2 == NULL) return 0;
	else return s1->data == s2->data;
}
void PrintTree1(BSTNode *(*d)[21][21])
{
	static char l = '/', r = '\\';
	for(int i =0 ; i< 21; i++)
	{
		char n[21];	
		memset(n, '-', 21);
		for(int j = 1; j < 20; j++)
		{
			if((*d)[i][j])
			{
				if( (*d)[i][j]->left )
				{
					n[j-1] = EqualData( (*d)[i][j]->left, (*d)[i+1][j-1] ) ? '/' : '-';
					n[j-1] = EqualData( (*d)[i][j], (*d)[i+1][j-1] ) ? '/' : n[j-1];
				}
				if( (*d)[i][j]->rigt )
				{
					n[j+1] = EqualData( (*d)[i][j]->rigt , (*d)[i+1][j+1]) ? '\\' : '-';
					n[j+1] = EqualData( (*d)[i][j], (*d)[i+1][j+1] ) ? '\\' : n[j+1];
				}	
			}
		}
		for(int j = 0; j < 21; j++)
		{
			if( (*d)[i][j] == NULL) printf(" - ");
			else if( EqualData( (*d)[i][j], (*d)[i+1][j-1] ) ) printf(" / ");
			else if( EqualData( (*d)[i][j], (*d)[i+1][j+1] ) ) printf(" \\ ");
			else printf(" %-2d", (*d)[i][j]->data);
		}
		printf("\r\n");
		for(int j = 0; j < 21; j++)
		{
			if(n[j] == '-') printf(" %c ", n[j]);
			else if(n[j] == '/') printf("  %c", n[j]);
			else if(n[j] == '\\') printf("%c  ", n[j]);
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
	PrintArray(&ds1, 21);
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
	PrintArray(&ds2, 21);
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
	PrintArray(&ds3, 21);
		printf("\r\n");
	PrintTree1(&ds3);
}
void ShowTree(BSTree *tree)
{
	Change(tree);
}
*/