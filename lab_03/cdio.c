#include <stdlib.h>
#include <string.h>

#include "headers/cdio.h"
#include "headers/colors.h"
#include "headers/define.h"

void create_sparse_matrix(matrix_t *struct_matrix, sparse_matrix_t sparse_matrix)
{
    // for (int i = 0)
}

int construct(matrix_t *struct_matrix)
{
    char str_answer[MAX_LEN_STR];

    printf("Введите количество строк: ");
    scanf("%s", str_answer);
    correct_input_integer(str_answer, &struct_matrix->row);
    while (struct_matrix->row < 0)
    {
        strcpy(str_answer, "NO");
        correct_input_integer(str_answer, &struct_matrix->row);
    }

    printf("Введите количество столбцов: ");
    scanf("%s", str_answer);
    correct_input_integer(str_answer, &struct_matrix->col);
    while (struct_matrix->col < 0)
    {
        strcpy(str_answer, "NO");
        correct_input_integer(str_answer, &struct_matrix->col);
    }

    return OK;
}

int input_matrix(matrix_t *struct_matrix)
{
    printf("Заполните матрицу:\n");

    char str_answer[MAX_LEN_STR];

    for (int i = 0; i < struct_matrix->row; i++)
        for (int j = 0; j < struct_matrix->col; j++)
        {
            scanf("%s", str_answer);
            if (strcmp(str_answer, "0") == 0)
            {
                struct_matrix->matrix[i][j] = 0;
                strcpy(str_answer, "\0");
                continue;
            }
            correct_input_integer(str_answer, &struct_matrix->matrix[i][j]);
            // scanf("%d", &struct_matrix->matrix[i][j]);
        }

    return OK;
}

int print_matrix(matrix_t struct_matrix)
{
    printf("\nВ каком формате...?\n");

    printf("row = %d col = %d\n", struct_matrix.row, struct_matrix.col);

    for (int i = 0; i < struct_matrix.row; i++)
    {
        for (int j = 0; j < struct_matrix.col; j++)
            printf("%d ", struct_matrix.matrix[i][j]);
        puts("");
    }
    return OK;
}

void correct_input_integer(char string_answer[MAX_LEN_STR], int *integer_answer)
{
    int temp = atoi(string_answer);

    while (!temp)
    {
        strcpy(string_answer, "\0");
        red();
        printf("Некорректный ввод\nВведите ещё раз: ");
        scanf("%s", string_answer);
        temp = atoi(string_answer);
    }

    *integer_answer = temp;
    white();
}