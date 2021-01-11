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

void print_lexicographic(node_pointer np)
{
    if (np == NULL)
    {
        return;
    }
}

void preorder(node_pointer follow, char *hold)
{
    int i = 0;
    if (follow == NULL)
    {
        return;
    }
    /* Print the word at the beginning instead of the end */
    if (follow->isWord == TRUE)
    {
        printf("%s %d\n", hold,follow->count);
    }

    for (i = 0; i < 26; i++)
    {
        char *strcat(hold,follow->letter);
        preorder(follow->children[i], strcat);
    }
}

char *get_word()
{
    size_t size = 0;
    char c;
    char *w;
    int counter = 0;
    while (((c = getchar()) != '\0' && c != ' ' && c != '\t' && c != '\n' && c != '\r') && c != EOF)
    {
        w[counter++] = c;
        if (counter == size)
        {
            w = realloc(w, sizeof(*w) * (size += 16));
            if (!w)
                return w;
        }
    }
}

int main()
{
    node_pointer root = node_constructor();
    char *str = (char*)malloc(6);
    int ch;
    size_t size = 6, len = 0;

    while ((ch=getchar()) != EOF) {
        str[len++] = ch;

        if(len==size){
            size=size*2 ;
            str = realloc(str, sizeof(char)*size);       
        }

        if(ch==' ')
        {
            insert_word(root,str);
            free(str);
            str = malloc(str, sizeof(char)*size);
        }

    }
    preorder(root);


    return 0;
   
    
}