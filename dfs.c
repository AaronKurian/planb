#include <stdio.h>
#define MAX_VERTICES 10

void dfs(int vertex, int visited[MAX_VERTICES], int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices)
{
    printf("V%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; i++)
    {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i])
        {
            dfs(i, visited, adjacencyMatrix, numVertices);
        }
    }
}

int main()
{
    int numVertices, i, j;

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix (1 for connected, 0 for not connected):\n");
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    int visited[MAX_VERTICES] = {0};

    printf("DFS Traversal Order:\n");
    for (i = 0; i < numVertices; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adjacencyMatrix, numVertices);
        }
    }

    return 0;
}
