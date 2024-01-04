#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    y = &x;
    if (x >= 0){
        *y = x;
    }
    else {
        *y = -x;
    }
    printf("%d", *y);
}

int main(void) {
    int *p = NULL;
    int a;
    a = -98;
    absolute(a, p);
    
    return EXIT_SUCCESS;
}

// si pongo el printf en main no anda el codigo, si lo pongo en la absolute si anda 
