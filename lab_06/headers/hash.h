#ifndef _HASH_H

#define _HASH_H

#include <stdio.h>
#include "struct.h"

#define MAX_LEN_HASH_TABLE 100

#define REMAINDER_DIVISION 11 // 97 //11 // Остаток от деления.
#define COLLISION 10

#define TRUE 1
#define FALSE 0

int add_element_hash_table(FILE *f, hash_s **hash_table, char word[MAX_LEN_WORD]);

void del_element_hash_table(hash_s **hash_table, char word[MAX_LEN_WORD]);

value_s find_hash(hash_s **hash_table, char word[MAX_LEN_WORD]);

int output_hash_table(FILE *f, hash_s **hash_table);

int input_hash_table(FILE *f, hash_s **hash_table);

void destruct_hash_table(hash_s **hash_table);

int is_empty_hash_table(hash_s **hash_table);

int hash_function(char word[MAX_LEN_WORD]);

hash_s *add_list(char word[MAX_LEN_WORD]);

hash_s **create_hash_table();

#endif