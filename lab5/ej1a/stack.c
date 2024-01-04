#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack{
    stack_elem elem;
    stack next;
};

stack stack_empty(){
    return NULL;
}

stack stack_push(stack s, stack_elem e){
        stack q = malloc(sizeof(struct _s_stack));
        q->elem = e;
        q->next = s;
        return q;
}

stack stack_pop(stack s){
    assert(s!=NULL);
    stack q = s;
    s = s->next;
    free(q);
    return s; 
}

unsigned int stack_size(stack s){
    unsigned int tam = 0u;
    if (s!=NULL){
        stack q = s;
        while(q!=NULL){
            ++tam;
            q = q->next;
        }
    }
    return tam;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elem;
}

bool stack_is_empty(stack s){
    return (s==NULL);
}

stack_elem *stack_to_array(stack s){
    if (s==NULL){
        return NULL;
    }
    else{
        stack_elem *array;
        array = calloc(stack_size(s),sizeof(stack_elem));
        stack q = s;
        for (int i=stack_size(s)-1; 0 <= i; --i){
            array[i] = q->elem;
            q = q->next;
        }
        return array;
    }
}

stack stack_destroy(stack s){
    assert(s!=NULL);
    stack d;
    while(s!=NULL){
        d = s;
        s = s->next;
        free(d);
    }
    return s;
}
