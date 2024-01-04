#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int piv, i, j;
    piv = izq;
    i = izq + 1u;
    j = der;
    while (i <= j){
        if (goes_before(a[i], a[piv])){
            i = i + 1u;
        }
        else if (goes_before(a[piv], a[j])){
            j = j - 1u;
        }
        else if (goes_before(a[piv],a[i]) && goes_before(a[j],a[piv])){
            swap(a, i, j);
        }
    }
    swap(a, piv, j);
    return (piv = j);
    

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int piv;
    if (izq < der){
        piv = partition(a, izq, der);
        if (piv != 0){
            quick_sort_rec(a, izq, piv-1); 
        }
        quick_sort_rec(a, piv+1, der);
    }

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

