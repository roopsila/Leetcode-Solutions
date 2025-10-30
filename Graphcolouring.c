#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int color[MAX];
int vertices, frequencies;

int isSafe(int node, int freq) {
    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] && color[i] == freq)
            return 0;
    }
    return 1;
}

int assignFrequency(int node) {
    if (node == vertices)
        return 1;

    for (int freq = 1; freq <= frequencies; freq++) {
        if (isSafe(node, freq)) {
            color[node] = freq;

            if (assignFrequency(node + 1))
                return 1;

            color[node] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter number of cells (vertices): ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of available frequencies: ");
    scanf("%d", &frequencies);

    for (int i = 0; i < vertices; i++)
        color[i] = 0;

    if (assignFrequency(0)) {
        printf("\nFrequencies assigned to each cell:\n");
        for (int i = 0; i < vertices; i++)
            printf("Cell %d = Frequency %d\n", i + 1, color[i]);
    } else {
        printf("\nNo valid frequency assignment possible.\n");
    }

    return 0;
}
