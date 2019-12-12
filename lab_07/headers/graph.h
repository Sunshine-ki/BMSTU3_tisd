#ifndef _GRAPH_H

#define _GRAPH_H

#include <stdio.h>

#include "define.h"

void print_matrix(char array_station[LEN][MAX_LEN_STATION], int matrix[LEN][LEN], int n);

void reset_function(int matrix[LEN][LEN], int n);

void parser_matrix(FILE *f, char array_station[LEN][MAX_LEN_STATION], int matrix[LEN][LEN]);

void floid(int count, int matrix[LEN][LEN], int path[LEN][LEN], int dist[LEN][LEN]);

void show_path(int start, int end, int path[LEN][LEN], int dist[LEN][LEN], char station[LEN][MAX_LEN_STATION]);

#endif