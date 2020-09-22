#include "link.h"
#include <stdio.h>
#include <stdlib.h>

int Equal(elm_t s, elm_t d)
{
	return (s == d) ? 1 : -1;
}

LinkList CreateLinkList()
{
	LinkList l = (LinkList)malloc(sizeof(LNode));
	l->data = -1;
	l->next = NULL; 
	return l;
}

int DestroyLinkList(LinkList list)
{
	ASSERT(list != NULL);
	
	//if next element exist, 'n' keep element 'next'
	//,and free current element.
	LNode* p = list->next;
	for(LNode* t = NULL; p != NULL; free(p), p = t)
	{
		t = p->next;
	}
	free(list);
	return 0;
}


int Locate(LinkList list, elm_t elm)
{
	ASSERT(list != NULL);

	LNode* p = list->next;
	for(int i = 0 ; p != NULL; p = p->next, i++ )
	{
		if( Equal(p->data, elm) >= 0) return i;
	}

	return -1;
}

LNode* Get(LinkList list, int index)
{
	if( index < 0 ) return NULL;

	LNode* p = list->next;
	for(int i = 0 ; p != NULL; p = p->next, i++ )
	{
		if( index == i ) return p;
	}

	return NULL;
}

int Add(LinkList list, elm_t elm)
{

	ASSERT(list != NULL);
	LNode* p = list;
#if defined(HEAD_MODE)
	if(p->next != NULL)
	{
		LNode* t = p->next;
		p->next = (LNode*)malloc(sizeof(LNode));
		p->next->data = elm;
		p->next->next = t;
	}else
	{
		p->next = (LNode*)malloc(sizeof(LNode));
		p->next->data = elm;
		p->next->next = NULL;
	}
#else
	for( ; p->next != NULL ; p = p->next );
	p->next = (LNode*)malloc(sizeof(LNode));
	p->next->data = elm;
	p->next->next = NULL;
#endif
	return 0;
}

int Delete(LinkList list, int index)
{
	ASSERT(list != NULL && index >= 0);

	LNode* p = list;
	for(int i = 0; p->next != NULL; p = p->next, i++)
	{
		if( index == i )
		{
			LNode* elm = p->next;
			p->next = p->next->next;
			free(elm);
			return 1;
		}
	}

	return -1;
}

void ToString(LinkList list)
{
	int i = 0;
	LNode* p = list->next;
	for(i = 0; p != NULL; p = p->next, i++)
	{
		printf("[%2d]:%4d\r\n", i, p->data);
	}
	printf("size of %d\r\n", i);
}

int Insert(LinkList list, int index, elm_t elm)
{
	LNode* p = list;
	for(int i = 0; p->next != NULL; p = p->next, i++)
	{
		if( index == i )
		{
			LNode* e = (LNode*)malloc(sizeof(LNode));
			e->data = elm;
			e->next = p->next;
			p->next = e;
			return 1;
		}
	}

	return -1;
}
int Replace(LinkList list, int index, elm_t elm)
{

	LNode* p = list;
	for(int i = 0; p->next != NULL; p = p->next, i++)
	{
		if( index == i )
		{
			p->next->data = elm;
			return 1;
		}
	}
	return -1;
}
