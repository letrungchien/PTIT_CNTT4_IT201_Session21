//
// Created by Admin on 23/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
} Graph;
Graph* createGraph(int V) {
    Graph *graph=(int*)malloc(sizeof(Graph));
    graph->V=V;
    graph->matrix=(int**)malloc(sizeof(int*)*V);
    for(int i=0;i<V;i++) {
        graph->matrix[i]=(int*)calloc(V,sizeof(int));
    }
    return graph;
}
void addEdge(Graph*graph,int src,int dest) {
    graph->matrix[src][dest]=1;
    graph->matrix[dest][src]=1;
}
void printfMatrix(Graph*graph) {
    for(int i=0;i<graph->V;i++) {
        for(int j=0;j<graph->V;j++) {
            printf("%d ",graph->matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    Graph*qraph=createGraph(3);
    addEdge(qraph,1,2);
    printfMatrix(qraph);
    return 0;
}