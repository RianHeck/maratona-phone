#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* declare a node type for our graph */
typedef struct node Node;
/* and then define it */
struct node {
    int value;
    char letter;
    /* this is called a "self-referencing" struct,
     * which has some influence from OOP (not really) */
    Node* child;
    Node* sibling;
};

/* NOTE: every time we call this function with the same file pointer
 *we continue in the previous line that we were, so that there is no need
 *to return it to the start */

/* get number of elements of next data set */
int get_size(FILE* file) {
    char buff[20];

    fgets(buff, 20, file);

    return atoi(buff);
}


/* NOTE: this function consumes a lot of memory because of all those mallocs */
 /* receives: file pointer, pointer to an empty array of characters, size of the set
  * returns: integer (1 = end of file/ error  0 = sucess)
  * HACK: mutates the array from the pointer */
int get_set(FILE* file, char** data_arr, int size) {
    int i;

   /* loop through lines in the set and put them into array
    * if we find an EOF (end of file), return 1 (error code) */
   if (!feof(file)) {
       for (i = 0; i < size; i++) {
        /* we allocate a 50 character long string for each array element */
        data_arr[i] = malloc(sizeof(char) * 80);
        /* and then get the next line of the file and put it into that empty string */
        fgets(data_arr[i], 80, file);
       }
   } else {
       return 1;
   }

    return 0;
}

/* receives: letter of the correspondent character
 * returns: a new Node struct */
Node* new_node(char letter) {
    Node* result = malloc(sizeof(Node));
    if (result != NULL) {
        result->value = 1;
        result->child = NULL;
        result->sibling = NULL;
        result->letter = letter;
    }
    return result;
}

/* generates a new branch on the tree depending on the existing one */
Node* gen_branch(char string[], Node* previous, int pos) {
    if ( &previous->letter != NULL ) {
        previous->child = new_node(string[pos+1]);
    }

/* receives: dataset (array of strings), number of strings in dataset
 * returns: void (NOTE: not decided yet)
 * HACK: generates the tree structure on the heap (NOTE: has to be freed manually later) */
void gen_tree(char** dataset, int size) {
    for (int i = 0; i < size; i++) {
        Node* branch = new_node(dataset[i][0]);
        gen_branch(dataset[i], branch, 1);
    }
}

float get_score(char** dataset, int size) {
    float average = 0;

    gen_tree(dataset, size);
    return average;
}

int main(int argc, char* argv[]) {
   FILE* file;
   char* filename;
   char** dataset;
   int size;
   /* int i;  iterator index */

   if (argc != 2) {
        printf("Incorrect number of arguments\nCorrect use:\tshorthand [file path]\n");
        return 1;
    } else {
        filename = argv[1];
   }

   /* FILE SCOPE BEGIN */
   file = fopen(filename, "r");

   /* do whatever here */
   size = get_size(file);
   printf("size is: %d\n", size);

   /* we first allocate the number of pointer to our arrays.
    * they will be create at get_set() later */
   dataset = malloc(size * sizeof(char*));
   get_set(file, dataset, size);

   /* get_score(dataset, size); TODO -> needs implementation */

   fclose(file);
   /* FILE SCOPE END */

   free(dataset); /* no memory leaks thank you */

    return 0;
}
