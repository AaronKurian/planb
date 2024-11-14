#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

void bfs(int startVertex, int visited[MAX_VERTICES], int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices)
{
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    while (front != rear)
    {

        int currentVertex = queue[++front];
        printf("V%d ", currentVertex);

        for (int i = 0; i < numVertices; i++)
        {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
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

    printf("BFS Traversal Order:\n");
    for (i = 0; i < numVertices; i++)
    {
        if (!visited[i])
        {
            bfs(i, visited, adjacencyMatrix, numVertices);
        }
    }

    return 0;
}