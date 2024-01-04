#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct _node
{
    list_elem elem;
    list next;
};

list empty()
{
    return NULL;
}

list addl(list_elem x, list l)
{
    list q;
    q = malloc(sizeof(struct _node));
    q->elem = x;
    q->next = l;
    return q;
}

bool is_empty(list l)
{
    return (l == NULL);
}

unsigned int length(list l)
{
    list q;
    unsigned int x;
    x = 0;
    q = l;
    while (q->next != NULL)
    {
        x = x + 1;
        q = q->next;
    }
    x = x +1 ;
    return x;
}

list_elem head(list l)
{
    assert(length(l)>0);
    list_elem x;
    x = l->elem;
    return x;
}

list tail(list l)
{
    assert(length(l)>0);
    list p;
    p = l;
    l = l->next;
    free(p);
    return l;
}


list copy_list(list l)
{
    list l1 = empty();
    list p = l;
    while (p != NULL){
        addr(l1, p->elem);
    }
    return l1;
}


list addr(list l, list_elem x)
{
    list q;
    q = malloc(sizeof(struct _node));
    list p;
    q->elem = x;
    q->next = NULL;
    if (!is_empty(l)){
        p = l;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
    else {
        l = q;
    }
    return l;
}

list concat(list l, list l1){
    list p;
    if (!is_empty(l)){
        p = l;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = l1;
    }
    else {
        l = l1;
    }
    return l;        
}

list_elem index(list l , unsigned int x){
    assert(x < length(l));
    list q;
    unsigned int z = 0;
    q = l;
    while (z < x)
    {
        q = q->next;
        z = z + 1;
    }
    return q->elem;
}

void destroy_list(list l){
    assert(l != NULL);
    list p;
    p = l;
    while (p->next != NULL)
    {
        p = l;
        l = l->next;
        free(p);
    }
    l = NULL;    
}
