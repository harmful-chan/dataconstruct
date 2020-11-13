#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "typedef.h"
#include "avl.h"
#include "cbt.h"

BSTTree btree;
AVLTree atree;
CBTTree ctree;

void Show(TreeName name)
{
	system("clear");
	char str[10] = {'\0'};
	switch(name)
	{
		case BST: {ShowBSTTree(&btree); memcpy(str, "bst", 3);} break;
		case AVL: {ShowAVLTree(&atree); memcpy(str, "avl", 3);} break;
		case CBT: {ShowCBTTree(&ctree); memcpy(str, "cbt", 3);} break;
		default : break;
	}
	printf("current type is : %s\r\n", str );
}

char ReadKey()
{
	char c= '\0';
	// cmd line :
	printf("# script > "); 
	scanf("%c", &c); 
	printf("\r\n");
	return c;
}

int main(void)
{		

	InitBSTTree(&btree);
	InitAVLTree(&atree);
	InitCBTTree(&ctree);

	int tmp[] = {10, 20, 30, 40, 50, 25, 3, 4, 15, 13};
	TreeName curName = CBT;
	while(1)
	{
		Show(curName);
		switch(ReadKey())
		{
			case 'm':{
				char s[10] = {'\0'};
				scanf("%s", &s);
				if( s[0]=='a'&&s[1]=='v'&&s[2]=='l' ) curName = AVL;
				if( s[0]=='b'&&s[1]=='s'&&s[2]=='t' ) curName = BST;
				if( s[0]=='c'&&s[1]=='b'&&s[2]=='t' ) curName = CBT;
				memset(&s, '\0', 10);
			}break;
			case 'i': {
				int d = -1;	
				scanf("%d", &d);getchar();
				switch(curName)
				{
					case BST :{
						BSTNode *p = InitBSTNode((BSTNode *)malloc(sizeof(BSTNode)), d);
						InsertBSTNode(&btree, p);
					}break;
					case AVL :{
						AVLNode *p = InitAVLNode((AVLNode *)malloc(sizeof(AVLNode)), d);
						InsertAVLNode(&atree, p);
					}break;
					case CBT :{
						CBTNode *p = InitCBTNode((CBTNode *)malloc(sizeof(CBTNode)), d);
						InsertCBTNode(&ctree, p);
					}break;
					default : break;
				}	
			}break;
			case 'a' : {
				FOR(i, 10)
				switch(curName)
				{
					case BST :{
						BSTNode *p = InitBSTNode((BSTNode *)malloc(sizeof(BSTNode)), tmp[i]);
						InsertBSTNode(&btree, p);
					}break;
					case AVL :{
						AVLNode *p = InitAVLNode((AVLNode *)malloc(sizeof(AVLNode)), tmp[i]);
						InsertAVLNode(&atree, p);
					}break;
					case CBT :{
						CBTNode *p = InitCBTNode((CBTNode *)malloc(sizeof(CBTNode)), tmp[i]);
						InsertCBTNode(&ctree, p);
					}break;
					default : break;
				}
			}break;
			case 'd' : {
				int d = -1;	
				scanf("%d", &d);
				switch(curName)
				{
					case BST :{
						DeleteBSTNode(&btree, d);
					}break;
					case AVL :{
						DeleteAVLNode(&atree, d);
					}break;
					case CBT :{
						DeleteCBTNode(&ctree, d);
					}break;
					default : break;
				}
			}break;
			case 'c' : {
				switch(curName)
				{
					case BST :{
						ReleaseBSTTree(&btree);
					}break;
					case AVL :{
						ReleaseAVLTree(&atree);
					}break;
					case CBT :{
						ReleaseCBTTree(&ctree);
					}break;
					default : break;
				}
			}break;
			case 'q' : {
				ReleaseBSTTree(&btree);
				ReleaseAVLTree(&atree);
				ReleaseCBTTree(&ctree);
				exit(0);
			}break;
			default : break;
		}
	}
	return 0;
}
