#include "tail_link.h"
#include "typedef.h"
#include <stdio.h>
#include <stdlib.h>
#define ASSERT(i) if( !(i) ) return -1;

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
	for(LNode*  n = NULL; p != NULL; free(p), p = n)
	{
		n = p->next;
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
	for( ; p->next != NULL ; p = p->next );
	p->next = (LNode*)malloc(sizeof(LNode));
	p->next->data = elm;
	p->next->next = NULL;
	return 0;
}

int Delete(LinkList list, int index)
{
	ASSERT(list != NULL && index >= 0);

	LNode* p = list->next;
	for(int i = 0; p != NULL; p = p->next, i++)
	{
		if( (index == (i+1)) && (p->next != NULL) )
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
	LNode* p = list->next;
	for(int i = 0; p != NULL; p = p->next, i++)
	{
		if( (index == (i+1)) && (p->next != NULL) )
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

	LNode* p = list->next;
	for(int i = 0; p != NULL; p = p->next, i++)
	{
		if( (index == (i+1)) && (p->next != NULL) )
		{
			p->next->data = elm;
		}
	}
	return -1;
}
void main(void)
{
	LinkList list = CreateLinkList();
	printf("add elements\r\n");
	Add(list, 1);
	Add(list, 2);
	Add(list, 3);
	Add(list, 4);
	Add(list, 5);
	Add(list, 6);
	ToString(list);

	printf("data 6 index is [%2d]\r\n", Locate(list, 6));
	printf("[ 6] data is %2d\r\n", Get(list, Locate(list, 6))->data);
	printf("delete index 3 element.\r\n");
	Delete(list, 3);
	ToString(list);	

	printf("insert 99 in the index 4\r\n");
	Insert(list, 4, 99);
	ToString(list);

	printf("replace index of 2 data to 71\r\n");
	Replace(list, 2, 71);
	ToString(list);
	
	DestroyLinkList(list);
}
