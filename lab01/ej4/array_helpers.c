#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_helpers.h"

bool array_is_sorted(int a[], unsigned int max_size){

	bool ordenado = true;
  unsigned int i = 0;
  if (max_size > 0) {
    while (i < (max_size - 1) && ordenado) {
      if (a[i] <= a[i+1]) {
        ordenado = true;
        i++;
      } else {
        ordenado = false;
        printf("El arreglo no está ordenado\n");
        return ordenado;
      }
    }
  } else {
    ordenado = true;
  }


  
  printf("El arreglo está ordenado\n");
	return ordenado; 

}


unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    
    array = array;
    max_size = max_size;
    filepath = filepath;
    
    FILE*fp;
    
    fp = fopen(filepath,"r");   
    
    if (fp == NULL){
       printf("No such file.\n");
       exit(1);
    } else {
       fscanf(fp, "%u", &max_size);    // Para el tamano del arreglo
       for(unsigned int i = 0; i<max_size; i++){       
         fscanf(fp, "%d", &array[i]);               // Para los elementos de arreglo
       }
    }
       
    fclose(fp);
    
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
}
