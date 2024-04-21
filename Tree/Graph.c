#pragma once
#include "Graph.h"

void CreateGraph(Graph* pg) {
    pg->n = 0;
    for(int i = 0; i < MAXVERTEX; i++) {
        pg->entry[i].firstedge = NULL;
    }
}
 
void TraverseDepthFirstAux(Graph* pg, int k, void (*visit) (GraphEntry), int visited[]) {
    (*visit)(pg->entry[k].entry);
    visited[k] = 1;
    for(Edge *t = pg->entry[k].firstedge; t; t = t->nextedge) {
        if(!visited[t->endpoint]) {
            TraverseDepthFirstAux(pg, k, visit, visited);
        }
    }
}
void TraverseDepthFirst(Graph* pg, int k, void(*visit)(int)) {
    int visited[MAXVERTEX];
    int i;
    for(i = 0; i < pg->n; i++) {
        visited[i] = 0;
    }
    TraverseDepthFirstAux(pg, k, visit, visited);
    for(i = 0; i < pg-> n; i++) {
        if(!visited[i]) {
            TraverseDepthFirstAux(pg, k, visit, visited);
        }
    }
}
 