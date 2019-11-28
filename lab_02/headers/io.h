#ifndef IO_H

#define IO_H

#include <stdio.h>
#include <string.h>

#include "const.h"

int read_file_in_struct(FILE *f, literature array_struct[LEN_STRUCT]);

int print_strict(literature array_struct[LEN_STRUCT], int n);

void creature_array_key(literature array_struct[LEN_STRUCT], key_struct array_key[LEN_STRUCT], int n);

void print_array(key_struct array_key[LEN_STRUCT], int n);

void cpy_array_struct(literature array_struct_copy[LEN_STRUCT], literature array_struct[LEN_STRUCT], int n);

#endif
