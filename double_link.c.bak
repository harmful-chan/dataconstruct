#include "link.h"
#include <stdlib.h>
#include <stdio.h>
LinkList CreateLinkList()
{
	LinkList list = (LinkList)malloc(sizeof(LNode));
	list->prio = NULL;
	list->next = NULL;
	list->data = -1;
	return list;
}

int DestroyLinkList(LinkList list)
{
	ASSERT(list != NULL);

	LNode *p = list;
	for(;p != NULL;)
	{
		LNode* t = p->next;
		free(p);
		p = t;
	}	
}

LNode* Get(LinkList list, int index)
{
	if(list == NULL) return NULL;
	if(index < 0) return NULL;

	LNode* p = list->next;
	for(int i = 0; p != NULL; p = p->next, i++)
	{
		if( i == index ) return p;
	}

	return NULL;
}
int Locate(LinkList list, elm_t elm)
{
	ASSERT(list != NULL);

	LNode* p = list->next;
	for(int i = 0; p != NULL; p = p->next, i++)
	{
		if( Equal(elm, p->data) >= 0 ) return i;
	}
	
	return -1;
}

int Add(LinkList list, elm_t elm)
{
	ASSERT(list != NULL);
#if defined(HEAD_MODE)
	LNode* p = (LNode*)malloc(sizeof(LNode));
	p->data = elm;
	if(list->next == NULL)
	{
		list->next = p;
		p->prio = list;
		p->next = NULL;
		return 0;
	}
	else
	{
		list->next->prio = p;
		p->next = list->next;
		p->prio = list;
		list->next = p;
		return 1;
	}
	
#else
	LNode* p = list;
	for(; p != NULL; p = p->next)
	{
		if( p->next == NULL )
		{
			p->next = (LNode *)malloc(sizeof(LNode));
			p->next->prio = p;
			p->next->next = NULL;
			p->next->data = elm;
			return 1;	
		}
	}
#endif
	
	return -1;
}

int Delete(LinkList list, int index)
{
	ASSERT(list != NULL);
	ASSERT(index >= 0);

	LNode* p = Get(list, index);
	ASSERT(p != NULL);

	p->prio->next = p->next;
	p->next->prio = p->prio;
	free(p);

	return index;
	
}
int Insert(LinkList list, int index, elm_t elm)
{	
	ASSERT(list != NULL);
	ASSERT(index >= 0);

	
	LNode* p = Get(list, index);
	ASSERT(p != NULL);
	
	LNode *n = (LNode*)malloc(sizeof(LNode));

	n->data = elm;
	p->prio->next = n;
	n->prio = p->prio;
	n->next = p;
	p->prio = n;
	
	return index;
	
}
int Replace(LinkList list, int index, elm_t elm)
{
	
	ASSERT(list != NULL);
	ASSERT(index >= 0);
	
	LNode* p = Get(list, index);
	ASSERT(p != NULL);
	p->data = elm;
	return index;
}

void ToString(LinkList list)
{
	LNode* p = list;
	for(int i = 0; p != NULL; p = p->next, i++)
	{
		printf("[%3d]:%5d\r\n", i, p->data);
	}
}
int Equal(elm_t s, elm_t d)
{
	return (s == d)? 1 : -1;
}
