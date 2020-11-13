#include "avl.h"
#include <stddef.h>
#include <stdlib.h>

#define max(a, b) (a > b ? a : b)

static int Whirl(WhirlType mode, AVLNode *pare, AVLNode *pa, AVLNode *pb, AVLNode *pc)
{
    switch(mode)
    {
        case WHIRL_MODE_CP:{  
            if( isLeftChild(pare, pa) ) pare->left = pb;
            if( isRigtChild(pare, pa) ) pare->rigt = pb;
            return 0;
        }break;
        case WHIRL_MODE_LL :{    
            Whirl(WHIRL_MODE_CP, pare, pa, pb, pc);
            pa->left = pb->rigt;
            pb->rigt = pa;    
        }break;
        case WHIRL_MODE_RR:{       
            Whirl(WHIRL_MODE_CP, pare, pa, pb, pc);
            pa->rigt = pb->left;
            pb->left = pa;   
        }break;
        case WHIRL_MODE_LR:{
            Whirl(WHIRL_MODE_RR, pa, pb, pc, NULL);
            Whirl(WHIRL_MODE_LL, pare, pa, pc, pb);
        }break;
        case WHIRL_MODE_RL:{    
            Whirl(WHIRL_MODE_LL, pa, pb, pc, NULL);
            Whirl(WHIRL_MODE_RR, pare, pa, pc, pb);
        }break;
        default : break;
    }
    return 0;//Traverse(pare, pa);
}
static WhirlType GetAdjustMode(AVLNode *node)
{
    if( haveLeftChild(node) && haveRigtChild(node) )    //have two child.
    {
        if( haveLeftChild(node->left->rigt) || haveRigtChild(node->left->rigt) )
            return WHIRL_MODE_LR;
        else if( haveLeftChild(node->rigt->left) || haveRigtChild(node->rigt->left) ) 
            return WHIRL_MODE_RL;
        else if( haveLeftChild(node->left->left) || haveRigtChild(node->left->left) )
            return WHIRL_MODE_LL; 
        else //if( haveLeftChild(node->rigt->right) || haveRigtChild(node->rigt->rigt) )
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
static int WhrilNodeBalance(AVLNode *pare, AVLNode *node)
{
    int ret = 0;
    WhirlType type = GetAdjustMode(node);
    switch(type)
    {
        case WHIRL_MODE_LL : ret = Whirl(type, pare, node, node->left, node->left->left); break;
        case WHIRL_MODE_RR : ret = Whirl(type, pare, node, node->rigt, node->rigt->rigt); break;
        case WHIRL_MODE_LR : ret = Whirl(type, pare, node, node->left, node->left->rigt); break;
        case WHIRL_MODE_RL : ret = Whirl(type, pare, node, node->rigt, node->rigt->left); break;
        default : break;
    }
    return ret;
}
static int AdjustNodeBalance(AVLNode *pare, AVLNode *node)
{
    if(node != NULL)
    {
        int a = AdjustNodeBalance(node, node->left);
        int b = AdjustNodeBalance(node, node->rigt);
        
        // not balance 
        if(abs(a - b) >= 2)
            if(a > b) a = WhrilNodeBalance(pare, node);
            else b = WhrilNodeBalance(pare, node);

        node->height = a - b  ;
        return max(a, b) + 1;
    }
    return 0;
}
static AVLNode *AdjustTreeBalance(AVLTree *tree)
{
    AVLNode *root = tree->head;
    if(haveLeftChild(root) && haveRigtChild(root))
    {
        AVLNode *rl = root->left;
        AVLNode *rlr = root->left->rigt;
        AVLNode *rr = root->rigt;
        AVLNode *rrl = root->rigt->left;
        AdjustNodeBalance(NULL, root);
        if(isRigtChild(rl, root)) tree->head = rl;    // LL
        else if(isRigtChild(rlr, root)) tree->head = rlr;    // LR
        else if(isLeftChild(rr, root)) tree->head = rr;    //RR
        else if(isLeftChild(rrl, root)) tree->head = rrl;    //RL
    }else if(haveLeftChild(root))
    {
        AVLNode *rl = root->left;
        AdjustNodeBalance(NULL, root);
        if(isRigtChild(rl, root)) tree->head = rl;
    }
    else
    {
        AVLNode *rr = root->rigt;
        AdjustNodeBalance(NULL, root);
        if(isLeftChild(rr, root)) tree->head = rr;
    }
}

#pragma region Interfaces

AVLTree *InitAVLTree(AVLTree *tree)
{
    AVLTree *p = F_INIT_TREE(AVLTree, tree);
    p->name = AVL;
    return p;
}

AVLNode *InitAVLNode(AVLNode *node, ElemType data)
{
    AVLNode *p = F_INIT_NODE(AVLNode, node, data);
    p->height = 0;
    return p;
}

AVLNode *InsertAVLNode(AVLTree *tree, AVLNode *node)
{
    AVLNode *p = F_INSERT_NODE(AVLNode, tree, node);
    AdjustTreeBalance(tree);
}
void DeleteAVLNode(AVLTree *tree, ElemType data)
{

    F_DELETE_NODE(AVLTree, tree, data);
    AdjustTreeBalance(tree);
}
void ReleaseAVLTree(AVLTree *tree)
{
    F_RELEASE_TREE(AVLTree, tree);
}
void ShowAVLTree(AVLTree *tree)
{
    F_SHOW_TREE(AVLTree, tree);
}
#pragma endregion

