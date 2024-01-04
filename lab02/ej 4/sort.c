#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    unsigned int j;
    j = i;
    while (j > 0u && goes_before(a[j], a[j-1u])){
        swap(a, j-1u, j);
        j = j-1u;
    } 
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


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
        else /*f (goes_before(a[piv],a[i]) && goes_before(a[j],a[piv]))*/{
            swap(a, i, j);
        }
    }
    swap(a, piv, j);
    return (piv = j);
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int piv;
    if (izq < der){
        piv = partition(a, izq, der);
        if (piv > 0){
            quick_sort_rec(a, izq, piv-1); 
        }
        if (piv < der){
            quick_sort_rec(a, piv+1, der);
        }
        
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
