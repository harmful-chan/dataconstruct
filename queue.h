#ifndef _QUEUE_H_
#define _QUEUE_H_


#define QueueElemType int
typedef struct queue_node_s
{
	QueueElemType data;
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
extern void Entry(Queue *, QueueElemType);
extern QueueElemType Out(Queue *);

#endif

