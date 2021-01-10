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

void preorder(struct node *follow, char hold[200], int s)
{
    int i = 0;
    if (follow == NULL)
    {
        return;
    }
    /* Print the word at the beginning instead of the end */
    if (follow->isWord == TRUE)
    {
        hold[s] = 0;
        printf("%s\n", hold);
    }

    for (i = 0; i < 26; i++)
    {
        hold[s] = 'a' + i;
        preorder(follow->children[i], hold, s + 1);
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

    while (1)
    {
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

        insert_word(root, w);

        if (w[counter] == EOF)
        {
            free(w);
            break;
        }

        free(w);
    }
    char hold[200];
    preorder(root, hold, 0);
}