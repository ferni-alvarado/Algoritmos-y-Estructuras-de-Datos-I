#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack{
    stack_elem elem;
    stack next;
    unsigned int size;
};

stack stack_empty(){
    return NULL;
}

stack stack_push(stack s, stack_elem e){
    if (s == NULL){
        s = malloc(sizeof(struct _s_stack));
        s->elem = e;
        s->next = NULL;
        s->size = 1;
        return s;
    }
    else{
        stack q = malloc(sizeof(struct _s_stack));
        q->elem = e;
        q->next = s;
        q->size = s->size;
        ++q->size;
        return q;
    }
}

stack stack_pop(stack s){
    assert(s!=NULL);
    stack q = s;
    s = s->next;
    --s->size;
    free(q);
    return s; 
}

unsigned int stack_size(stack s){
    return s->size;
}

stack_elem stack_top(stack s){
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
        for (unsigned int i=stack_size(s)-1; i>=0; i--){
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
