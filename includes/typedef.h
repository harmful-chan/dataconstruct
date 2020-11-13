#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#define FOR(i, num) for(int i = 0; i < num; i++)

#define COM_NODE_INFO(type) \
    ElemType data; \
	type *left; \
	type *rigt;  \



#define COM_HEAD_INFO(type) \
    type *head; \
    TreeName name; \

typedef int ElemType;

typedef enum tree_name_t
{
    BST = 0,
    AVL,
    CBT
}TreeName;

#endif