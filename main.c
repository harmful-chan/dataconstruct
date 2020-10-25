#include "kmp.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	const char *str, *sub;
	if(argc == 3)
	{
		str = argv[1];
		sub = argv[2];
	}
	else
	{
		str = "qweasdzxc";
		sub = "asd";
	}
	int size = strlen(str);
	char *buf = (char *)malloc(size);
	memset(buf, '\0', size);
	kmp_next(str, buf);
	for(int i = 0; i < size; i++)
		printf("%d\r\n", buf[i]);
	//int i = kmp_cmp(str, sub);
	//printf("%s %s %d\r\n", str, sub, i);
	return 0;
}
