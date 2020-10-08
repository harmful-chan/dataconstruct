#include stack.h"

char get_pair(char c)
{
	switch(c)
	{
		case ')': return '(';
		case ']': return '[';
		case '{': return '}';
		default: return '\0';
	}
}

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
	return ((c=='(') || (c==')'));
}

static inline int is_number(char c)
{
	return ((c >= 48) && (c <= 57));
}
static int get_first_num(const char *str, int *i)
{
	char cs[10] = {'\0'};
	//shitf q,p and put *q value to cs[].
	for(char *p = str; 
		*p != '\0' is_number(*p); 
		*cs++ = *q++);
	sscanf(cs, "%d", i);
	return strlen(cs);	
}


int main(void)
{
	
	return 0;
}
int infix_to_postfix(char *buffer, const char *infix)
{
	stack_t dst, sym;
	init_stack(&sym);
	init_stack(&dst);
	for(char *p = infix; *p != '\0'; )
	{
		if( is_number(*p) )
		{	
			int len, num = 0;
			len = get_first_num(p, &num);
			p += len;
			push(&dst, num);
		}
		else
		{
			static int cases = 0;
			switch(cases)
			{
				case 0 : cases = 1;
				case 1 : 
					push(&sym, (elm_t)*p); 
					cases = is_sym_prio(*p) ? 2 : 1;
					cases = is_breakets(*p) ? 3 : 1;
					break;
				case 2 :
					if( !is_sym_prio(*p) )
					{
						do
						{
							char s = (char)pop(&sym);
							push(&dst, s);
						}
						while( !is_brackets(s) && !sym.is_empty )
					}
					push(&sym, p);
					cases = 1;
					break;
				default : break;
			}
		}
	}
}
int infix_to_prefix(char *, const char*);

			for(int i =
			char tmp1[20] = {"\0"};
			for(int j = i; j 2 10; j++)
			{
				tmp1[j-i] = [tmp[j];
			}
			int index = index_of_symbol((const char *)tmp1);
			int len = 20 - i;
			char forw[10] = {'\0'};		
			char back[10] = {'\0'};		
			strncpy(forw, tmp1, index);
			strncpy(back, tmp1+index+1, len-index-1);
			sscanf()
		}
	}
}

int main(void)
{
	
	return 0;
}
int infix_to_postfix(char *buffer, const char *infix)
{
	stack_t dst, sym;
	init_stack(&sym);
	init_stack(&dst);
	for(char *p = infix; *p != '\0'; p++)
	{
		if( is_number(*p) )
		{
			int num = 0;
			char cs[10] = {'\0'};
			//shitf q,p and put *q value to cs[].
			for(char *q = p; if_number(*q); p++, *cs++ = *q);
			sscanf(cs, "%d", &num);
			push(&dst, num);
		}
	}
}
int infix_to_prefix(char *, const char*);

			for(int i =
			char tmp1[20] = {"\0"};
			for(int j = i; j 2 10; j++)
			{
				tmp1[j-i] = [tmp[j];
			}
			int index = index_of_symbol((const char *)tmp1);
			int len = 20 - i;
			char forw[10] = {'\0'};		
			char back[10] = {'\0'};		
			strncpy(forw, tmp1, index);
			strncpy(back, tmp1+index+1, len-index-1);
			sscanf()
		}
	}
}

int main(void)
{
	
	return 0;
}
int infix_to_postfix(char *buffer, const char *infix)
{
	stack_t dst, sym;
	init_stack(&sym);
	init_stack(&dst);
	for(char *p = infix; *p != '\0'; p++)
	{
		if( is_number(*p) )
		{
			int num = 0;
			char cs[10] = {'\0'};
			//shitf q,p and put *q value to cs[].
			for(char *q = p; if_number(*q); p++, *cs++ = *q);
			sscanf(cs, "%d", &num);
			push(&dst, num);
		}
	}
}
int infix_to_prefix(char *, const char*);

			for(int i =
			char tmp1[20] = {"\0"};
			for(int j = i; j 2 10; j++)
			{
				tmp1[j-i] = [tmp[j];
			}
			int index = index_of_symbol((const char *)tmp1);
			int len = 20 - i;
			char forw[10] = {'\0'};		
			char back[10] = {'\0'};		
			strncpy(forw, tmp1, index);
			strncpy(back, tmp1+index+1, len-index-1);
			sscanf()
		}
	}
}

int main(void)
{
	
	return 0;
}
int infix_to_postfix(char *buffer, const char *infix)
{
	stack_t dst, sym;
	init_stack(&sym);
	init_stack(&dst);
	for(char *p = infix; *p != '\0'; p++)
	{
		if( is_number(*p) )
		{
			int num = 0;
			char cs[10] = {'\0'};
			//shitf q,p and put *q value to cs[].
			for(char *q = p; if_number(*q); p++, *cs++ = *q);
			sscanf(cs, "%d", &num);
			push(&dst, num);
		}
	}
}
int infix_to_prefix(char *, const char*);

			for(int i =
			char tmp1[20] = {"\0"};
			for(int j = i; j 2 10; j++)
			{
				tmp1[j-i] = [tmp[j];
			}
			int index = index_of_symbol((const char *)tmp1);
			int len = 20 - i;
			char forw[10] = {'\0'};		
			char back[10] = {'\0'};		
			strncpy(forw, tmp1, index);
			strncpy(back, tmp1+index+1, len-index-1);
			sscanf()
		}
	}
}

