#ifndef _HASH_H

#define _HASH_H

#include <stdio.h>
#include "struct.h"

#define MAX_LEN_HASH_TABLE 100

#define REMAINDER_DIVISION 11 // 97 //11 // Остаток от деления.
#define COLLISION 3

#define TRUE 1
#define FALSE 0

int is_simple(int a);

int find_simple(int a);

int add_element_hash_table(FILE *f, hash_s **hash_table, char word[MAX_LEN_WORD], int *collision, int len);
// int add_element_hash_table(FILE *f, hash_s **hash_table, char word[MAX_LEN_WORD], int *collision);

// int add_element_hash_table(FILE *f, hash_s **hash_table, char word[MAX_LEN_WORD]);

void del_element_hash_table(hash_s **hash_table, char word[MAX_LEN_WORD], int len);

// void del_element_hash_table(hash_s **hash_table, char word[MAX_LEN_WORD]);
int find_hash(hash_s **hash_table, char word[MAX_LEN_WORD], count_s *count_h, int len);

// int find_hash(hash_s **hash_table, char word[MAX_LEN_WORD], count_s *count_h);

// int find_hash(hash_s **hash_table, char word[MAX_LEN_WORD]);

int output_hash_table(FILE *f, hash_s **hash_table, int count);

// int input_hash_table(FILE *f, hash_s **hash_table, int *collision);

// int input_hash_table(FILE *f, hash_s **hash_table);

void destruct_hash_table(hash_s **hash_table, int count);

int is_empty_hash_table(hash_s **hash_table, int count);

int input_hash_table(FILE *f, hash_s **hash_table, int *collision, int len);
// int hash_function(char word[MAX_LEN_WORD]); //, int redmainder_division);

hash_s *add_list(char word[MAX_LEN_WORD], int len);
// hash_s *add_list(char word[MAX_LEN_WORD]);

hash_s **create_hash_table(FILE *f, int *count);

int find_hash_test(hash_s *hash_table, char word[MAX_LEN_WORD], count_s *count_h);

#endif