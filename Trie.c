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
void print_lexicographic_reverse(node_pointer np, char str[], int level)
{
    if (np == NULL)
    {
        return;
    }

    for (int i = NUM_LETTERS - 1; i > -1; i--)
    {
        if (np->children[i])
        {
            str[level] = i + 'a';
            print_lexicographic_reverse(np->children[i], str, level + 1);
        }
    }
    if (np->isWord == TRUE)
    {
        str[level] = '\0';
        printf("%s %ld\n", str, np->count);
    }
}

void foo(char *arr, size_t size)
{
    for (int k = 0; k < size; k++)
        arr[k] = '\0';
}

void clean(node_pointer root){
    for(int i=0;i<NUM_LETTERS;i++){
        if(root->children[i]){
            clean(root->children[i]);
        }
    }
    free(root);
}
int main( int argc, char *argv[])
{
    
    node_pointer root = node_constructor();
    char *words = (char *)malloc(sizeof(char));
    if (!words)
            {
                printf("not enough memory to allocate");
                return 0;
            }

    char c;
    int length_of_word = 0;
    int max = 0;
    while ((c = getchar()) != EOF)
    {
        if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
        {
            if ((c >= 65 && c <= 90))
            {
                c = c + 32;
            }
            words[length_of_word++] = c;
            words = realloc(words, sizeof(char) * (length_of_word));
            if (!words)
            {
                printf("not enough memory to allocate");
                return 0;
            }
        }

        if (c == '\0' || c == ' ' || c == '\t' || c == '\n' || c == '\r')
        {
            insert_word(root, words);
            if (max < length_of_word){
                max = length_of_word;
            }
            foo(words, length_of_word);

            length_of_word = 0;
        }
    }
    if (length_of_word != 0)
    {
        insert_word(root, words);
    }
    free(words);

    int level = 0;
    char *str = (char *)malloc(sizeof(max));
    if(argc == 1){
    print_lexicographic(root, words, level);
    }
    if(argc == 2 && *argv[1] == 'r'){
    print_lexicographic_reverse(root, words, level);
    }

    clean(root);
    
    return 0;
}
