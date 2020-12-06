#ifndef _STACK_H_
#define _STACK_H_

typedef int StackElemType;

typedef struct stack_node_s
{
	StackElemType data;
	struct stack_node_s *next;
}StackNode;

typedef struct stack_s
{
	int isEmpty;
	StackElemType first;
	struct stack_node_s *next;
}Stack;

extern Stack *InitStack(Stack *);
extern Stack *CleanStack(Stack *);
extern void Push(Stack *, StackElemType);
extern StackElemType Pop(Stack *);

extern StackElemType First(Stack *);
#endif
