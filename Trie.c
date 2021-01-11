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

void print_lexicographic(node_pointer np,char str[],int level)
{
    if (np->isWord==TRUE)
    {
        str[level]='\0';
        printf("%s %ld\n", str,np->count);
        
    }
    for(int i=0;i<NUM_LETTERS;i++){
    if(np->children[i]){
    str[level]=i+'a';
    print_lexicographic(np->children[i],str,level+1);
    }
    }
}

<<<<<<< HEAD
/*void preorder(node_pointer follow, char *hold)
=======
void preorder(node_pointer follow, char *hold)
>>>>>>> 7549a2d56410f70e84b4d62dfcd81cecba68b3ee
{
    int i = 0;
    if (follow == NULL)
    {
        return;
    }
   
    if (follow->isWord == TRUE)
    {
<<<<<<< HEAD
        printf("%s %ld\n", hold,follow->count);
=======
        printf("%s %ld\n", hold, follow->count);
>>>>>>> 7549a2d56410f70e84b4d62dfcd81cecba68b3ee
    }

    for (i = 0; i < 26; i++)
    {
<<<<<<< HEAD
        char *strcat(hold,follow->letter);
        preorder(follow->children[i], strcat);
    }
}
*/
/*
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
=======
        const char ot = 'a' + i;
        strcat(hold, (char)('a' + i));
        preorder(follow->children[i], hold);
>>>>>>> 7549a2d56410f70e84b4d62dfcd81cecba68b3ee
    }
}
*/
int main()
{
    node_pointer root = node_constructor();
<<<<<<< HEAD
    //char keys[][10]={"the","the", "a", "there", "answer", "any","by","bye","any" ,"their"};
	
    char *words=(char*)malloc(sizeof(char));
    char c;
    int length_of_word=0;
    
    while((c=getchar())!=EOF){
    
    	words[length_of_word++]=c;
    	words=realloc(words,sizeof(char)*(length_of_word));
    	
	if(c== '\0' || c != ' ' || c != '\t' || c != '\n' || c != '\r'){
		insert_word(root,words);
	}
    }
    
    int level=0;
    char str[20];
    print_lexicographic(root,words,level);
    
    /*
    for(int j=0;j<(sizeof(keys)/sizeof(keys[0]));j++){
    insert_word(root,keys[j]);
    }
    int level=0;
    char str[20];
    print_lexicographic(root,str,level);
    
    /*
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
    print_lexicographic(root);
    */


    return 0;
   
    
}
=======
    char *str = (char *)malloc(6);
    int ch;
    size_t size = 6, len = 0;

    while ((ch = getchar()) != EOF)
    {
        if (!(ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
        {
            insert_word(root, str);
            free(str);
            str = malloc(sizeof(char) * size);
        }

        else
        {
            if ((ch >= 65 && ch <= 90))
            {
                ch = ch + 32;
            }
            str[len++] = ch;
        }

        if (len == size)
        {
            size = size * 2;
            str = realloc(str, sizeof(char) * size);
        }
    }
    
    char *hold = malloc(sizeof(char) * size);
    preorder(root, hold);

    return 0;
}
>>>>>>> 7549a2d56410f70e84b4d62dfcd81cecba68b3ee
