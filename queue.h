#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "typedef.h"
typedef struct queue_node_s
{
	ElmType data;
	struct queue_node_s *next, * prev;
}QueueNode;

typedef struct queue_s
{
	int isEmpty;
	int length;
	struct queue_node_s *next, *prev;
}Queue;

extern Queue *InitQueue(Queue *);
extern Queue *CleanQueue(Queue *);
extern void Entry(Queue *, ElmType);
extern ElmType Out(Queue *);

#endif

