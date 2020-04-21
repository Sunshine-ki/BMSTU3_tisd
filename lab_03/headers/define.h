#ifndef DEFINE_H

#define DEFINE_H

#define OK 0
#define MAX_LEN_STR 128
#define MAX_LEN_MATRIX 35

typedef struct
{
    int matrix[MAX_LEN_MATRIX][MAX_LEN_MATRIX];
    int row;
    int col;
} matrix_t;

typedef struct
{
    int n;                  // (row * col) + 1
    int a[MAX_LEN_MATRIX];  // Значения.
    int ia[MAX_LEN_MATRIX]; // Строки.
    int ja[MAX_LEN_MATRIX]; // Указатели, на начало строки.
} sparse_matrix_t;

#endif