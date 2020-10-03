#ifndef _SINGLE_DEF_H_
#define _SINGLE_DEF_H_


typedef int elm_t;
typedef struct node_s
{
	elm_t data;
	struct node_s* next;	
}node_t;

typedef struct head_s
{
	int count;
	struct node_s* next;
}head_t;




#endif
