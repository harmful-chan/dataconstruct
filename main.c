#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "typedef.h"
#include "avl.h"

typedef enum SHOW_MODE
{
	MODE_BST = 0,
	MODE_AVL
}ShowModeType;

BSTree btree;
AVLTree atree;
void Show(ShowModeType mode)
{
	system("clear");
	char str[10] = {'\0'};
	switch(mode)
	{
		case MODE_BST: {ShowBSTree(&btree); memcpy(str, "bst", 3);} break;
		case MODE_AVL: {ShowAVLTree(&atree); memcpy(str, "avl", 3);} break;
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

	InitBSTree(&btree);
	InitAVLTree(&atree);

	int tmp[] = {10, 20, 30, 40, 50, 25, 3, 4, 15, 13};
	ShowModeType mode = MODE_BST;
	while(1)
	{
		Show(mode);
		switch(ReadKey())
		{
			case 'm':{
				char s[10] = {'\0'};
				scanf("%s", &s);
				
				if( s[0]=='a'&&s[1]=='v'&&s[2]=='l' ) mode = MODE_AVL;
				if( s[0]=='b'&&s[1]=='s'&&s[2]=='t' ) mode = MODE_BST;
				memset(&s, '\0', 10);
			}break;
			case 'i': {
				int d = -1;	
				scanf("%d", &d);getchar();
				switch(mode)
				{
					case MODE_BST :{
						BSTNode *p = InitBSTNode((BSTNode *)malloc(sizeof(BSTNode)), d);
						InsertBSTNode(&btree, p);
					}break;
					case MODE_AVL :{
						AVLNode *p = InitAVLNode((AVLNode *)malloc(sizeof(AVLNode)), d);
						InsertAVLNode(&atree, p);
					}break;
					default : break;
				}				
			}break;
			case 'a' : {
				FOR(i, 10)
				switch(mode)
				{
					case MODE_BST :{
						BSTNode *p = InitBSTNode((BSTNode *)malloc(sizeof(BSTNode)), tmp[i]);
						InsertBSTNode(&btree, p);
					}break;
					case MODE_AVL :{
						AVLNode *p = InitAVLNode((AVLNode *)malloc(sizeof(AVLNode)), tmp[i]);
						InsertAVLNode(&atree, p);
					}break;
					default : break;
				}
			}break;
			case 'd' : {
				int d = -1;	
				scanf("%d", &d);
				switch(mode)
				{
					case MODE_BST :{
						DeleteBSTNode(&btree, d);
					}break;
					case MODE_AVL :{
						DeleteAVLNode(&atree, d);
					}break;
					default : break;
				}
			}break;
			case 'q' : {
				ReleaseBSTree(&btree);
				ReleaseAVLTree(&atree);
				exit(0);
			}break;
			default : break;
		}
	}
	return 0;
}
