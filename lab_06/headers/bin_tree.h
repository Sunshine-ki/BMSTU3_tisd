#ifndef _BIN_TREE_H_

#define _BIN_TREE_H_

#include "struct.h"

int input_tree(FILE *f, node_t **p);

node_t *find_avl(node_t *p, char word[MAX_LEN_WORD], count_s *count_all);

// node_t *find_avl(node_t *p, char word[MAX_LEN_WORD]);

void print_avl(node_t *root, const char *dir, int level);

node_t *create_node(char word[MAX_LEN_WORD]);

unsigned int height(node_t *p);

int balance_factor(node_t *p);

void fix_height(node_t *p);

node_t *rotate_right(node_t *p);

node_t *rotate_left(node_t *q);

node_t *balance(node_t *p);

node_t *insert(node_t *p, char word[MAX_LEN_WORD]); // вставка ключа k в дерево с корнем p

node_t *find_min(node_t *p); // поиск узла с минимальным ключом в дереве p

node_t *remove_min(node_t *p); // удаление узла с минимальным ключом из дерева p

node_t *remove_tree(node_t *p, char word[MAX_LEN_WORD]); // удаление ключа k из дерева p

node_t *balance_tree(bin_search_s *bts, node_t **tree_avl);

#endif