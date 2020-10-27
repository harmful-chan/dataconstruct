#include "bst.h"
#include <stdlib.h>

int main(void)
{
	BSTree tree;
	InitBST(&tree);
	BSTNode p[20];
	int tmp[20] = {2, 3, 22, 9, 7, 5, 6, 1, 70, 50,\
				   45, 4, 44, 43, 42, 45, 53, 52, 51, 25};
	for(int i = 0; i < 20; i++)
	{
		InitBSTNode(&p[i], tmp[i]);
		InsertBSTNode(&tree, &p[i]);
	}
	ShowTree(&tree);
	
	return 0;
}
