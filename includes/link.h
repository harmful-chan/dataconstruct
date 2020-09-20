#ifndef _LINK_H_
#define _LINK_H_

#include "typedef.h"
	extern LinkList CreateLinkList();
        extern int DestroyLinkList(LinkList list);

        extern LNode* Get(LinkList list, int index);
        extern int Locate(LinkList list, elm_t elm);

        extern int Add(LinkList list, elm_t elm);
        extern int Delete(LinkList list, int index);
        extern int Insert(LinkList list, int index, elm_t elm);
        extern int Replace(LinkList list, int index, elm_t elm);


	extern void ToString(LinkList list);
#endif
