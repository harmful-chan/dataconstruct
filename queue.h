#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "typedef.h"
typedef struct queue_node_s
{
	elm_t data;
	struct queue_node_s *next, * prev;
}queue_node_t;

typedef struct queue_s
{
	int is_empty;
	struct queue_node_s *next, *prev;
}queue_t;

extern queue_t *init_queue(queue_t *);
extern queue_t *clean_queue(queue_t *);
extern void entry(queue_t *, elm_t);
extern elm_t out(queue_t *);

#endif

