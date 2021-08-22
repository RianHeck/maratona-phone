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

 /* receives: file pointer, pointer to an empty array of characters, size of the set
  * returns: integer (1 = end of file/ error  0 = sucess)
  * HACK mutates the array from the pointer */
int get_set(FILE* file, char** data_arr, int size) {
    int i;

   /* loop through lines in the set and put them into array
    * if we find an EOF (end of file), return 1 (error code) */
   if (!feof(file)) {
       for (i = 0; i < size; i++) {
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

   /* FIXME I know there's a segfault starting somewhere on this malloc */
   dataset = (char **)malloc(size * sizeof(char) * 50);
   get_set(file, dataset, size);

   /* gen_graph(dataset); TODO -> needs implementation */

   printf("this is the first element: %s\n", dataset[0]);

   fclose(file);
   /* FILE SCOPE END */

    return 0;
}
