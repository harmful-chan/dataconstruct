#ifndef _DOUBLE_DEF_H_
#define _DOUBLE_DEF_H_

typedef int elm_t;

typedef struct node_s
{
	elm_t data;
	struct node_s *next, *prev;
}node_t;

typedef struct head_s
{
	int length;
	struct node_s *next, *prev;
}head_t;


#endif
