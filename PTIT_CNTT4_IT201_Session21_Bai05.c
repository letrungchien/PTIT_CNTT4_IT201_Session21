//
// Created by Admin on 23/07/2025.
//
#include <stdlib.h>
#include <stdio.h>
typedef  struct Node {
    int data;
    struct Node *next;
}Node;
Node *createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Node * graph[],int start, int end) {
Node * newNode = createNode(end);
   newNode->next = graph[start];
    graph[start]=newNode;
}
void printGraph(Node* graph[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d -> ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
int size=3;
    Node * graph[3]={NULL};
    addEdge(graph,1,2);
    printGraph(graph,size);
    printf("\n");
    addEdge(graph,0,1);
    printGraph(graph,size);

    return 0;
}