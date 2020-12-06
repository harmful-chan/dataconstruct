GCC=gcc
CFLAGS= -std=c99 -g

all: main.o  stack.o
	$(GCC)  $^ $(CFLAGS)

main.o : main.c
	$(GCC) -o $@ -c $^ $(CFLAGS)

stack.o : stack.c
	$(GCC) -o $@ -c $^ $(CFLAGS)

stack.a : stack.o
	ar rv lib$@ $^

clean : 
	rm -rf core.* a.out *.o

log :
	@echo -e '\r\n#####' \
	${shell date} \
	${shell git config --get user.name} \
	${shell git config --get user.email} '\n' \
	${shell ls | grep .c} >> changelog.md
