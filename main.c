#include "bst.h"
#include <stdlib.h>

int main(void)
{
	BSTree tree;
	InitBST(&tree);
	BSTNode p[10];
	int tmp[10] = {2, 3, 22, 9, 7, 5, 6, 1, 70, 50};
	for(int i = 0; i < 10; i++)
	{
		InitBSTNode(&p[i], tmp[i]);
		InsertBSTNode(&tree, &p[i]);
	}
	Show(&tree);
	
	return 0;
}
