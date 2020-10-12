#include "stack.h"
#include "queue.h"
#include <stdio.h>
#include <string.h>

static inline int is_symbol(char c)
{
	return ((c == '*') || (c=='/') || (c=='+') || (c=='-'));
}

static inline int is_sym_prio(char c)
{
	return ((c=='*') || (c=='/'));
}

static inline int is_brackets(char c) 
{

	return ( (c=='(') || (c==')') );
}

static inline int is_number(char c)
{
	return ((c >= 48) && (c <= 57));
}
static int get_first_num(char *str, int *num)
{
	char cs[10] = {'\0'};
	int i = 0;
	for(char *p = str; 
		p[i] != '\0' && is_number(p[i]); 
		cs[i] = p[i], i++);
	sscanf(cs, "%d", num);
	return strlen(cs);	
}



static void symbol_assignment(char c, stack_t* sym, queue_t* dst)
{
	if( !is_sym_prio(c) || (c == ')') )  // +,-,)
	{
		char d = (char)sym->first; 
		if( is_sym_prio(d) || c == ')' )  // *,/,)
		{
			while( !sym->is_empty && (sym->first != '(') )
			{
				entry(dst, pop(sym));
			}
			if( sym->first == '(' )
			{
				pop(sym);
				return;
			}
		}
	}
	push(sym, c);
}
int infix_to_postfix(queue_t *dst, const char *infix)
{
	stack_t sym;
	init_stack(&sym);
	for(char *p = (char *)infix; *p != '\0'; )
	{
		if( is_number(*p) )
		{	
			int len, num = 0;
			len = get_first_num(p, &num);
			p += len;
			entry(dst, num);
		}
		else
		{
			symbol_assignment(*p++, &sym, dst);
		}
	}

	while( !sym.is_empty ) entry(dst, pop(&sym));
	return dst->length;
}

int cypher_postfix(queue_t *q)
{
	stack_t stack;
	init_stack(&stack);

	while( !q->is_empty )
	{
		int v = (int)out(q);
		if( !is_symbol((char)v) )
		{
			push(&stack, v);
		}
		else
		{
			int b = (int)pop(&stack);
			int f = (int)pop(&stack);
			switch((char)v)
			{
				case '+': push(&stack, f+b); break;
				case '-': push(&stack, f-b); break;
				case '*': push(&stack, f*b); break;
				case '/': push(&stack, f/b); break;
				default : break;
			}
		}
	}
	return (int)pop(&stack);
}
