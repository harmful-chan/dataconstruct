#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "typedef.h"
#include "avl.h"

int main(void)
{		
	char *cmd_line = "# script > ";

	BSTree btree;
	AVLTree atree;
	InitBSTree(&btree);
	InitAVLTree(&atree);

	int tmp[] = {10, 20, 30, 40, 50, 5, 3, 4, 15, 13};
	int mode = 0;
	while(1)
	{
		char c= '\0';
		system("clear");
		switch(mode)
		{
			case 0: ShowTree(&btree); break;
			case 1: ShowTree((BSTree *)&atree); break;
			default : break;
		}

		// cmd line :
		printf(cmd_line); scanf("%c", &c); printf("\r\n");
		switch(c)
		{
			case 'm':{
				char *s = "";
				scanf("%s", &s);
				if( strcmp("avl", s) >= 0 ) mode = 1;
				if( strcmp("bst", s) >= 0 ) mode = 0;
			}break;
			case 'i': {
				int d = -1;	
				scanf("%d", &d);
				switch(mode)
				{
					case 0 :{
						BSTNode *p = InitBSTNode((BSTNode *)malloc(sizeof(BSTNode)), d);
						InsertBSTNode(&btree, p);
					}break;
					case 1 :{
						AVLNode *p = InitAVLNode((AVLNode *)malloc(sizeof(AVLNode)), d);
						InsertAVLNode(&atree, p);
					}break;
					default : break;
				}
			}break;
			case 'a' : {
				FOR(i, 5)
				switch(mode)
				{
					case 0 :{
						BSTNode *p = InitBSTNode((BSTNode *)malloc(sizeof(BSTNode)), tmp[i]);
						InsertBSTNode(&btree, p);
					}break;
					case 1 :{
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
					case 0 :{
						DeleteBSTNode(&btree, d);
					}break;
					case 1 :{
						DeleteAVLNode(&atree, d);
					}break;
					default : break;
				}
			}break;
			case 'q' : {
				exit(0);
			}break;
			default : break;
		}
	}
	
	
	return 0;
}
