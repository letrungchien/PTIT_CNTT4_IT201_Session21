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

//DFS
void DFSUtil(Graph*graph,int src,int *visited) {
    printf("%d ",src);
    visited[src]=1;
    for(int i=0;i<graph->V;i++) {
        if (graph->matrix[i][src]==1 && visited[i]==0) {
            DFSUtil(graph,i,visited);
        }
    }
}
void DFS(Graph*graph,int src) {
    int *visited=(int*)calloc(graph->V,sizeof(int));
    printf("bat dau duyet DFS ");
    DFSUtil(graph,src,visited);
    free(visited);
}
 typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;
Queue* createQueue(int capacity) {
    Queue* queue=(int*)malloc(sizeof(Queue));
    queue->arr=(int*)calloc(capacity,sizeof(int));
    queue->front=0;
    queue->rear=-1;
    queue->capacity=capacity;
    return queue;
}
void enqueue(Queue*queue, int vertex) {
    if(queue->rear==queue->capacity-1) {
        printf("queue full");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear]=vertex;
}
int isEmpty(Queue*queue) {
     if(queue->front>queue->rear) {
        printf("queue empty");
        return 1;
    }
    return 0;
}
int dequeue(Queue*queue) {
    if(isEmpty(queue)) {
        return 1;
    }
    int value = queue->arr[queue->front];
    queue->front++;
    return value;
}
void BFS(Graph*graph,int src) {
    int *visited=(int*)calloc(graph->V,sizeof(int));
    Queue* queue=createQueue(graph->V);
    enqueue(queue,src);
    visited[src]=1;
    while(!isEmpty(queue)) {
        int vertex=dequeue(queue);
        printf("%d ",vertex);
    for(int i=0;i<graph->V;i++) {
        if (graph->matrix[vertex][i]==1 && visited[i]==0) {
            visited[i]=1;
            enqueue(queue,i);
        }
    }

    }
    printf("\n");
    free(visited);
}
int main() {
    Graph*qraph=createGraph(4);
    addEdge(qraph,0,1);
    addEdge(qraph,1,3);
    addEdge(qraph,0,2);

    printfMatrix(qraph);
    DFS(qraph,0);
    printf("ggggg\n");
    BFS(qraph,0);

    return 0;
}