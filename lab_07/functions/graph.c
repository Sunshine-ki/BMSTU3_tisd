#include "graph.h"

void print_matrix(int matrix[LEN][LEN], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == infinity)
                printf("   oo   ");
            else
                printf("   %d   ", matrix[i][j]);
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
                    matrix_p[i][j] = k + 1;
                }
            }
        }
    }
}

void print_way(int matrix[LEN][LEN], int n, int a, int b)
{
    printf("%d ", a + 1);

    for (int i = 0; i < n; i++)
    {
        if (matrix[a][i] != 0)
            printf(" -> %d", matrix[a][i]);
    }

    printf(" -> %d ", b + 1);
}

// int main(void)
// {
//     int matrix[LEN][LEN] = {{infinity, 3, infinity, infinity}, {8, infinity, 3, infinity}, {15, 5, infinity, 2}, {10, 7, 9, infinity}};
//     int matrix_p[LEN][LEN] = {0};

//     min_way_matrix(matrix, matrix_p, 4);

//     printf("Матрица:\n\n");
//     print_matrix(matrix, LEN);
//     printf("Матрица путей:\n\n");
//     print_matrix(matrix_p, LEN);
//     printf("\nПуть из 1 в 4 :\n");
//     print_way(matrix_p, LEN, 0, 3);

//     printf("\n");
//     return 0;
// }