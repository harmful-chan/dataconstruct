#include "cbt.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ds.h"

static void DepictLastNodeClue(CBTNode* pare, CBTNode *node)
{
	if(node != NULL)
	{
		DepictLastNodeClue(pare, node->rtag ? NULL : node->rigt);
		DepictLastNodeClue(pare, node->ltag ? NULL : node->left);
		if(pare->ltag == 0)
		{
			pare->left = node;
			pare->ltag = 1;
			node->rigt = pare;
			node->rtag = 1;
		}		
	}
}

static void DepictNodeClue(CBTNode *pare, CBTNode *node)
{
	if(node != NULL)
	{
		DepictNodeClue(pare, node->left);
		if(node->left == NULL)
		{
			node->left = pare;
			node->ltag = 1;
		}
		if(pare != NULL && pare->rigt == NULL)
		{
			pare->rigt = node;
			pare->rtag = 1;
		}
		pare = node;
		DepictNodeClue(pare, node->rigt);
	}
}
static void DepictTreeClue(CBTTree *tree)
{
	DepictNodeClue(&(tree->super), tree->head);
	DepictLastNodeClue(&(tree->super), tree->head);
}

static void ObtainNodeClue(CBTNode *node)
{
	if(node != NULL)
	{
		ObtainNodeClue(node->ltag ? NULL : node->left);
		printf(" [%8d:%10p] [%1d] [%8d:%10p] [%1d] [%8d:%10p]\r\n", \
			node->left ? node->left->data : -1, 
			node->left, node->ltag, node->data, node, node->rtag, 
			node->rigt ? node->rigt->data : -1, node->rigt);
		ObtainNodeClue(node->rtag ? NULL : node->rigt);
	}
}
static void ObtainTreeClue(CBTTree *tree)
{
	printf(" [%8d:%10p] [%1d] [%8d:%10p] [%1d] [%8d:%10p]\r\n", \
		tree->super.left ? tree->super.left->data : -1, 
		tree->super.left, tree->super.ltag, tree->super.data, &(tree->super), 
		tree->super.rtag,
		tree->super.rigt ? tree->super.rigt->data : -1,  tree->super.rigt);
	ObtainNodeClue(tree->head);
}


static void CleanTreeSuper(CBTTree *tree)
{
	tree->super.rtag = 0;
	tree->super.rigt = NULL;
	tree->super.ltag = 0;
	tree->super.left = NULL;
}
static void CleanNodeClue(CBTNode *node)
{
	if(node != NULL)
	{
		if(node->ltag)
		{
			node->ltag = 0;
			node->left = NULL;
		}	
		if(node->rtag)
		{
			node->rtag = 0;
			node->rigt = NULL;
		}	
		CleanNodeClue(node->left);
		CleanNodeClue(node->rigt);
	}
}
static void CleanTreeClue(CBTTree *tree)
{
	CleanTreeSuper(tree);
	CleanNodeClue(tree->head);
}

static CBTNode *FindFirstNode(CBTNode *node)
{
	while(!node->ltag) 
		node = node->left;
	return node;
}

static CBTNode *FindNextNode(CBTNode *node)
{
	if(!node->rtag) return FindFirstNode(node->rigt);
	else return node->rigt;
}
CBTNode *FindCBTNode(CBTTree *tree, ElemType data)
{
	for(CBTNode *p = FindFirstNode(tree->head); p != NULL; p = FindNextNode(p))
	{
		if(p->data == data) return p; 
	}
	return NULL;
}

CBTTree *InitCBTTree(CBTTree *tree)
{
	CBTTree *p = F_INIT_TREE(CBTTree, tree);
	CleanTreeSuper(tree);
	p->name = CBT;
	return p;
}

CBTNode *InitCBTNode(CBTNode *node, ElemType data)
{
	CBTNode *p = F_INIT_NODE(CBTNode, node, data);
	p->ltag = 0;
	p->rtag = 0;
	return p;
}

CBTNode *InsertCBTNode(CBTTree *tree, CBTNode *node)
{
	CleanTreeClue(tree);
	CBTNode *p = F_INSERT_NODE(CBTNode, tree, node);
//	DepictNodeClue(&(tree->super), tree->head);
	DepictTreeClue(tree);
}

void DeleteCBTNode(CBTTree *tree, ElemType data)
{
	CBTNode *p = FindCBTNode(tree, data);
	CleanTreeClue(tree);
	free(p);
	// DepictNodeClue(&(tree->super), tree->head);
	DepictTreeClue(tree);

}

void ReleaseCBTTree(CBTTree *tree)
{
	CleanTreeClue(tree);
	F_RELEASE_TREE(CBTNode, tree);
}

void ShowCBTTree(CBTTree *tree)
{
	ObtainTreeClue(tree);
	CleanTreeClue(tree);
	F_SHOW_TREE(CBTNode, tree);
	// DepictNodeClue(&(tree->super), tree->head);
	DepictTreeClue(tree);

}