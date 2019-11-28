#ifndef CDIO_H

#define CDIO_H

#include "define.h"
#include <stdio.h>

int construct(matrix_t *matrix);

int input_matrix(matrix_t *struct_matrix);

int print_matrix(matrix_t struct_matrix);

void correct_input_integer(char string_answer[MAX_LEN_STR], int *integer_answer);

void create_sparse_matrix(matrix_t *struct_matrix, sparse_matrix_t sparse_matrix);

#endif