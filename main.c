#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "calculate.h"

static inline int is_symbol(char c)
{
	return ( (c=='+') || (c=='-') || (c=='*') || (c=='/') );
}
int main(int argc, char* argv[])
{
	queue_t q;
	if( !init_queue(&q) ) printf("init queue fail!\r\n");

	if( argc == 2 )
		infix_to_postfix(&q, argv[1]);
	else	
		infix_to_postfix(&q, "1+2+3");
		
	printf("queue is empty: %d\r\n", q.is_empty);
	while( !q.is_empty )
	{
		elm_t data = out(&q);
		if( is_symbol((char)data) )
			printf("%c ", data);
		else
			printf("%d ", data);
	}

	return 0;
}

int test_sq(void)
{
	stack_t s;
	if( !init_stack(&s) ) printf("init stack fail!\r\n");
	queue_t q;
	if( !init_queue(&q) ) printf("init queue fail!\r\n");
	
	for(int i = 0; i < 10; i++)
	{
		push(&s, i);
		entry(&q, i);
	}

	for(int i = 0; i < 10; i++)
	{
		if( !s.is_empty )
		{
			elm_t data = pop(&s);
			printf("%d%s", data, (i==9) ? "\r\n" : " ");
		}
	}
	printf("stack is empty: %d\r\n", s.is_empty);
	for(int i = 0; i < 10; i++)
	{
		if( !q.is_empty )
		{
			elm_t data = out(&q);
			printf("%d%s", data, (i==9) ? "\r\n" : " ");
		}
	}
	printf("queue is empty: %d\r\n", q.is_empty);
	

	return 0;
}



