GCC=gcc
CFLAGS= -std=c99 -g

all : main.o gapimg.o mag.o alg.o queue.o
	$(GCC) -o a.out $^ $(CFLAGS)

queue.o : queue.c
	$(GCC) -c $^ -o $@ $(CFLAGS)

main.o : main.c
	$(GCC) -c $^ -o $@ $(CFLAGS)

mag.o : mag.c
	$(GCC) -c $^ -o $@ $(CFLAGS)

alg.o : alg.c
	$(GCC) -c $^ -o $@ $(CFLAGS)


gapimg.o : gapimg.c
	$(GCC) -c $^ -o $@ $(CFLAGS)

clean : 
	rm -rf core.* a.out *.o

log :
	@echo -e '\r\n#####' \
	${shell date} \
	${shell git config --get user.name} \
	${shell git config --get user.email} '\n' \
	${shell ls | grep .c} >> changelog.md