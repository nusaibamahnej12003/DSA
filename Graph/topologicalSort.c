#include <stdio.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency Matrix
int indegree[MAX]; // Indegree array
int n;             // Number of vertices

void topologicalSort() {
    int queue[MAX], front = 0, rear = 0;
    int count = 0;

    // Find all vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Order: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        // Decrease indegree of adjacent vertices
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if (count != n) {
        printf("\nGraph contains a cycle! Topological sort not possible.\n");
    }
}

int main() {
    int e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix & indegree array
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
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
        adj[src][dest] = 1;  // Directed graph
        indegree[dest]++;    // Increase indegree of destination
    }

    topologicalSort();
    return 0;
}
