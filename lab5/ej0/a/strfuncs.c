#include "strfuncs.h"
#include <stdio.h>
#include <stdlib.h>

size_t string_length(const char *str){
    unsigned int i;
    size_t a;
    a = 0;
    i = 0u;
    if (str == NULL){
        return 0;
    }
    else {
        while (str[i] != '\0'){
            ++a;
            ++i;
        }
        return a;
    }   
}

char *string_filter(const char *str, char c){
    char *a;
    unsigned int i = 0;
    unsigned int j = 0;
    a = malloc(sizeof(str));
    if (str == NULL){
        return NULL;
    }    
    else {
        while (str[i]!= '\0'){
            if(str[i] != c){
                a[j] = str[i];
                ++j;
            }
            i++;
        }
        return a;
    }
}
