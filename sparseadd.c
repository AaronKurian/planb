#include <stdio.h>

int main()
{
    int rows1, cols1;

    // User input for the dimensions of the first matrix
    printf("Enter the number of rows for first matrix: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for first matrix: ");
    scanf("%d", &cols1);

    int matrix1[rows1][cols1];

    // User input for the elements of the first matrix
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Array to store triplet representation of the first sparse matrix
    int triplet1[rows1 * cols1][3];
    int k1 = 1; // Index for triplet array for the first matrix

    // Generate triplet representation for the first matrix
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            if (matrix1[i][j] != 0)
            {                                    // Only consider non-zero values
                triplet1[k1][0] = i;             // Row index
                triplet1[k1][1] = j;             // Column index
                triplet1[k1][2] = matrix1[i][j]; // Non-zero value
                k1++;
            }
        }
    }
    // Store dimensions and number of non-zero elements in the triplet
    triplet1[0][0] = rows1;
    triplet1[0][1] = cols1;
    triplet1[0][2] = k1 - 1;

    // Input for the second matrix dimensions
    int rows2, cols2;
    printf("Enter the number of rows for second matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for second matrix: ");
    scanf("%d", &cols2);

    // Check if both matrices have the same dimensions
    if (rows1 != rows2 || cols1 != cols2)
    {
        printf("Matrices must have the same dimensions for addition.\n");
        return 1;
    }

    int matrix2[rows2][cols2];

    // User input for the elements of the second matrix
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Array to store triplet representation of the second sparse matrix
    int triplet2[rows2 * cols2][3];
    int k2 = 1; // Index for triplet array for the second matrix

    // Generate triplet representation for the second matrix
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            if (matrix2[i][j] != 0)
            {                                    // Only consider non-zero values
                triplet2[k2][0] = i;             // Row index
                triplet2[k2][1] = j;             // Column index
                triplet2[k2][2] = matrix2[i][j]; // Non-zero value
                k2++;
            }
        }
    }
    // Store dimensions and number of non-zero elements in the triplet
    triplet2[0][0] = rows2;
    triplet2[0][1] = cols2;
    triplet2[0][2] = k2 - 1;

    // Print triplet representation of the first sparse matrix
    printf("Triplet representation of the 1st sparse matrix:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < k1; i++)
    {
        printf("%d\t%d\t%d\n", triplet1[i][0], triplet1[i][1], triplet1[i][2]);
    }

    // Print triplet representation of the second sparse matrix
    printf("Triplet representation of the 2nd sparse matrix:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < k2; i++)
    {
        printf("%d\t%d\t%d\n", triplet2[i][0], triplet2[i][1], triplet2[i][2]);
    }

    // Sparse matrix addition
    int triplet3[rows1 * cols1][3];
    int k3 = 1; // Index for the result triplet array
    int i = 1, j = 1;

    // Initialize the result triplet with the dimensions
    triplet3[0][0] = rows1;
    triplet3[0][1] = cols1;

    // Perform addition of the two sparse matrices
    while (i < k1 && j < k2)
    {
        if (triplet1[i][0] == triplet2[j][0] && triplet1[i][1] == triplet2[j][1])
        {
            // Same position in both matrices
            triplet3[k3][0] = triplet1[i][0];
            triplet3[k3][1] = triplet1[i][1];
            triplet3[k3][2] = triplet1[i][2] + triplet2[j][2];
            i++;
            j++;
            k3++;
        }
        else if (triplet1[i][0] < triplet2[j][0] ||(triplet1[i][0] == triplet2[j][0] && triplet1[i][1] < triplet2[j][1]))
        {
            // Only in the first matrix
            triplet3[k3][0] = triplet1[i][0];
            triplet3[k3][1] = triplet1[i][1];
            triplet3[k3][2] = triplet1[i][2];
            i++;
            k3++;
        }
        else
        {
            // Only in the second matrix
            triplet3[k3][0] = triplet2[j][0];
            triplet3[k3][1] = triplet2[j][1];
            triplet3[k3][2] = triplet2[j][2];
            j++;
            k3++;
        }
    }

    // Add remaining elements from triplet1
    while (i < k1)
    {
        triplet3[k3][0] = triplet1[i][0];
        triplet3[k3][1] = triplet1[i][1];
        triplet3[k3][2] = triplet1[i][2];
        i++;
        k3++;
    }

    // Add remaining elements from triplet2
    while (j < k2)
    {
        triplet3[k3][0] = triplet2[j][0];
        triplet3[k3][1] = triplet2[j][1];
        triplet3[k3][2] = triplet2[j][2];
        j++;
        k3++;
    }

    // Update the number of non-zero elements in the result triplet
    triplet3[0][2] = k3 - 1;

    // Print the triplet representation of the resulting sparse matrix
    printf("Triplet representation of the resulting sparse matrix:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < k3; i++)
    {
        printf("%d\t%d\t%d\n", triplet3[i][0], triplet3[i][1], triplet3[i][2]);
    }

    return 0;
}