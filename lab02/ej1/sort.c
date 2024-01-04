#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    unsigned int j;
    j = i;
    int elem;
    while (j > 0u && goes_before(a[j], a[j-1u])){
        elem = a[j];
        a[j] = a[j-1u];
        a[j-1u] = elem;
        j = j-1u;
    } 
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
        assert(array_is_sorted(a,length));
    }
}
