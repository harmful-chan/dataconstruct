#ifndef _DS_H_
#define _DS_H_

#include "bst.h"

typedef struct dsn_t
{
    BSTNode *node;
    unsigned char havePare, haveLeft, haveRigt;
}DSNode;

extern void *ProductTreePicture(BSTNode *head);
#endif