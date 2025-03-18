#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    
    return min_index;
}

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    printf("Edge \tWeight\n");
    int totalWeight = 0;
    
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    
    printf("Total weight of MST: %d\n", totalWeight);
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int parent[MAX_VERTICES];   
    int key[MAX_VERTICES];      
    bool mstSet[MAX_VERTICES];  
    
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    
    key[0] = 0;      
    parent[0] = -1; 
    
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        
        mstSet[u] = true;
        
        for (int v = 0; v < V; v++) {

            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    printMST(parent, graph, V);
}

int main() {
    int V;

    printf("Aashutosh Pudasaini \n");

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    
    printf("Enter the adjacency matrix (enter 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("\nRunning Prim's algorithm...\n");
    primMST(graph, V);
    
    return 0;
}
