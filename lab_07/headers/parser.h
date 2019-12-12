#ifndef _PARSER_H

#define _PARSER_H

#include "define.h"

int input_array_station(FILE *f, char array_station[LEN][MAX_LEN_STATION]);

int find_station(char array_station[LEN][MAX_LEN_STATION], char station[MAX_LEN_STATION]);

void print_station(char array_station[LEN][MAX_LEN_STATION], int n);

int count_station(FILE *f);

#endif