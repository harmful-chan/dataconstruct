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



void symbol_assignment(char c, stack_t* sym, queue_t* dst)
{
	static int cases = 0;
	switch(cases)
	{
		case 0 : cases = 1;
		case 1 : 
			push(sym, c); 
			cases = is_sym_prio(c) ? 2 : 1;
			cases = is_brackets(c) ? 3 : cases;
			break;
		case 2 :
			for(char s = (char)sym->first; 
				!is_sym_prio(c) && \
				!is_brackets(s) && \
				!sym->is_empty;
				s = (char)sym->first)
			{
				elm_t ret = pop(sym);
				entry(dst, ret);
			}
			push(sym, c);
			cases = 1;
			break;
		case 3 :
			for(char s = (char)sym->first; 
				(c == ')') && (s != '(');
				s = sym->first)
			{
				elm_t ret = pop(sym);
				entry(dst, ret);
			} 
			if( c == ')' ) pop(sym);
			cases = 1;
			break;
		default : break;
	}
/*
	if( is_sym_prio(c) )
	{
		for(char s = (char)sym->first; 
			!is_sym_prio(c) && \
			!is_brackets(s) && \
			!sym->is_empty;
			s = (char)sym->first)
		{
			elm_t ret = pop(sym);
			entry(dst, ret);
		}
		push(sym, c);
		
	}
	else if( is_brackets(c) )
	{

	}
*/
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


