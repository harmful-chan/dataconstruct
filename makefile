CC = gcc
HEADS = -I./includes
LIBS = -lcunit
TEST_TARGET =
DEFINES = 

CFLAGS = -std=c99 -D $(DEFINES) -g

test: test.c 
	$(CC) $(CFLAGS) $(LIBS) $(HEADS)  -o $@  $(TEST_TARGET) $^

