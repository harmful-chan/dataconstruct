#ifndef _CHECK_LINK_H_
#define _CHECK_LINK_H_

#include "typedef.h"

#define ERROR_MSG_SIZE 100

typedef enum ret_no_e
{
	SUCCESS = 0,
	ERROR,
	ERROR_PTR_NOT_NULL,
	ERROR_PTR_NULL,
	ERROR_OVERFLOW,
}ret_no_t;

typedef struct ret_s
{
	ret_no_t no;
	char msg[ERROR_MSG_SIZE];
}ret_t;

typedef struct object_s
{
	ret_t   (*init_link)(head_t **);
	ret_t	(*init_node)(node_t **, elm_t);
	ret_t	(*clean_link)(head_t *);
	ret_t	(*get_node)(head_t *, int, node_t **);
	ret_t	(*locate_node)(head_t *, elm_t, node_t **);
	ret_t	(*append_node)(head_t* , node_t *);
	ret_t	(*delete_node)(head_t *, int); 
	ret_t	(*insert_node)(head_t *, int, node_t *);
	ret_t	(*replace_node)(head_t *, int, node_t *);
}object_t;

extern object_t ob;
extern char *error_msg;
extern ret_t	check_init_link(head_t **);
extern ret_t	check_init_node(node_t **, elm_t);
extern ret_t 	check_clean_link(head_t *);
extern ret_t	check_get_node(head_t *, int, node_t **);
extern ret_t 	check_locate_node(head_t *, elm_t, node_t **);
extern ret_t 	check_append_node(head_t *, node_t *);
extern ret_t 	check_delete_node(head_t *, int);
extern ret_t 	check_insert_node(head_t *, int, node_t *);
extern ret_t 	check_replace_node(head_t *, int, node_t *);

#define ASSERT_PTR_NULL(p) \
{\
	ret_t ret = assert_ptr_null((p), "ptr isn't null, ",\
		__FILE__, __func__, __LINE__);\
	if( SUCCESS != ret.no ) return ret; \
}

#define ASSERT_PTR_NOT_NULL(p) \
{\
	ret_t ret = assert_ptr_not_null((p), "ptr is null, ", \
		__FILE__, __func__, __LINE__);\
	if( SUCCESS != ret.no ) return ret; \
}
#endif
