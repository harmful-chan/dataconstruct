#include "link.h"
#include <stdio.h>
#include <stdlib.h>

int equal(node_t* s, node_t* d)
{
	return (s->data == d->data);
}

void init_link(head_t **list)
{
	head_t *p = (head_t *)malloc(sizeof(head_t));
	p->length = 0;
	p->next = NULL;
	p->prev = NULL;
	*list = p;
}

void init_node(node_t **new, elm_t data)
{
	node_t *p = (node_t *)malloc(sizeof(node_t));
	p->data = data;
	p->next = NULL;
	p->prev = NULL;
	*new = p;
}

void clean_link(head_t *list)
{
	node_t *d, *p;
	p =  list->next;
	for(; p != NULL;)
	{
		d = p->next;
		free(p);
		p = d;
	}
	free(list);

}

void locate_node(head_t *list, elm_t elm, node_t **dest)
{
	node_t *p = list->next;
	node_t d = { elm, NULL };
	for(int i = 0 ; p != NULL; p = p->next, i++ )
	{
		if( equal(p, &d) ) *dest = p;
	}
}

void get_node(head_t *list, int index, node_t **dest)
{
	node_t *p = list->next;
	for(int i = 0 ; p != NULL; p = p->next, i++ )
	{
		if( index == i ) *dest = p;
	}
}

void append_node(head_t *list, node_t *new)
{
	node_t *p = NULL;
#if defined( HEAD_MODE )
	p = (node_t *)list;
	if( p == NULL )	return;
	new->next = p->next;
	new->prev = p;
	p->next->prev = new;
	p->next = new;
#else
	if( list->length==0 ) p = (node_t *)list;
	else get_node(list,  list->length-1, &p);
	if( p == NULL )	return;
	new->prev = p;
	p->next = new;	
#endif

	list->length++;
}

void delete_node(head_t *list, int index)
{
	node_t *p = NULL;
	get_node(list, index, &p);
	if( p == NULL )	return;
	
	if( p->next == NULL ) p->prev->next = NULL;
	else
	{
		p->prev = p->next->prev;
		p->prev->next = p->next;
	}
	free(p);
	list->length--;
}

void insert_node(head_t* list, int index, node_t* new)
{
	node_t* p = NULL;
	get_node(list, index, &p);
	if( p == NULL )	return;

	new->next = p;
	new->prev = p->prev;
	new->prev->next = new;
	new->next->prev =  new;
}
void replace_node(head_t* list, int index, node_t* new)
{
	node_t* p = NULL;
	get_node(list, index, &p);
	if( p == NULL )	return;

	new->next = p->next;
	new->prev = p->prev;
	new->prev->next = new;
	if( new->next != NULL )
		new->next->prev =  new;
	free(p->next);
}
/*
void show(head_t *list)
{
	
	int index = 0;
	int length = 10;
	while(1)
	{
		system("clear");
		if(index < list->length)
		{
			//index
			for(int i = index;
				(i < index + length) && (i < list->length); 
				printf("[%2d] ", i), i++);
			printf("\r\n");
			
			//data
			node_t *p = NULL;
			get_node(list, index, p);
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

void show1(head_t* list)
{
	int u = (list->length%10 == 0) ? 0: 1;
	int row = (list->length/10) + u;
	int x=0, y=0;
	while(1)
	{
		system("clear");
		if( x >= 0 && x < 10 && y >=0 && y < row )
		{
			node_t *p = NULL;
			get_node(list, 0, p);
			for(int i=0; i < row; i++)
			{
				for(int j = 0; j < 10; j++)
				{
					if( i == y && j == x )
						printf("<%2d> ", i*10 + j);
					else
						printf("[%2d] ", i*10 + j);
				}
				printf("\r\n");
				for(int j = 0; j < 10; j++, p = p->next)
				{
					if(p!=NULL)
						printf("[%2d] ", p->data);
				}
				printf("\r\n");
			}
		}
		unsigned char ch[4] = {0};
		for(int i =0; i < 4; ch[i]=getchar(), i++);
		switch(ch[2])
		{
			case 68: x--; break;
			case 67: x++; break;
			case 66: y++; break;
			case 65: y--; break;
			default: break;
		}
	}
}*/

void show(head_t *list)
{

}
