#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "calculate.h"

void stack_run();
void queue_run();
void calculate_run(int argc, char* argv[]);


int main(int argc, char* argv[])
{
	stack_run();
	queue_run();
	calculate_run(argc, argv);
}

static inline int isSymbol(char c)
{
	return ( (c=='+') || (c=='-') || (c=='*') || (c=='/') \
			|| (c=='(') || (c==')'));
}
void calculate_run(int argc, char* argv[])
{
	Queue q;
	if( !InitQueue(&q) ) printf("init queue fail!\r\n");

	char *exp = "1+2+3";
	printf("input expression :%s\r\n", (argc==2)?argv[1]:exp);
	if( argc == 2 )
		InfixToPostfix(&q, argv[1]);
	else	
		InfixToPostfix(&q, "1+2+3");
		
	int ret = CypherPostfix(&q);
	printf("result : %d\r\n", ret);
	
	printf("queue is empty: %d\r\n", q.isEmpty);
	while( !q.isEmpty )
	{
		QueueElemType data = Out(&q);
		if( isSymbol((char)data) )
			printf("%c ", data);
		else
			printf("%d ", data);
	}printf("\r\n");

}

void stack_run(void)
{
	Stack s;
	if( !InitStack(&s) ) printf("init stack fail!\r\n");
	for(int i = 0; i < 10; i++)
	{
		Push(&s, i);
	}

	for(int i = 0; i < 10; i++)
	{
		if( !s.isEmpty )
		{
			StackElemType data = Pop(&s);
			printf("%d%s", data, (i==9) ? "\r\n" : " ");
		}
	}
}


void queue_run(void)
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
}

