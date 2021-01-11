#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_LETTERS ((int)26)

typedef enum
{
    FALSE = 0,
    TRUE = 1
} boolean;

typedef struct node
{
    char letter;                        //Incoming letter
    long unsigned int count;            //num_of_words for node
    struct node *children[NUM_LETTERS]; //an array of pointers to all of its children
    boolean isWord;
} node, *node_pointer;

//Constructor
node_pointer node_constructor(void)
{
    node_pointer np = NULL;
    np = (node_pointer)malloc(sizeof(node)); //give memory to pointer
    if (np)
    {
        np->letter = '\0';
        np->count = 0;
        np->isWord = FALSE;
        memset(np->children, 0, sizeof(np->children)); //give memory to children
    }
    return np;
}

void insert_word(node_pointer np, char *str)
{
    int index;
    node_pointer current_node = np;

    for (int i = 0; i < strlen(str); i++)
    {
        index = (int)str[i] - (int)'a';
        if (!current_node->children[index])
        { //if current node is null , create new child
            current_node->children[index] = node_constructor();
            current_node->letter = str[i];
        }
        current_node = current_node->children[index];
    }

    // mark last node as leaf
    current_node->isWord = TRUE;
    current_node->count += 1;
}

void print_lexicographic(node_pointer np, char str[], int level)
{
    if (np->isWord == TRUE)
    {
        str[level] = '\0';
        printf("%s %ld\n", str, np->count);
    }
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (np->children[i])
        {
            str[level] = i + 'a';
            print_lexicographic(np->children[i], str, level + 1);
        }
    }
}

void foo(char * arr, size_t size) {
    for (int k = 0; k < size; k++) 
        arr[k] = '\0';
}

int main()
{
    node_pointer root = node_constructor();
    //char keys[][10]={"the","the", "a", "there", "answer", "any","by","bye","any" ,"their"};

    char *words = (char *)malloc(sizeof(char));
    char c;
    int length_of_word = 0;

    while ((c = getchar()) != EOF)
        {
        //printf("%c \n", c);
        //printf("%d \n",length_of_word);
        if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
        {
            // {
            // }
            if ((c >= 65 && c <= 90))
            {
                c = c + 32;
            }
            words[length_of_word++] = c;
            printf("%s \n", words);
            words = realloc(words, sizeof(char) * (length_of_word));
        }

        if (c == '\0' || c == ' ' || c == '\t' || c == '\n' || c == '\r')
        {
            insert_word(root, words);
            foo(words,length_of_word);
            //strcpy(words,"");
            length_of_word = 0;
        }
    }
    insert_word(root, words);
    free(words);
    int level = 0;
    char str[200];
    print_lexicographic(root, words, level);

    return 0;
}
