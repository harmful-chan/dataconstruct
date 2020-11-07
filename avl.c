#include "avl.h"
#include <stddef.h>
#include <stdlib.h>

#define max(a, b) (a > b ? a : b)

static enum WHIRL_MODE AdjustMode(AVLNode *node);
static int Whirl(enum WHIRL_MODE mode, AVLNode *pa, AVLNode *pb, AVLNode *pc);
static int AdjustBalance(AVLNode *node);
static int Traverse(AVLNode *node);

AVLTree *InitAVLTree(AVLTree *tree)
{
    return (AVLTree *)InitBSTree((BSTree *)tree);
}

AVLNode *InitAVLNode(AVLNode *node, ElemType data)
{
    AVLNode *p = (AVLNode *)InitBSTNode((BSTNode *)node, data);
    p->height = 0;
    return p;
}

AVLNode *InsertAVLNode(AVLTree *tree, AVLNode *node)
{
    AVLNode *p = (AVLNode *)InsertBSTNode((BSTree *)tree, (BSTNode *)node);
    Traverse(tree->head);

    // change parent point to 'tree->head'   
    if(tree->head->pare != NULL)    
        tree->head = tree->head->pare;
}
int DeleteAVLNode(AVLTree *tree, ElemType data)
{
    
}
static enum WHIRL_MODE AdjustMode(AVLNode *node)
{
    if( haveLeftChild(node) && haveRigtChild(node) )    //have two child.
    {
        if( haveLeftChild(node->left) || haveRigtChild(node->left) )
            return WHIRL_MODE_LL;
        else 
            return WHIRL_MODE_RR;
    }
    else    //one child
    {
        if(haveLeftChild(node))     //only left child.
        {
            if(node->left->left != NULL) return WHIRL_MODE_LL;
            else return WHIRL_MODE_LR;
        }    
        else    //only right child
        {
            if(node->rigt->rigt != NULL) return WHIRL_MODE_RR;
            else return WHIRL_MODE_RL;
        }
    }
}
static int Whirl(enum WHIRL_MODE mode, AVLNode *pa, AVLNode *pb, AVLNode *pc)
{
    switch(mode)
    {
        case WHIRL_MODE_CP:{  
            if( isLeftChild(pa) ) pa->pare->left = pb;
            if( isRigtChild(pa) ) pa->pare->rigt = pb;
            return 0;
        }break;
        case WHIRL_MODE_LL :{    
            if( pa->pare != NULL ) 
                Whirl(WHIRL_MODE_CP, pa, pb, pc);
            pa->left = pb->rigt;
            pb->pare = pa->pare;   
            pa->pare = pb;  
            pb->rigt = pa;    
        }break;
        case WHIRL_MODE_RR:{       
            if( pa->pare != NULL ) 
                Whirl(WHIRL_MODE_CP, pa, pb, pc);
            pa->rigt = pb->left;
            pb->pare = pa->pare; 
            pa->pare = pb;  
            pb->left = pa;   
        }break;
        case WHIRL_MODE_LR:{   
            Whirl(WHIRL_MODE_RR, pb, pc, NULL);
            if( pa->pare != NULL ) 
                Whirl(WHIRL_MODE_CP, pa, pb, pc);
            Whirl(WHIRL_MODE_LL, pa, pc, pb);
        }break;
        case WHIRL_MODE_RL:{    
            Whirl(WHIRL_MODE_LL, pb, pc, NULL);
            if( pa->pare != NULL ) 
                Whirl(WHIRL_MODE_CP, pa, pb, pc);
            Whirl(WHIRL_MODE_RR, pa, pc, pb);
        }break;
        default : break;
    }
    return Traverse(pa);
}
static int AdjustBalance(AVLNode *node)
{
    int ret = 0;
    enum WHIRL_MODE type = AdjustMode(node);
    switch(type)
    {
        case WHIRL_MODE_LL : ret = Whirl(type, node, node->left, node->left->left); break;
        case WHIRL_MODE_RR : ret = Whirl(type, node, node->rigt, node->rigt->rigt); break;
        case WHIRL_MODE_LR : ret = Whirl(type, node, node->left, node->left->rigt); break;
        case WHIRL_MODE_RL : ret = Whirl(type, node, node->rigt, node->rigt->left); break;
        default : break;
    }
    return ret;
}
static int Traverse(AVLNode *node)
{
    if(node != NULL)
    {
        int a = Traverse(node->left);
        int b = Traverse(node->rigt);
        
        // not balance 
        if(abs(a - b) >= 2)
            if(a > b) a = AdjustBalance(node);
            else b = AdjustBalance(node);

        node->height = a - b  ;
        return max(a, b) + 1;
    }
    return 0;
}
