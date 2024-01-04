#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>

typedef int list_elem;
typedef struct _node * list;

list empty();

list addl(list_elem x, list l);

bool is_empty(list l);

list_elem head(list l);

list tail(list l);

list addr(list l, list_elem x);

unsigned int length(list l);

list concat(list l, list l1);

list_elem index(list l , unsigned int x);

list take(list l , unsigned int x);

list drop(list l, unsigned int x);

list copy_list(list l);

void destroy_list(list l);

#endif