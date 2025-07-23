//
// Created by Admin on 23/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void addEdge(int graph[SIZE][SIZE] ,int start,int end) {
    graph[start][end]=1;
    graph[end][start]=1;
}
void printMatrix(int graph[SIZE][SIZE]) {
    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE;j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int graph[SIZE][SIZE]={{0}};
    addEdge(graph,1,2);
    printMatrix(graph);
}