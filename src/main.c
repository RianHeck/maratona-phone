#include <stdio.h>

int main(int argc, char* argv[]) {
   FILE* file;
   char* filename;

   if (argc != 2) {
        printf("Incorrect number of arguments\nCorrect use:\tshorthand [file path]\n");
        return 1;
    } else {
        filename = argv[1];
    }

    return 0;
}
