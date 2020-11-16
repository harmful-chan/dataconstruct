
all :
	gcc main.c mag.c -std=c99 -g

clean : 
	rm -rf core.* a.out