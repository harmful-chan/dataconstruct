#include "kmp.h"
#include <string.h>

static inline 
int equal(const char *str, const char *sub, int length)
{
	int ret = 1;
	for(int i = 0 ; 
		i<length && \
		str[i] != '\0' && \
		sub[i] != '\0' ;i++)
	{
		ret &= (str[i] == sub[i]);
	}

	return ret;
}

int kmp_next(const char *str, char *buf)
{
	int size = strlen(str);
	for(int i = size-1; i > 0; i--)
	{
		for(int j = i-1; j > 0; j--)
		{
			equal(str[])
		}
		int j = 0;
		while(str[i+j] == str[j] && i+j < size) j++;
		buf[i]=j;
	}
	return strlen(str);
}

int kmp_cmp(const char* str, const char* sub)
{
	for(int i = 0, j = 0; str[i] != '\0'; i++)
	{
		
	}
}
int simple_cmp(const char* str, const char* sub)
{
	int index = -1;
	for(const char *p = str, *q = sub; *p != '\0'; p++)
	{
		index++;
		for(int i = 0; q[i] == p[i]; i++ )
		{
			if( q[i+1] == '\0') return index;
		}
	}
	return -1;
}
