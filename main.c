#include "bst.h"
#include <stdlib.h>

int main(void)
{		
	BSTree tree;
	InitBST(&tree);
	BSTNode p[20];
	int tmp[20] = {10, 5, 4, 3, 8, 9, 10, 60,  20, 19 ,31, 32, 30, 29, 33, 31, 40, 50, 60, 70, 80, 90};
	for(int i = 0; i < 20; i++)
	{
		InitBSTNode(&p[i], tmp[i]);
		InsertBSTNode(&tree, &p[i]);
	}
	ShowTree(&tree);
	
	return 0;
}
