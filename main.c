#include <stdio.h>
#include "stack.h"
#include "queue.h"
int main(void)
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
