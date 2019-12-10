#include "graph.h"

void print_matrix(char array_station[LEN][MAX_LEN_STATION], int matrix[LEN][LEN], int n)
{
    printf("             ");
    for (int i = 0; i < n; i++)
        printf("%25s ", array_station[i]);

    puts("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%10s ", array_station[i]);
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INFINITY)
                printf("    oo    ");
            else
                printf("    %7d    ", matrix[i][j]);
        }
        printf("\n\n\n");
    }
}

void min_way_matrix(int matrix[LEN][LEN], int matrix_p[LEN][LEN], int n) // Search
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    matrix_p[i][j] = k;
                    // matrix_p[i][j] = k + 1;
                }
            }
        }
    }
}

void print_way(char array_station[LEN][MAX_LEN_STATION], int matrix[LEN][LEN], int n, int a, int b)
{
    printf("%d ", a + 1);

    for (int i = 0; i < n; i++)
    {
        if (matrix[a][i] != 0)
            printf(" -> %s", array_station[matrix[a][i]]);

        // printf(" -> %d", matrix[a][i]);
    }

    printf(" -> %d ", b + 1);
} // {
//     // printf("%s ", array_station[a]);

//     for (int i = 0; i < n; i++)
//     {
//         if (matrix[i][a] != 0)
//             printf(" -> %s", array_station[matrix[a][i]]);
//         // printf(" -> %d", matrix[a][i]);
//     }

//     // printf(" -> %s ", array_station[b]);
// }

void reset_function(int matrix[LEN][LEN], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = INFINITY;
}