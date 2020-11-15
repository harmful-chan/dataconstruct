#ifndef _STACK_H_
#define _STACK_H_

#include "typedef.h"

typedef struct stack_node_s
{
	ElmType data;
	struct stack_node_s *next;
}StackNode;

typedef struct stack_s
{
	int isEmpty;
	ElmType first;
	struct stack_node_s *next;
}Stack;

extern Stack *InitStack(Stack *);
extern Stack *CleanStack(Stack *);
extern void Push(Stack *, ElmType);
extern ElmType Pop(Stack *);

extern ElmType First(Stack *);
#endif
