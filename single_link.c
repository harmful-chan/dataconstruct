#include "link.h"
#include <stdio.h>
#include <stdlib.h>

int equal(node_t* s, node_t* d)
{
	return (s->data == d->data);
}

head_t* create_link()
{
	head_t *p = (head_t *)malloc(sizeof(head_t));
	p->count = 0;
	p->next = NULL;
	return p;
}

node_t* create_node(elm_t data)
{
	node_t *p = (node_t *)malloc(sizeof(node_t));
	p->data = data;

	p->next = NULL;
	return p;
}

void destroy_link(head_t *list)
{
	node_t *d, *p;
	p =  list->next;
	for(; p != NULL;)
	{
		d = p->next;
		free(p);
		p = d;
	}
}


int locate_node(head_t *list, elm_t elm)
{
	node_t *p = list->next;
	node_t *d = &((node_t){ elm, NULL });
	for(int i = 0 ; p != NULL; p = p->next, i++ )
	{
		if( equal(p, d) ) return i;
	}

	return -1;
}

node_t* get_node(head_t *list, int index)
{
	node_t *p = list->next;
	for(int i = 0 ; p != NULL; p = p->next, i++ )
	{
		if( index == i ) return p;
	}

	return NULL;
}

void add_node(head_t *list, node_t *new)
{
	node_t *p = NULL;
#if defined( HEAD_MODE )
	p = list;
	if( p == NULL )	return;
	new->next = p->next;
	p->next = new;
#else
	if( list->count==0 ) p = list;
	else p = get_node(list,  list->count-1);
	if( p == NULL )	return;
	p->next = new;	
#endif

	list->count++;
}

void delete_node(head_t *list, int index)
{
	node_t *d, *p;
	p = get_node(list, index-1);
	if( p == NULL )	return;

	d = p->next;
	p->next = p->next->next;
	free(d);
	list->count--;
}

void insert_node(head_t* list, int index, node_t* new)
{
	node_t* p = get_node(list, index-1);
	if( p == NULL )	return;

	new->next = p->next->next;
	p->next = new;
}
void replace_node(head_t* list, int index, node_t* new)
{
	node_t* p = get_node(list, index-1);
	if( p == NULL )	return;

	new->next = p->next->next;
	free(p->next);
	p->next = new;
}

void show(head_t *list)
{
	
	int index = 0;
	int length = 10;
	while(1)
	{
		system("clear");
		if(index < list->count)
		{
			//index
			for(int i = index;
				(i < index + length) && (i < list->count); 
				printf("[%2d] ", i), i++);
			printf("\r\n");
			
			//data
			node_t *p = get_node(list, index);
			for(int i = 0; 
				p != NULL && i < length; 
				p=p->next, i++)
			{
				printf(" %2d  ", p->data);
			}
			printf("\r\n");
		}

		//get input direct.
		unsigned char ch[4] = {0};
		for(int i =0; i < 4; ch[i]=getchar(), i++);
		switch(ch[2])
		{
			case 68: if(index > 0) index--; break;
			case 67: index++; break;
			default: break;
		}
	}
}

