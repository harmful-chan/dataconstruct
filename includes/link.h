#ifndef _LINK_H_
#define _LINK_H_

#include "typedef.h"

//native function, not check
extern void init_link(head_t **);
extern void init_node(node_t **, elm_t);
extern void clean_link(head_t *);

extern void get_node(head_t *, int, node_t **);
extern void locate_node(head_t *, elm_t, node_t **);

extern void append_node(head_t *, node_t *);
extern void delete_node(head_t *, int);
extern void insert_node(head_t *, int, node_t *);
extern void replace_node(head_t *, int, node_t *);

extern int equal(node_t* s, node_t* d);
extern void show(head_t* list);

#endif
