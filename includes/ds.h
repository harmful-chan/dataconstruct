#ifndef _DS_H_
#define _DS_H_

#include "bst.h"
typedef struct ds_elm_t
{
	ElemType data;
	struct ds_elm_t *left;
	struct ds_elm_t *rigt;
	struct ds_elm_t *pare;
}DSElmNode;

typedef struct ds_node_t
{
    DSElmNode *node;
    unsigned char havePare, haveLeft, haveRigt;
}DSNode;

extern void *ProductTreePicture(void *);
#endif