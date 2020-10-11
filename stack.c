#include "stack.h"
#include <stdlib.h>

stack_t *init_stack(stack_t *stack)
{
	stack->is_empty = 1;
	stack->next = NULL;
	stack->first = 0;
	return stack;
}

stack_t *clean_stack(stack_t *stack)
{
	if( stack->is_empty ) return stack;
	for( stack_node_t *n,*p = stack->next; p != NULL; p=n)
	{
		n = p->next;
		free(p);
	}
	return stack;
}

void push(stack_t *stack, elm_t new)
{
	stack->is_empty = 0;
	stack_node_t *p = (stack_node_t *)malloc(sizeof(stack_node_t));
	p->data = new;

	p->next = stack->next;
	stack->next = p;
	stack->first = new;
}
elm_t pop(stack_t *stack)
{
	stack_node_t *p = stack->next;
	if( p != NULL )
	{ 
		stack->next = p->next;
		if( stack->next == NULL )
		{
			stack->is_empty = 1;
			stack->first = 0;
		}else
		{
			stack->first = stack->next->data;
		}
		elm_t data = p->data;
		free(p);
		return data;
	}
	return 0;
}

