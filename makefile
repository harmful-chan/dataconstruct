GCC=gcc
CFLAGS= -std=c99 -g 
LIBS= libqueue.a libstack.a


all :  calculate.o main.o
	$(GCC) $^  $(LIBS) -o a.out $(CFLAGS)

main.o : main.c
	$(GCC) -c $^ -o $@ $(CFLAGS)

calculate.o : calculate.c
	$(GCC) -c $^ -o $@ $(CFLAGS)




clean : 
	rm -rf core.* a.out *.o

log :
	@echo -e '\r\n#####' \
	${shell date} \
	${shell git config --get user.name} \
	${shell git config --get user.email} '\n' \
	${shell ls | grep .c} >> changelog.md
