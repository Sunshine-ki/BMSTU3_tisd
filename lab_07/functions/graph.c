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
    for (int i = 0; i < n; i++) // k
    {
        for (int j = 0; j < n; j++) // u
        {
            for (int k = 0; k < n; k++) // v
            {
                if (i == j || i == k || j == k)
                    continue;
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    matrix_p[j][k] = matrix_p[j][i];
                    // path[u][v] = path[u][k];

                    // matrix_p[i][j] = k;
                    // printf("i = %d, j = %d, k = %d, matrix[i][j] %d > matrix[i][k] = %d  + matrix[k][j] = %d\n", i, j, k, matrix[i][j], matrix[i][k], matrix[k][j]);
                    // matrix_p[i][j] = k + 1;
                }
            }
        }
    }
}

void print_way(char array_station[LEN][MAX_LEN_STATION], int way[LEN][LEN], int n, int a, int b)
{
    printf("%s -> ", array_station[a]);

    while (way[a][b])
    {
        printf(" %s - > ", array_station[way[a][b]]);
        a = way[a][b];
    }

    printf("%s", array_station[b]);
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