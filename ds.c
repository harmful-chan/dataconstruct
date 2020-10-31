#include "ds.h"
#include <stddef.h>
#include <stdio.h>
#define NotNull(s ,r) (s ? s->r : NULL)

static DSNode ds[21][21] ={NULL};

static void CopyDSArray(DSNode (*src)[21][21], DSNode (*dst)[21][21])
{
    for(int i = 0; i < 21; i++)
	for(int j = 0; j < 21; j++)
        (*dst)[i][j] = (*src)[i][j];
}

static void ShiftLine(DSNode (*d)[21][21], int start, int end)
{
    int offsize = end - start;

    // row index of '[s ~ 19][0~20]' move down line one.
	for(int i = 0; i < 21-offsize; i++)
	for(int j = 0; j < 21; j++)
		(*d)[20-i][j] = (*d)[20-i-offsize][j];

    //row index of 's' clear.
	for(int i = 0; i < offsize; i++) 
    for(int j = 0; j < 21; j++)
	    (*d)[start+i][j].node = NULL;
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
        if(ds[i-l][j].node != NULL){
            ShiftLine(&ds, i-l, i+1);
            break;
        } 
        ds[i][j].node = tree;
		i--; 
		FreshTreeDS(tree->rigt);
		j--;
	}
}
static void RepairRela(DSNode (*p)[21][21])
{
    //fill the gap.
    for(int i = 0 ; i < 21; i++)
	{
        int start = 0;
        int end = 0;
	    
        //get start index.
        for(; start < 21; start++) 
        if( (*p)[start][i].node == NULL ) 
            break;

        //get end index.
        for(end = start; end < 21; end++)
        if((*p)[end][i].node != NULL && 
        (*p)[end][i].node->pare == (*p)[start-1][i].node)
            break;

        //add '/'
        if(start != 0 && end < 21)
        for(int l = start; l < end; l++)
            (*p)[l][i] = (*p)[start-1][i];

        //not tail again.
        if(end < 21) i--;
    }

    //fill 'have*'
    for(int i = 0 ; i < 21; i++)
	for(int j = 0 ; j < 21; j++)
    {
        BSTNode *q  = (*p)[i][j].node;
        BSTNode *qr = (*p)[i][j+1].node;
        BSTNode *ql = (*p)[i+1][j].node;

        (*p)[i][j].haveRigt = q ? qr ? q->rigt == qr || q == qr ? 1 : 0 : 0 : 0;
        (*p)[i][j].haveLeft = q ? ql ? q->left == ql || q == ql ? 1 : 0 : 0 : 0;
    }
}

static void RotateN90(DSNode (*p)[21][21])
{
    DSNode d[21][21] = {{NULL, 0, 0 ,0}};
	for(int i = 0; i < 21; i++)
	for(int j = 0; j < 21; j++)
        d[j][20-i] = (*p)[i][j];
    
    CopyDSArray(&d,p);
}
static void Rotate45(DSNode (*p)[21][21])
{
    DSNode d[21][21] = {{NULL, 0, 0 ,0}};
	for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++)
        d[j][10-i+j] = (*p)[j][20-i];
    
    CopyDSArray(&d,p);
}
static void VerticalStretch(DSNode (*p)[21][21])
{
    DSNode d[21][21] = {{NULL, 0, 0 ,0}};
	for(int i = 0; i < 10; i++)
	for(int j = 0; j < 10; j++)
		d[10-i+j][i+j] = (*p)[j][i+j];

	for(int i = 0; i < 10; i++)
		d[i][10+i] =  (*p)[i][10+i];
    
    CopyDSArray(&d,p);
}
static void PrintDSNodeArray(DSNode (*d)[21][21], int mode, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        printf("%-2d", i);
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
        printf("  ");

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
	//PrintDSNodeArray(&ds, 0, 15, 21);   
    RepairRela(&ds);    
	//PrintDSNodeArray(&ds, 0, 15, 21);
    RotateN90(&ds);
    // PrintDSNodeArray(&ds, 2, 10, 21);
	Rotate45(&ds);
    // PrintDSNodeArray(&ds, 0, 10, 21);
	VerticalStretch(&ds);
    PrintDSNodeArray(&ds, 3, 16, 21);    
	return NULL;
}

