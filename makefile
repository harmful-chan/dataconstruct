GCC=gcc
FLAGS= -std=c99 -g -m32 -I ./includes

all: ds.o main.o avl.o bst.o  
	$(GCC) -o a.out $(FLAGS) $^

ds.o : ds.c 
	$(GCC) -c $^ -o $@  $(FLAGS)

bst.o : bst.c 
	$(GCC) -c $^ -o $@  $(FLAGS)

avl.o : avl.c  
	$(GCC) -c $^ -o $@  $(FLAGS)

main.o : main.c  
	$(GCC) -c $^ -o $@  $(FLAGS)


clean:
	rm -rf core.* a.out *.o