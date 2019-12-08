#ifndef _BINARY_SEARCH_TREE_

#define _BINARY_SEARCH_TREE_

#include "struct.h"

bin_search_s *get_bin_search(char word[MAX_LEN_WORD], bin_search_s *parent);

void insert_bin_search(bin_search_s **head, char word[MAX_LEN_WORD]);

bin_search_s *find_bin_search(bin_search_s *parent, char word[MAX_LEN_WORD]);

void delete_bin_search(bin_search_s *root, char word[MAX_LEN_WORD]);

void remove_node_bin_search(bin_search_s *target);

bin_search_s *find_min_node(bin_search_s *root);

bin_search_s *find_max_node(bin_search_s *root);

void print_bin_search(bin_search_s *root, const char *dir, int level);

#endif