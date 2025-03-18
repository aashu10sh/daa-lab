#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Subset {
    int parent;
    int rank;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight; 
}

void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V]; 
    int e = 0; 
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    int v;
    for (v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    int minimumCost = 0;
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost of Spanning Tree: %d\n", minimumCost);

    free(subsets);
}

int main() {
    int V, E, i;

    printf("Aashutosh Pudasaini\n");

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    struct Graph* graph = createGraph(V, E);
    
    printf("\nEnter edges (source, destination, weight):\n");
    printf("Vertices are numbered from 0 to %d\n\n", V-1);
    
    for (i = 0; i < E; i++) {
        printf("Edge %d:\n", i + 1);
        printf("Source: ");
        scanf("%d", &graph->edge[i].src);
        
        printf("Destination: ");
        scanf("%d", &graph->edge[i].dest);
        
        printf("Weight: ");
        scanf("%d", &graph->edge[i].weight);
        
        if (graph->edge[i].src < 0 || graph->edge[i].src >= V ||
            graph->edge[i].dest < 0 || graph->edge[i].dest >= V) {
            printf("Invalid vertex! Must be between 0 and %d.\n", V - 1);
            i--; 
        }
        
        printf("\n");
    }
    
    printf("\nApplying Kruskal's Algorithm...\n");
    KruskalMST(graph);
    
    free(graph->edge);
    free(graph);
    
    return 0;
}