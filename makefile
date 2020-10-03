CC = gcc
HEADS = -I./includes
LIBS = -lcunit -lncurses
TEST_TARGET =
DEFINES = 

CFLAGS = -std=c99 -D $(DEFINES) -g

test: test.c check_link.c
	$(CC) $(CFLAGS) $(LIBS) $(HEADS)  -o $@  $(TEST_TARGET) $^

