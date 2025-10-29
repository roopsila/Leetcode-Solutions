#include <stdio.h>

#define MAX 10 

int numVertices;
int graph[MAX][MAX];   
int path[MAX];         

void getNextVertex(int k) {
    int j;

    while (1) {
        path[k] = (path[k] + 1) % (numVertices + 1);

        if (path[k] == 0)
            return;

        if (graph[path[k - 1]][path[k]] != 0) {
            for (j = 1; j < k; j++) {
                if (path[j] == path[k])
                    break;
            }

            if (j == k) {
                if ((k < numVertices) || 
                    (k == numVertices && graph[path[numVertices]][path[1]] != 0))
                    return;
            }
        }
    }
}

void findHamiltonianCycle(int k) {
    while (1) {
        getNextVertex(k);

        if (path[k] == 0)
            return;

        if (k == numVertices) {
            printf("\nHamiltonian Cycle: ");
            for (int i = 1; i <= numVertices; i++)
                printf("%d ", path[i]);
            printf("%d", path[1]);  
        }
        else
            findHamiltonianCycle(k + 1);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix (use 1 for edge, 0 for no edge):\n");
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 1; i <= numVertices; i++)
        path[i] = 0;

    path[1] = 1;

    printf("\nAll possible Hamiltonian Cycles are:\n");
    findHamiltonianCycle(2);

    return 0;
}
