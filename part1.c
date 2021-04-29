#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

typedef struct Queue {
    int items[SIZE];
    int start;
    int end;
}Queue;

Queue* initialiseQueue();
int isEmpty(Queue* queue);
void addToQueue(Queue* queue, int value);
int removeFromQueue(Queue* queue);

typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

Node* initialiseNode(int vertex);

typedef struct Graph {
    int vertices;
    Node** linkedlist;
    int* visited;
}Graph;

Graph* initialiseGraph(int vertices);
void addEdge(Graph* graph, int start, int end);
void printGraph(Graph* graph);
void DFS(Graph*, int);
void BFS(Graph* graph, int start);

int main() {
    Graph* graph = initialiseGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 3);
    addEdge(graph, 5, 2);

    //printf("DPS: ");
    //DFS(graph, 0);
    BFS(graph, 0);
    return 0;
}



Queue* initialiseQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->start = -1;
    queue->end = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    if(queue->end == -1) 
        return 1;
    else 
        return 0;
}

void addToQueue(Queue* queue, int value){
    if (queue->end == SIZE - 1) {
        printf("\nQueue is Full!!");
    }
    else {
        if(queue->start == -1)
            queue->start = 0;
        queue->end++;
        queue->items[queue->end] = value;
    }
}

int removeFromQueue(Queue* queue){
    int item;
    if(isEmpty(queue)){
        printf("Queue is empty");
        item = -1;
    }
    else{
        item = queue->items[queue->start];
        queue->start++;
        if(queue->start > queue->end){
            queue->start = queue->end = -1;
        }
    }
    return item;
}



Node* initialiseNode(int vertex) {
    Node* node = malloc(sizeof(node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}



Graph* initialiseGraph(int vertices){
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = vertices;
 
    graph->linkedlist = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));
    
 
    for (int i = 0; i < vertices; i++) {
        graph->linkedlist[i] = NULL;
        graph->visited[i] = 0;
    }
 
    return graph;
}
 
void addEdge(Graph* graph, int start, int end){
    // Add edge from src to dest
    Node* node = initialiseNode(end);
    node->next = graph->linkedlist[start];
    graph->linkedlist[start] = node;
}

void printGraph(struct Graph* graph){
    for (int v = 0; v < graph->vertices; v++) {

        Node* curr = graph->linkedlist[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (curr) {
            printf("%d -> ", curr->vertex);
            curr = curr->next;
        }
        printf("\n");
    }
}

void DFS(Graph* graph, int vertex) {
        Node* linkedlist = graph->linkedlist[vertex];
        Node* curr = linkedlist;
        
        graph->visited[vertex] = 1;
        printf("%c ", 'A' + vertex);
    
        while(curr != NULL) {
            int connectedVertex = curr->vertex;
        
            if(graph->visited[connectedVertex] == 0) {
                DFS(graph, connectedVertex);
            }
            curr = curr->next;
        }       
}

void BFS(Graph* graph, int start) {
    Queue* queue = initialiseQueue();
    
    addToQueue(queue, start);
    graph->visited[start] = 1;
    
    printf("BFS: ");
    while(!isEmpty(queue)){
        int current = removeFromQueue(queue);
        printf("%c ", 'A' + current);
    
       Node* curr = graph->linkedlist[current];
       while(curr) {

            if(graph->visited[curr->vertex] == 0){
                addToQueue(queue, curr->vertex);
                graph->visited[curr->vertex] = 1;
                
            }
            curr = curr->next;
       }
    }
}