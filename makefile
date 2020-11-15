GCC=gcc
FLAGS= -g -std=c99 

all: main.o calculate.o queue.o stack.o
	$(GCC)  $^ $(FLAGS)

main.o : main.c
	$(GCC) -o $@ -c $^ $(FLAGS)

calculate.o : calculate.c
	$(GCC) -o $@ -c $^ $(FLAGS)

queue.o : queue.c
	$(GCC) -o $@ -c $^ $(FLAGS)

stack.o : stack.c
	$(GCC) -o $@ -c $^ $(FLAGS)

clean :
	rm -rf a.out *.o core.*