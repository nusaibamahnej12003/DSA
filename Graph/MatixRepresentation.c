#include <stdio.h>

#define MAX 100

int main() {
    int n, e;  // n = number of vertices, e = number of edges
    int adjMatrix[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination) one per line:\n");
    for (int i = 0; i < e; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);

        // For undirected graph, mark both [src][dest] and [dest][src]
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
