#include <stdio.h>
#include "stack.h"

int main(int argc, char* argv[])
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
	printf("stack is empty: %d\r\n", s.isEmpty);

	return 0;

}

int test_sq(void)
{
}



