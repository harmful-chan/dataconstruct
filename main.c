#include "bst.h"
#include <stdlib.h>

int main(void)
{
	BSTree tree;
	InitBST(&tree);
	BSTNode p[20];
	int tmp[20] = {1, 2, 3, 4, 50, 6, 7, 8, 59, 60, 11,\
				   63, 62, 14, 70, 16, 17, 18, 80, 20};
	for(int i = 0; i < 20; i++)
	{
		InitBSTNode(&p[i], tmp[i]);
		InsertBSTNode(&tree, &p[i]);
	}
	ShowTree(&tree);
	
	return 0;
}
