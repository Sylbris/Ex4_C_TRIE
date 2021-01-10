  
CC=gcc
CFLAGS= -Wall -g

all: trie

trie: trie.c 
	$(CC) $(CFLAGS) -o trie trie.c

.PHONY: clean 
	
clean:              #clean all .o files.
	rm -f mains *.o *.a trie