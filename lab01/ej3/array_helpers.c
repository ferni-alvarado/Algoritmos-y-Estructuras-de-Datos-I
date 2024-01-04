#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"


unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    max_size = max_size;
    filepath = filepath;
    array = array;
    FILE *inputFile;
    inputFile = fopen(filepath,"r");
    if (inputFile == NULL){
        printf("no existe el archivo \n");
        exit(1);
    }
    else{
        fscanf(inputFile, "%u", &max_size);
        for(unsigned int i = 0; i<max_size; i++){
            fscanf(inputFile, "%d", &array[i]);
        }
    }
    fclose(inputFile);
    return max_size;
}

void array_dump(int a[], unsigned int length) {
    
    printf("[");
    for(unsigned int i = 0; i<length; i++)
    {
      printf("%d", a[i]);
      if (i < length-1)
      {
        printf(", ");
      }
    }
    printf("]");
    printf("\n");
}
