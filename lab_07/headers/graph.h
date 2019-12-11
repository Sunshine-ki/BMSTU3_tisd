#ifndef _GRAPH_H

#define _GRAPH_H

#include <stdio.h>

#include "define.h"

void print_way(char array_station[LEN][MAX_LEN_STATION], int matrix[LEN][LEN], int n, int a, int b);

void print_matrix(char array_station[LEN][MAX_LEN_STATION], int way[LEN][LEN], int n);

void min_way_matrix(int matrix[LEN][LEN], int matrix_p[LEN][LEN], int n); // Search

void reset_function(int matrix[LEN][LEN], int n);

#endif