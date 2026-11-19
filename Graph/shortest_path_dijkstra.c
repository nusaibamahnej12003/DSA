#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 999999

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX], visited[MAX];
    
    for (int i = 0; i < n; i++) {
        dist[i] = INF;      // Initial distance = infinity
        visited[i] = 0;     // No node visited yet
    }
    
    dist[src] = 0; // Source distance = 0
    
    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;
        
        // Find vertex with smallest distance and not visited
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < min) {
                min = dist[v];
                u = v;
            }
        }
        
        visited[u] = 1; // Mark as visited
        
        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // Print shortest distances
    printf("\nShortest distances from vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &e);
    
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // Directed graph
        graph[v][u] = w; // If undirected graph
    }
    
    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);
    
    dijkstra(graph, n, src);
    
    return 0;
}
