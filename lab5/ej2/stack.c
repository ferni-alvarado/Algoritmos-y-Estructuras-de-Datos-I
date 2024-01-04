#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
  stack s = malloc(sizeof(struct _s_stack));
  s->size = 0;
  s->capacity= 0;
  s->elems = NULL;
  return s;
}

stack stack_push(stack s, stack_elem e){
    assert(s!= NULL);
    if (s->size >= s->capacity){
        size_t capac = s->size == 0 ? 1*sizeof(stack_elem) : 2*s->size*sizeof(stack_elem); 
        // el ? es como un if, si se cumple s.size == 0 entonces toma el valor de 1*sizeof, sino el otro.
        s->elems = realloc(s->elems, capac);   
    }
    s->elems[s->size] = e;
    ++s->size;
    s->capacity = s->size;
    return s;
}

stack stack_pop(stack s){
    assert(s!=NULL);
    assert(s->size != 0);
    assert(s->elems!=NULL);
    --s->size;
    return s;
}

unsigned int stack_size(stack s){
    assert(s!=NULL);
    return s->size;
}

stack_elem stack_top(stack s){
    assert(s!=NULL);
    assert(s->size != 0);
    assert(s->elems!=NULL);
    return s->elems[s->size-1];        
}

bool stack_is_empty(stack s){
    assert(s!=NULL);
    return s->elems==NULL; //ver si agregar o cambiar por s->size == 0
}

stack_elem *stack_to_array(stack s){
    assert(s!=NULL);
    assert(s->size != 0);
    stack_elem* array;
    if (s->elems==NULL){
        array = NULL;
    }
    else{
        array = calloc(s->size, s->size*sizeof(stack_elem));
        for(unsigned int i = 0u; i<s->size; ++i){
            array[i] = s->elems[i];
        }
    }
    return array;
}

stack stack_destroy(stack s){
    assert(s!=NULL);
    free(s->elems);
    free(s);
    return NULL;
}