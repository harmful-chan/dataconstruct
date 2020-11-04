

all:
	gcc queue.c ds.c bst.c main.c -std=c99 -g -m32c

clean:
	rm -rf core.* a.out