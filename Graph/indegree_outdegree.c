#include <stdio.h>

#define MAX 100

int main() {
    int n, e;  // n = vertices, e = edges
    int adj[MAX][MAX];
    int indeg[MAX] = {0}, outdeg[MAX] = {0};

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
        adj[src][dest] = 1; // Directed graph
    }

    // Calculate indegree and outdegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                outdeg[i]++; // edge from i → j
                indeg[j]++;  // edge coming to j
            }
        }
    }

    // Print degrees
    printf("\nVertex\tIn-degree\tOut-degree\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i, indeg[i], outdeg[i]);
    }

    return 0;
}
