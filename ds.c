#include "ds.h"
#include <stddef.h>
#include <stdio.h>
#define NotNull(s ,r) (s ? s->r : NULL)

static BSTNode *ds[21][21] ={NULL};

static void CopyDSArray(DSNode (*src)[21][21], DSNode (*dst)[21][21])
{
    for(int i = 0; i < 21; i++)
	for(int j = 0; j < 21; j++)
        (*dst)[i][j] = (*src)[i][j];
}

static void ShiftLine(BSTNode *(*d)[21][21], int start, int end)
{
    int offsize = end - start;
    // row index of '[s ~ 19][0~20]' move down line one.
	for(int i = 0; i < 21-offsize; i++)
	for(int j = 0; j < 21; j++)
		(*d)[20-i][j] = (*d)[20-i-offsize][j];

    //row index of 's' clear.
	for(int i = 0; i < offsize; i++) 
    for(int j = 0; j < 21; j++)
    //    if( (*d)[start+offsize+i][j] == (*d)[start+i][j]) 
	    (*d)[start+i][j] = NULL;

    // //if index of [1 ~ 20][0] have pare pointer, copy.
	// for(int i = offsize; i >= 0; i--)
    // if( NotNull((*d)[start+i][0], pare) ) 
    //     (*d)[start+i-1][0] = (*d)[start+i][0];
	
    // //same as above.
	// for(int i = offsize; i >= 0; i--) 
	// for(int j = 1; j < 21; j++) 
    //     if( (*d)[start+i][j] )
	// 	if( (*d)[start+i][j]->pare && 
    //         (*d)[start+i][j]->pare != (*d)[start+i][j-1] &&
    //         (*d)[start+i][j]->pare == (*d)[start+i-1][j])
	// 		(*d)[start+i-1][j] = (*d)[start+i][j]; 
}
static void RepairRela(DSNode (*p)[21][21])
{
    for(int i = 0 ; i < 21; i++)
	{
        int j = 0;
	    for(; j < 21; j++) 
        if( (*p)[j][i].node == NULL ) 
            break;

        int k = 0;
        for(k = j; k < 21; k++)
        if((*p)[k][i].node != NULL && (*p)[k][i].node->pare == (*p)[j-1][i].node)
            break;

        if(j != 0 && k < 21)
        for(int l = j; l < k; l++)
            (*p)[l][i] = (*p)[j-1][i];
    }
}
static void FreshTreeDS(BSTree *tree)
{
	static int i=-1, j=-1;
	if(tree != NULL)
	{
		i++;
		FreshTreeDS(tree->left);
		j++;

        for(int l = 0; l < i; l++)
        if(ds[i-l][j] != NULL){
            ShiftLine(&ds, i-l, i+1);
            break;
        } 
        ds[i][j] = tree;
		i--; 
		FreshTreeDS(tree->rigt);
		j--;
	}
}

void RotateN90(DSNode (*p)[21][21])
{
    DSNode d[21][21] = {{NULL, 0, 0 ,0}};
	for(int i = 0; i < 21; i++)
	for(int j = 0; j < 21; j++)
    {
        d[j][20-i] = (*p)[i][j];
    }
    CopyDSArray(&d,p);
}
void Rotate45(DSNode (*p)[21][21])
{
    DSNode d[21][21] = {{NULL, 0, 0 ,0}};
	for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++)
    {
        d[j][10-i+j] = (*p)[j][20-i];
    }
    CopyDSArray(&d,p);
}
void VerticalStretch(DSNode (*p)[21][21])
{
    DSNode d[21][21] = {{NULL, 0, 0 ,0}};
	for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++)
		d[10-i+j][i+j] = (*p)[j][i+j];

	for(int i = 0; i < 10; i++)
		d[i][10+i] =  (*p)[i][10+i];
    CopyDSArray(&d,p);

}

void PrintDSNodeArray(DSNode (*d)[21][21], int mode, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            DSNode p = (DSNode)(*d)[i][j];
            if( !p.node ){ printf("    " ); continue;} 
            switch(mode)
            {
                case 0: {
                    printf("[%-2d]", p.node->data);
                    }break;
                case 1: {
                    printf("%-2d", p.node->data);
                    if( p.haveRigt ) printf("--");
                    else printf("  ");
                    }break;
                case 2:{
                    if( p.haveLeft ) printf("--");
                    else printf("  ");
                    printf("%-2d", p.node->data);
                    }break;
                case 3:{
                    if( i > 0 && j < 20  && (*d)[i-1][j+1].node == p.node)
                       printf("  / ");
                    else printf("[%-2d]", p.node->data);
                    //printf("[%-2d]", p.node->data);

                    }break;
                default : break;
            }
        }
        printf("\r\n");
        for(int j = 0; j < col; j++)
        {
            DSNode p = (DSNode)(*d)[i][j];

            if( !p.node ) { printf("    " ); continue;}
    
            switch(mode)
            {
                case 0: {
                    printf("    ");
                    }break;
                case 1: {
                    if( p.haveLeft ) printf("| ");
                    else printf("  ");
                    printf("  ");
                    }break;
                case 2:{
                    printf("  ");
                    if( p.haveRigt ) printf("| ");
                    else printf("  ");
                    }break;
                case 3:{
                    if( p.haveLeft ) printf("/");
                    else printf(" ");
                    printf("  ");
                    if( p.haveRigt ) printf("\\");
                    else printf(" ");
                    
                    }break;
                default : break;
            }
        }
        printf("\r\n");
        
    }
}

void *ProductTreePicture(BSTree *tree)
{
	FreshTreeDS(tree);
	DSNode pic[21][21] = {{NULL, 0, 0, 0}};
	for(int i = 0 ;i < 21; i++)
	for(int j = 0; j < 21; j++)
		pic[i][j].node = ds[i][j];
	
	PrintDSNodeArray(&pic, 0, 10, 21);
    
    RepairRela(&pic);    
	PrintDSNodeArray(&pic, 0, 10, 21);
        
	for(int i = 0 ; i < 21; i++)
	for(int j = 0 ; j < 21; j++)
    {
        BSTNode *p  = (BSTNode *)pic[i][j].node;
        BSTNode *pr = (BSTNode *)pic[i][j+1].node;
        BSTNode *pl = (BSTNode *)pic[i+1][j].node;

        pic[i][j].haveRigt = p ? pr ? p->rigt == pr || p == pr? 1 : 0 : 0 : 0;
        pic[i][j].haveLeft = p ? pl ? p->left == pl || p == pl ? 1 : 0 : 0 : 0;

    }
    PrintDSNodeArray(&pic, 1, 10, 21);
	
    RotateN90(&pic);
    //PrintDSNodeArray(&pic, 2, 6, 21);
	//printf("\r\n");
	
    //rotate 45 angle
	Rotate45(&pic);
    //PrintDSNodeArray(&pic, 0, 8, 21);
	//printf("\r\n");
	
    //search
	VerticalStretch(&pic);
    PrintDSNodeArray(&pic, 3, 16, 21);
    
	return NULL;
}

