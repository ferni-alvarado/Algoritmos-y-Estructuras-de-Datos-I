#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0){
        y = x;
    }
    else {
        y = -x;
    }
    printf("%d", y);
}

int main(void) {
    // Completar aqui
    int a;
    a= -98;
    int res;
    res= 0;
    absolute(a, res);
    return EXIT_SUCCESS;
}

/// si pongo el printf adentro del absolute imprime bien, 
/// si lo pongo en el main da 0 