#include <assert.h>
#include <stdlib.h>

#include "cost.h"
#include "graph.h"
#include "mini_set.h"

vertex_t min_edge(cost_t *D, set C, vertex_t max){

    vertex_t c = set_get(C);					    
    cost_t cost = D[c];							     
    for (vertex_t i = 0u; i < max; ++i){                 
        if(cost_lt(D[i], cost) && set_member(i, C)) {
                cost = D[i];
                c = i;
            }
        }
    return c;
}

cost_t *dijkstra(graph_t graph, vertex_t init) {
	vertex_t c;
	vertex_t max = graph_max_vertexs(graph);     
	set C = set_empty();
    cost_t *D = calloc(max, sizeof(cost_t));
    
	for(vertex_t i = 0u; i < max; ++i){
		C = set_add(C,i);   
        D[i] = graph_get_cost(graph, init, i);
                     
	}
	C = set_elim(C, init);

	while(!set_is_empty(C)){
		c = min_edge(D, C, max);
		C = set_elim(C,c);
		for(vertex_t j = 0u ; j < max; ++j){			  	
			if(cost_lt(cost_sum(D[c], graph_get_cost(graph,c,j)), D[j]) && set_member(j,C)){  
				D[j] = cost_sum(D[c], graph_get_cost(graph,c,j));         
			}
		}
	}
    set_destroy(C);
    return D;
}
