#include "queue.h"
#include <stdlib.h>

Queue *InitQueue(Queue *queue)
{
	queue->isEmpty = 1;
	queue->length = 0;
	queue->next = (QueueNode *)queue;
	queue->prev = (QueueNode *)queue;
	return queue;
}

Queue *CleanQueue(Queue *queue)
{
	if( queue->isEmpty ) return queue;
	for( QueueNode *n,*p = queue->next; \
		(Queue *)p != queue; p=n)
	{
		n = p->next;
		free(p);
	}
	queue->length = 0;
	queue->isEmpty = 1;
	return queue;
}

void Entry(Queue *queue, ElmType new)
{
	queue->isEmpty = 0;
	queue->length++;
	QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
	p->data = new;

	if( queue->next == (QueueNode *)queue)
	{
		p->prev = (QueueNode *)queue;
		p->next = (QueueNode *)queue;
		queue->next = p;
		queue->prev = p;
	}else
	{
		p->next = queue->next;
		p->prev = (QueueNode *)queue;
		queue->next->prev = p;
		queue->next = p;
	}
}
ElmType Out(Queue *queue)
{
	QueueNode *p = queue->prev;
	if( p->prev == (QueueNode *)queue )
	{
		queue->prev = (QueueNode *)queue;
		queue->next = (QueueNode *)queue;
		queue->isEmpty = 1;
		queue->length = 0;
	}
	else
	{ 
		p->prev->next = (QueueNode *)queue;
		queue->prev = p->prev;
		queue->length--;
	}
	ElmType data = p->data;
	free(p);
	return data;
}

