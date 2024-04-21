#include <stdio.h>
#include "Global.h"
 
typedef struct graphadjmat {
    int n;
    int A[MAXVERTEX][MAXVERTEX];
}GraphAdjacencyMatrix;
 
typedef struct edge {
    int endpoint;
    struct edge* nextedge;
}Edge;
 
typedef struct vertex {
    GraphEntry entry;
    Edge* firstedge;
}Vertex;
 
typedef struct graphadjlistlinked {
    int n;
    Vertex entry[MAXVERTEX];
}Graph;
 
void CreateGraph(Graph*);
void TraverseDepthFirst(Graph*, int, void(*)(int));
void BuildGraphFromAdjacency(Graph*, int, int [][MAXVERTEX]);