  
CC=gcc
CFLAGS= -Wall -g

all: trie

trie: Trie.c 
	$(CC) $(CFLAGS) -o trie Trie.c

.PHONY: clean 
	
clean:              #clean all .o files.
	rm -f mains *.o *.a trie
