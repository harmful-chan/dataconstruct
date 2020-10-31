#include "bst.h"
#include <stdlib.h>

int main(void)
{		
	BSTree tree;
	InitBST(&tree);
	BSTNode p[20];
	int tmp[20] = {51, 5, 2, 3, 4, 34, 33, 32, 50, 60, 59, 70, 75, 71, 8,  9, 10 ,11, 12, 13};
	for(int i = 0; i < 20; i++)
	{
		InitBSTNode(&p[i], tmp[i]);
		InsertBSTNode(&tree, &p[i]);
	}
	ShowTree(&tree);
	
	return 0;
}
