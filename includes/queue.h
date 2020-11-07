#ifndef _QUEUE_H_
#define _QUEUE_H_


typedef void *qlm_t;

typedef struct queue_node_s
{
	qlm_t data;
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
extern void Entry(Queue *, qlm_t);
extern qlm_t Out(Queue *);

#endif

