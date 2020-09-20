#ifndef _SINGLE_DEF_H_
#define _SINGLE_DEF_H_

//#define HEAD_MODE    //default not define this flag, is tail add.

typedef int elm_t;
typedef struct Node
{
	elm_t data;
	struct Node* next;
	
}LNode, *LinkList;


#endif
