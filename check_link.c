#include "link.h"

#include <string.h>
#include <stdio.h>
#include "check_link.h"


object_t ob = {
	.init_link = check_init_link,
	.init_node = check_init_node,
	.clean_link = check_clean_link,
	.get_node = check_get_node,
	.locate_node = check_locate_node,
	.append_node = check_append_node,
	.delete_node = check_delete_node,
	.insert_node = check_insert_node,
	.replace_node = check_replace_node,
};

static inline ret_t 
assert(int b, ret_no_t no, const char *msg,
	const char *file, const char *func, int line) 
{
	ret_t ret = { SUCCESS, "" };
	if( !(b & 0x1) )
	{
		char m[ERROR_MSG_SIZE] = {'\0'};
		strcat(m, msg);
		sprintf(m+strlen(m), "%s, %s, %d.\r\n",file, func, line);
		strncpy(ret.msg, m, ERROR_MSG_SIZE);
		ret.no = no;
	}
	return ret;
}

static inline ret_t 
assert_ptr_not_null(void *p, const char* msg,
	const char *file, const char *func, int line) 
{
	return assert((p == NULL), ERROR_PTR_NULL, msg, 
		file, func, line);
}
static inline ret_t 
assert_ptr_null(void *p, const char* msg ,
	const char *file, const char *func, int line) 
{ 
	return assert((p != NULL), ERROR_PTR_NOT_NULL, msg, 
		file, func, line);
}


ret_t  check_init_link(head_t **list)
{
	ASSERT_PTR_NULL(list);
	init_link(list);
	return (ret_t){ SUCCESS, ""};
}

ret_t check_init_node(node_t **new, elm_t data)
{
	ASSERT_PTR_NULL(new);
	init_node(new, data);
	ASSERT_PTR_NOT_NULL(new);
	return (ret_t){ SUCCESS, ""};
}
ret_t check_clean_link(head_t *list)
{

}

ret_t check_get_node(head_t *list, int index, node_t **dest)
{
	ASSERT_PTR_NOT_NULL(list);
	get_node(list, index, dest);
	ASSERT_PTR_NOT_NULL(dest);
	
}
ret_t check_locate_node(head_t *list, elm_t data, node_t **dest)
{

}
ret_t check_append_node(head_t *list, node_t *new)
{
	ASSERT_PTR_NOT_NULL(list);
	ASSERT_PTR_NOT_NULL(new);
	append_node(list, new);
	return (ret_t){ SUCCESS, ""};
}
ret_t check_delete_node(head_t *list, int index)
{

}

ret_t check_insert_node(head_t *list, int index, node_t *new)
{

}
ret_t check_replace_node(head_t *list, int index, node_t *new)
{

}