int main(void)
{
	
	return 0;
}
int infix_to_postfix(char *buffer, const char *infix)
{
	stack_t dst, sym;
	init_stack(&sym);
	init_stack(&dst);
	for(char *p = infix; *p != '\0'; p++)
	{
		if( is_number(*p) )
		{
			int num = 0;
			char cs[10] = {'\0'};
			//shitf q,p and put *q value to cs[].
			for(char *q = p; if_number(*q); p++, *cs++ = *q);
			sscanf(cs, "%d", &num);
			push(&dst, num);
		}
	}
}
int infix_to_prefix(char *, const char*);

			for(int i =
			char tmp1[20] = {"\0"};
			for(int j = i; j 2 10; j++)
			{
				tmp1[j-i] = [tmp[j];
			}
			int index = index_of_symbol((const char *)tmp1);
			int len = 20 - i;
			char forw[10] = {'\0'};		
			char back[10] = {'\0'};		
			strncpy(forw, tmp1, index);
			strncpy(back, tmp1+index+1, len-index-1);
			sscanf()
		}
	}
}

int main(void)
{
	
	return 0;
}
int infix_to_postfix(char *buffer, const char *infix)
{
	stack_t dst, sym;
	init_stack(&sym);
	init_stack(&dst);
	for(char *p = infix; *p != '\0'; p++)
	{
		if( is_number(*p) )
		{
			int num = 0;
			char cs[10] = {'\0'};
			//shitf q,p and put *q value to cs[].
			for(char *q = p; if_number(*q); p++, *cs++ = *q);
			sscanf(cs, "%d", &num);
			push(&dst, num);
		}
	}
}
int infix_to_prefix(char *, const char*);

			for(int i =
			char tmp1[20] = {"\0"};
			for(int j = i; j 2 10; j++)
			{
				tmp1[j-i] = [tmp[j];
			}
			int index = index_of_symbol((const char *)tmp1);
			int len = 20 - i;
			char forw[10] = {'\0'};		
			char back[10] = {'\0'};		
			strncpy(forw, tmp1, index);
			strncpy(back, tmp1+index+1, len-index-1);
			sscanf()
		}
	}
}

int main(void)
{
	
	return 0;
}
int infix_to_postfix(char *buffer, const char *infix)
{
	stack_t dst, sym;
	init_stack(&sym);
	init_stack(&dst);
	for(char *p = infix; *p != '\0'; p++)
	{
		if( is_number(*p) )
		{
			int num = 0;
			char cs[10] = {'\0'};
			//shitf q,p and put *q value to cs[].
			for(char *q = p; if_number(*q); p++, *cs++ = *q);
			sscanf(cs, "%d", &num);
			push(&dst, num);
		}
	}
}
int infix_to_prefix(char *, const char*);

			for(int i =
			char tmp1[20] = {"\0"};
			for(int j = i; j 2 10; j++)
			{
				tmp1[j-i] = [tmp[j];
			}
			int index = index_of_symbol((const char *)tmp1);
			int len = 20 - i;
			char forw[10] = {'\0'};		
			char back[10] = {'\0'};		
			strncpy(forw, tmp1, index);
			strncpy(back, tmp1+index+1, len-index-1);
			sscanf()
		}
	}
}

int main(void)
{
	
	return 0;
}
int infix_to_postfix(char *buffer, const char *infix)
{
	stack_t dst, sym;
	init_stack(&sym);
	init_stack(&dst);
	for(char *p = infix; *p != '\0'; p++)
	{
		if( is_number(*p) )
		{
			int num = 0;
			char cs[10] = {'\0'};
			//shitf q,p and put *q value to cs[].
			for(char *q = p; if_number(*q); p++, *cs++ = *q);
			sscanf(cs, "%d", &num);
			push(&dst, num);
		}
	}
}
int infix_to_prefix(char *, const char*);

			for(int i =
			char tmp1[20] = {"\0"};
			for(int j = i; j 2 10; j++)
			{
				tmp1[j-i] = [tmp[j];
			}
			int index = index_of_symbol((const char *)tmp1);
			int len = 20 - i;
			char forw[10] = {'\0'};		
			char back[10] = {'\0'};		
			strncpy(forw, tmp1, index);
			strncpy(back, tmp1+index+1, len-index-1);
			sscanf()
		}
	}
}

int main(void)
{
	
	return 0;
}
int infix_to_postfix(char *buffer, const char *infix)
{
	stack_t dst, sym;
	init_stack(&sym);
	init_stack(&dst);
	for(char *p = infix; *p != '\0'; p++)
	{
		if( is_number(*p) )
		{
			int num = 0;
			char cs[10] = {'\0'};
			//shitf q,p and put *q value to cs[].
			for(char *q = p; if_number(*q); p++, *cs++ = *q);
			sscanf(cs, "%d", &num);
			push(&dst, num);
		}
	}
}
int infix_to_prefix(char *, const char*);

			for(int i =
			char tmp1[20] = {"\0"};
			for(int j = i; j 2 10; j++)
			{
				tmp1[j-i] = [tmp[j];
			}
			int index = index_of_symbol((const char *)tmp1);
			int len = 20 - i;
			char forw[10] = {'\0'};		
			char back[10] = {'\0'};		
			strncpy(forw, tmp1, index);
			strncpy(back, tmp1+index+1, len-index-1);
			sscanf()
		}
	}
}

int main(void)
{
	
	return 0;
}
int infix_to_postfix(char *buffer, const char *infix)
{
	stack_t dst, sym;
	init_stack(&sym);
	init_stack(&dst);
	for(char *p = infix; *p != '\0'; p++)
	{
		if( is_number(*p) )
		{
			int num = 0;
			char cs[10] = {'\0'};
			//shitf q,p and put *q value to cs[].
			for(char *q = p; if_number(*q); p++, *cs++ = *q);
			sscanf(cs, "%d", &num);
			push(&dst, num);
		}
	}
}
int infix_to_prefix(char *, const char*);
