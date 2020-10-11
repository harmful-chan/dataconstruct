#include "queue.h"
#include <stdlib.h>

queue_t *init_queue(queue_t *queue)
{
	queue->is_empty = 1;
	queue->length = 0;
	queue->next = (queue_node_t *)queue;
	queue->prev = (queue_node_t *)queue;
	return queue;
}

queue_t *clean_queue(queue_t *queue)
{
	if( queue->is_empty ) return queue;
	for( queue_node_t *n,*p = queue->next; \
		(queue_t *)p != queue; p=n)
	{
		n = p->next;
		free(p);
	}
	queue->length = 0;
	queue->is_empty = 1;
	return queue;
}

void entry(queue_t *queue, elm_t new)
{
	queue->is_empty = 0;
	queue->length++;
	queue_node_t *p = (queue_node_t *)malloc(sizeof(queue_node_t));
	p->data = new;

	if( queue->next == (queue_node_t *)queue)
	{
		p->prev = (queue_node_t *)queue;
		p->next = (queue_node_t *)queue;
		queue->next = p;
		queue->prev = p;
	}else
	{
		p->next = queue->next;
		p->prev = (queue_node_t *)queue;
		queue->next->prev = p;
		queue->next = p;
	}
}
elm_t out(queue_t *queue)
{
	queue_node_t *p = queue->prev;
	if( p->prev == (queue_node_t *)queue )
	{
		queue->prev = (queue_node_t *)queue;
		queue->next = (queue_node_t *)queue;
		queue->is_empty = 1;
		queue->length = 0;
	}
	else
	{ 
		p->prev->next = (queue_node_t *)queue;
		queue->prev = p->prev;
		queue->length--;
	}
	elm_t data = p->data;
	free(p);
	return data;
}

