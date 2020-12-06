#include <stdio.h>
#include "queue.h"

int main(int argc, char* argv[])
{
	Queue q;
	if( !InitQueue(&q) ) printf("init queue fail!\r\n");
	
	for(int i = 0; i < 10; i++)
	{
		Entry(&q, i);
	}
	for(int i = 0; i < 10; i++)
	{
		if( !q.isEmpty )
		{
			QueueElemType data = Out(&q);
			printf("%d%s", data, (i==9) ? "\r\n" : " ");
		}
	}
	printf("queue is empty: %d\r\n", q.isEmpty);
	

	return 0;
}


