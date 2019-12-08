#ifndef _BINARY_SEARCH_TREE_

#define _BINARY_SEARCH_TREE_

#include "struct.h"

bin_search_s *create_bin_search(char value[MAX_LEN_WORD], bin_search_s *parent);

bin_search_s *find_bin_search(bin_search_s *root, char value[MAX_LEN_WORD]);

void insert_bin_search(bin_search_s **head, char value[MAX_LEN_WORD]);

void delete_bin_search(bin_search_s **root, char value[MAX_LEN_WORD]);

void print_bin_search(bin_search_s *root, const char *dir, int level);

bin_search_s *find_min_bin_search(bin_search_s *root);

bin_search_s *find_max_bin_search(bin_search_s *root);

int input_bin_search(FILE *f, bin_search_s **root);

void remove_bin_search(bin_search_s *target);

#endif