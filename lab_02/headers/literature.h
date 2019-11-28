#ifndef LITERATUR_H

#define LITERATUR_H

#include <stdio.h>
#include <string.h>

#include "const.h"

void add_literature(literature array_struct[LEN_STRUCT], int *n);

void find_literature(literature array_struct[LEN_STRUCT], int n);

void del_literature(literature array_struct[LEN_STRUCT], int *n);

void shuffle_table(literature array_struct[LEN_STRUCT], int n);

void print_literature_key(literature array_struct[LEN_STRUCT], key_struct array_key[LEN_STRUCT], int n);

#endif
