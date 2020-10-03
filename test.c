#include "check_link.h"
#include <stdio.h>

int main(void)
{
	ret_t ret;
	head_t* list = NULL;
	ret = ob.init_link(&list);
	if( ret.no != SUCCESS ) { printf(ret.msg); return -1; }	
	for(int i = 0; i < 10; i++)
	{
		node_t *p = NULL, *d = NULL;
		ret_t ret = ob.init_node(&p, i);
		if( ret.no != SUCCESS ) { printf(ret.msg); return -1; }	
		ret = ob.append_node(list, p);
		if( ret.no != SUCCESS ) { printf(ret.msg); return -1; }	
		
	}

	for(int i = 0; i < 10; i++)
	{	
		node_t *p = NULL;
		ret_t ret = ob.get_node(list, i, &p);
		if( ret.no != SUCCESS ) { printf(ret.msg); return -1; }	
		printf("%d ", p->data);
	}
	return 0;
}
