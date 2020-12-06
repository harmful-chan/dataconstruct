GCC=gcc
CFLAGS= -std=c99 -g

all: main.o queue.o 
	$(GCC)  $^ $(CFLAGS)

main.o : main.c
	$(GCC) -o $@ -c $^ $(CFLAGS)

queue.o : queue.c
	$(GCC) -o $@ -c $^ $(CFLAGS)

clean : 
	rm -rf core.* a.out *.o

queue.a : queue.o
	ar rv lib$@ $^

log :
	@echo -e '\r\n#####' \
	${shell date} \
	${shell git config --get user.name} \
	${shell git config --get user.email} '\n' \
	${shell ls | grep .c} >> changelog.md