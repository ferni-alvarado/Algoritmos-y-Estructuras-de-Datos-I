/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"



bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}


bool goes_before(player_t x, player_t y){
    if (x->rank < y->rank){
        return true;
    }
    else {
        return false;
    }
}

void sort(player_t a[], unsigned int length) {
    // completar aquí
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
        array_is_sorted(a,length);
    }
}

static void insert(player_t a[], unsigned int i) {
    unsigned int j;
    j = i;
    player_t elem;
    elem = NULL;
    while (j > 0 && goes_before(a[j], a[j-1])){
        elem = a[j];
        a[j] = a[j-1];
        a[j-1] = elem;
        j = j-1;
    } 
}

