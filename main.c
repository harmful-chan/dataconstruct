#include "bst.h"
#include <stdlib.h>

int main(void)
{
	BSTree tree;
	InitBST(&tree);
	BSTNode p[10];
	for(int i = 0; i < 10; i++)
	{
		InitBSTNode(&p[i], i);
		InsertBSTNode(&tree, &p[i]);
	}
	
	
	return 0;
}
