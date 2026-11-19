#include <stdio.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency Matrix
int visited[MAX];  // Visited array
int n;             // Number of vertices

// DFS Function
void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// BFS Function
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int e; // Number of edges

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;  // Directed Graph
        //adj[dest][src] = 1;  // Undirected Graph (comment this line for directed)
    }

    // DFS
    for (int i = 0; i < n; i++) visited[i] = 0; // Reset visited
    printf("\nDFS Traversal starting from vertex 0: ");
    DFS(0);

    // BFS
    printf("\nBFS Traversal starting from vertex 0: ");
    BFS(0);

    return 0;
}
