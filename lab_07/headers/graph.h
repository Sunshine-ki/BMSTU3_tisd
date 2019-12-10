#ifndef _GRAPH_H

#define _GRAPH_H

#include <stdio.h>

#include "struct.h"

void print_matrix(int matrix[LEN][LEN], int n);

void min_way_matrix(int matrix[LEN][LEN], int matrix_p[LEN][LEN], int n); // Search

void print_way(int matrix[LEN][LEN], int n, int a, int b);

#endif