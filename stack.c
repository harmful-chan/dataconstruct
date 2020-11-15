#include "stack.h"
#include <stdlib.h>

Stack *InitStack(Stack *stack)
{
	stack->isEmpty = 1;
	stack->next = NULL;
	stack->first = 0;
	return stack;
}

Stack *CleanStack(Stack *stack)
{
	if( stack->isEmpty ) return stack;
	for( StackNode *n,*p = stack->next; p != NULL; p=n)
	{
		n = p->next;
		free(p);
	}
	return stack;
}

void Push(Stack *stack, ElmType new)
{
	stack->isEmpty = 0;
	StackNode *p = (StackNode *)malloc(sizeof(StackNode));
	p->data = new;

	p->next = stack->next;
	stack->next = p;
	stack->first = new;
}
ElmType Pop(Stack *stack)
{
	StackNode *p = stack->next;
	if( p != NULL )
	{ 
		stack->next = p->next;
		if( stack->next == NULL )
		{
			stack->isEmpty = 1;
			stack->first = 0;
		}else
		{
			stack->first = stack->next->data;
		}
		ElmType data = p->data;
		free(p);
		return data;
	}
	return 0;
}

