#include "stack.h"
#include "queue.h"
#include <stdio.h>
#include <string.h>

static inline int isSymbol(char c)
{
	return ((c == '*') || (c=='/') || (c=='+') || (c=='-'));
}

static inline int IsSymPrio(char c)
{
	return ((c=='*') || (c=='/'));
}

static inline int IsBrackets(char c) 
{

	return ( (c=='(') || (c==')') );
}

static inline int IsNumber(char c)
{
	return ((c >= 48) && (c <= 57));
}
static int GetFirstNumber(char *str, int *num)
{
	char cs[10] = {'\0'};
	int i = 0;
	for(char *p = str; 
		p[i] != '\0' && IsNumber(p[i]); 
		cs[i] = p[i], i++);
	sscanf(cs, "%d", num);
	return strlen(cs);	
}



static void SymbolAssignment(char c, Stack* sym, Queue* dst)
{
	if( !IsSymPrio(c) || (c == ')') )  // +,-,)
	{
		char d = (char)sym->first; 
		if( IsSymPrio(d) || c == ')' )  // *,/,)
		{
			while( !sym->isEmpty && (sym->first != '(') )
			{
				Entry(dst, Pop(sym));
			}
			if( sym->first == '(' )
			{
				Pop(sym);
				return;
			}
		}
	}
	Push(sym, c);
}
int InfixToPostfix(Queue *dst, const char *infix)
{
	Stack sym;
	InitStack(&sym);
	for(char *p = (char *)infix; *p != '\0'; )
	{
		if( IsNumber(*p) )
		{	
			int len, num = 0;
			len = GetFirstNumber(p, &num);
			p += len;
			Entry(dst, num);
		}
		else
		{
			SymbolAssignment(*p++, &sym, dst);
		}
	}

	while( !sym.isEmpty ) Entry(dst, Pop(&sym));
	return dst->length;
}

int CypherPostfix(Queue *q)
{
	Stack stack;
	InitStack(&stack);

	while( !q->isEmpty )
	{
		int v = (int)Out(q);
		if( !isSymbol((char)v) )
		{
			Push(&stack, v);
		}
		else
		{
			int b = (int)Pop(&stack);
			int f = (int)Pop(&stack);
			switch((char)v)
			{
				case '+': Push(&stack, f+b); break;
				case '-': Push(&stack, f-b); break;
				case '*': Push(&stack, f*b); break;
				case '/': Push(&stack, f/b); break;
				default : break;
			}
		}
	}
	return (int)Pop(&stack);
}
