#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index = -1;
    int v;
    
    for (v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void printSolution(int dist[], int V, int source) {
    printf("\nVertex \t Distance from Source (%d)\n", source);
    
    int i;
    for (i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d \t INF\n", i); 
        else
            printf("%d \t %d\n", i, dist[i]);
    }
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void printAllPaths(int parent[], int dist[], int V, int source) {
    printf("\nShortest paths from source %d:\n", source);
    
    int i;
    for (i = 0; i < V; i++) {
        if (i != source) {
            if (dist[i] == INT_MAX) {
                printf("No path to %d\n", i);
            } else {
                printf("Path to %d (cost = %d): %d", i, dist[i], source);
                printPath(parent, i);
                printf("\n");
            }
        }
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int source) {
    int dist[MAX_VERTICES];     
    bool sptSet[MAX_VERTICES];  
    int parent[MAX_VERTICES];   

    int i, count, u, v;
    
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }
    
    dist[source] = 0;
    
    for (count = 0; count < V - 1; count++) {
        u = minDistance(dist, sptSet, V);
        
        if (u == -1) 
            break;

        sptSet[u] = true;
        
        for (v = 0; v < V; v++) {
            if (!sptSet[v] && 
                graph[u][v] && 
                dist[u] != INT_MAX && 
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    printSolution(dist, V, source);
    
    printAllPaths(parent, dist, V, source);
}

int main() {
    int V, source, i, j;

    printf("Aashutosh Pudasaini\n");
    
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("\nEnter the weighted adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &source);
    
    if (source < 0 || source >= V) {
        printf("Invalid source vertex! Must be between 0 and %d.\n", V - 1);
        return 1;
    }
    
    printf("\nRunning Dijkstra's algorithm...\n");
    dijkstra(graph, V, source);
    
    return 0;
}