.PHONY: all clean
CC = gcc
CFLAGS = -std=c11 -pedantic -D_XOPEN_SOURCE=700 -Wall -Werror

all:
	$(CC) $(CFLAGS) textEdior.c -o main

clean:
	rm -r *.o
