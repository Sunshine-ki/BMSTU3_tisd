#ifndef _HASH_H

#define _HASH_H

#include <stdio.h>
#include "struct.h"

#define REMAINDER_DIVISION 30 // ==  MAX_LEN_HASH_TABLE ???
#define MAX_LEN_HASH_TABLE 100

int output_hash_table(FILE *f, hash_s hash_table[MAX_LEN_HASH_TABLE]);

int input_hash_table(FILE *f, hash_s *hash_table[MAX_LEN_HASH_TABLE]);

value_s find_hash(char word[MAX_LEN_WORD], hash_s hash_table[MAX_LEN_HASH_TABLE]);

int hash_function(char word[MAX_LEN_WORD]);

#endif