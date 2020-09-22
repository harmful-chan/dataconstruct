#ifndef _DOUBLE_DEF_H_
#define _DOUBLE_DEF_H_

typedef int elm_t;

typedef struct Node
{
	elm_t data;
	struct Node* prio;
	struct Node* next;
}LNode, *LinkList;

#endif
