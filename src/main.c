#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* NOTE every time we call this function with the same file pointer
 *we continue in the previous line that we were, so that there is no need
 *to return it to the start */

/* get number of elements of next data set */
int get_size(FILE* file) {
    char buff[20];

    fgets(buff, 20, file);

    return atoi(buff);
}


/* NOTE this function consumes a lot of memory because of all those mallocs */
 /* receives: file pointer, pointer to an empty array of characters, size of the set
  * returns: integer (1 = end of file/ error  0 = sucess)
  * HACK mutates the array from the pointer */
int get_set(FILE* file, char** data_arr, int size) {
    int i;

   /* loop through lines in the set and put them into array
    * if we find an EOF (end of file), return 1 (error code) */
   if (!feof(file)) {
       for (i = 0; i < size; i++) {
        /* we allocate a 50 character long string for each array element */
        data_arr[i] = malloc(sizeof(char) * 50);
        /* and then get the next line of the file and put it into that empty string */
        fgets(data_arr[i], 50, file);
       }
   } else {
       return 1;
   }

    return 0;
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

   /* gen_graph(dataset); TODO -> needs implementation */

   fclose(file);
   /* FILE SCOPE END */

   free(dataset); /* no memory leaks thank you */

    return 0;
}
