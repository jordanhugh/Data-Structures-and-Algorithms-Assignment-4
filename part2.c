#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define SIZE 7

void dijkstra(int Graph[SIZE][SIZE], int start);
 
int main(){
    int graph[SIZE][SIZE] = {
        {0, 1, 3, 0, 0, 10, 0},
        {1, 0, 1, 7, 5, 0, 2},
        {3, 1, 0, 9, 2, 0, 0},
        {0, 7, 9, 0, 2, 1, 12},
        {0, 5, 3, 2, 0, 2, 0},
        {10, 0, 0, 1, 2, 0, 0},
        {0, 2, 0, 12, 0, 0, 0}
    };

    char node;
    printf("\nEnter the starting node: ");
    scanf("%c", &node);
    int start = node - 'A';
    dijkstra(graph, start);
    return 0;
}
 
void dijkstra(int Graph[SIZE][SIZE], int start){
    int cost[SIZE][SIZE]; 
    int dist[SIZE];
    int path[SIZE];
    bool visited[SIZE];
    int count;
    int distmin;
    int next;
    
    for(int j = 0; j < SIZE; j++)
        for(int i = 0; i < SIZE; i++)
            if(Graph[j][i] == 0)
                cost[j][i] = 9999;
            else
                cost[j][i] = Graph[i][j];
    
    for(int i = 0; i < SIZE; i++){
        dist[i] = cost[start][i];
        path[i]=start;
        visited[i] = false;
    }
    
    dist[start] = 0;
    visited[start] = true;
    count = 1;
    
    while(count < SIZE - 1){
        distmin = 9999;
        
        for(int i = 0; i < SIZE; i++)
            if(dist[i] < distmin && !visited[i]){
                distmin = dist[i];
                next = i;
            }
            
            visited[next] = true;
            for(int i = 0; i < SIZE; i++)
                if(!visited[i])
                    if(distmin + cost[next][i] < dist[i]){
                        dist[i] = distmin + cost[next][i];
                        path[i] = next;
                    }
        count++;
    }

    for(int i = 0; i < SIZE; i++){
        if(i != start){
            printf("\nDistance of node %c = %d",'A' + i, dist[i]);
            printf("\nPath = %d",i);
            
            int j = i;
            do
            {
                j = path[j];
                printf(" + %d",j);
            }while(j != start);
        }
    }
}