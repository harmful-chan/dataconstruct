#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "typedef.h"
int main(void)
{		
	BSTree tree;
	InitBST(&tree);
	int tmp[] = {10, 20, 30, 40, 50, 5, 3, 4, 15, 13};

	while(1)
	{
		char c= '\0';
		system("clear");
		ShowTree(&tree);
		printf("# script > ");
		scanf("%c", &c);
		printf("\r\n");

		switch(c)
		{
			case 'i': {
				int d = -1;	
				scanf("%d", &d);
				BSTNode *p = InitBSTNode((BSTNode *)malloc(sizeof(BSTNode)), d);
				InsertBSTNode(&tree, p);
			}break;
			case 'c' : {
				FOR(i, 10){
					BSTNode *p = InitBSTNode((BSTNode *)malloc(sizeof(BSTNode)), tmp[i]);
					InsertBSTNode(&tree, p);
				}
			}break;
			case 'd' : {
				int d = -1;	
				scanf("%d", &d);
				DeleteBSTNode(&tree, d);
			}break;
			case 'q' : {
				exit(0);
			}break;
			default : break;
		}
	}
	
	
	return 0;
}
