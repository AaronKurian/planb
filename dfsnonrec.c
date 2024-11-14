#include <stdio.h>
#define MAX_VERTICES 10

void dfs(int vertex, int visited[MAX_VERTICES], int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices)
{
    int nb[numVertices];
    nb[0]=vertex;
    int top=0;
    
    while(top!=-1)
    {
        int current = nb[top--];
        visited[current] = 1;
        printf("V%d ", current);
    for (int i = numVertices - 1; i >= 0; i--)
    {
        if (adjacencyMatrix[current][i] == 1 && !visited[i])
        {
            nb[++top]=i;

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

    printf("DFS Traversal Order:\n");
 
            dfs(0, visited, adjacencyMatrix, numVertices);

    return 0;
}
