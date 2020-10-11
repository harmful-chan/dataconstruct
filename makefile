
all:
	gcc -g -std=c99 main.c calculate.c queue.c stack.c >& error.txt 
