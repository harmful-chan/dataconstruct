
all:
	gcc -g -std=c99 main.c kmp.h kmp.c >& error.txt 
