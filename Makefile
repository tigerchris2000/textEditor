.PHONY: all clean $(MAKES)
CC = gcc
CFLAGS = -std=c11 -pedantic -D_XOPEN_SOURCE=700 -Wall -Werror 
MAKES = files
FILES := textEditor.o  

include files/Makefile

all: textEditor 

makeing: $(MAKES)
	@echo test
	$(MAKE) -C $(MAKES)

textEditor: $(FILES)
	@echo $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o textEditor

textEditor.o: textEditor.c files/file.h
	$(CC) $(CFLAGS) textEditor.c -c textEditor.o

clean:
	@echo "clean"
	@rm -r *.o
	@rm textEditor
