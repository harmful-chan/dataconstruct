#ifndef _STACK_H_
#define _STACK_H_

#include "typedef.h"
typedef struct stack_node_s
{
	elm_t data;
	struct stack_node_s *next;
}stack_node_t;

typedef struct stack_s
{
	int is_empty;
	elm_t first;
	struct stack_node_s *next;
}stack_t;

extern stack_t *init_stack(stack_t *);
extern stack_t *clean_stack(stack_t *);
extern void push(stack_t *, elm_t new);
extern elm_t pop(stack_t *);

extern elm_t first(stack_t *);
#endif
