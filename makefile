  
CC=gcc
CFLAGS= -Wall -g

all: frequency

frequency: Trie.c 
	$(CC) $(CFLAGS) -o frequency Trie.c



.PHONY: clean 
	
clean:              #clean all .o files.
	rm -f mains *.o *.a frequency
