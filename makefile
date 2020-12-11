GCC=gcc
OBJDIR= ./object
CFLAGS= -I$(OBJDIR) -std=c99 -g 
LIBS= -L$(OBJDIR) -lstack -lqueue
OBJS= $(OBJDIR)/calculate.o $(OBJDIR)/main.o 

all : clean libstack.a libqueue.a $(OBJS)   
	$(GCC) $(OBJS) $(LIBS) $(CFLAGS)

$(OBJDIR)/main.o : main.c
	$(GCC) -c $^ -o $@ $(CFLAGS) 

$(OBJDIR)/calculate.o : calculate.c
	$(GCC) -c $^ -o $@ $(CFLAGS) 

libstack.a :
	@echo download libstack.a ...
	@gh release download stack-v0.0.2 -p 'libstack.a' -p 'stack.h' -D $(OBJDIR) 

libqueue.a :
	@echo download libqueue.a ...
	@gh release download queue-v0.0.2 -p 'libqueue.a' -p 'queue.h' -D $(OBJDIR)

.PHONY: clean
clean : 
	@rm -rf $(OBJDIR) a.out

log :
	@echo -e '\r\n#####' \
	${shell date} \
	${shell git config --get user.name} \
	${shell git config --get user.email} '\n' \
	${shell ls | grep .c} >> changelog.md
