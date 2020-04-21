#ifndef _STRUCT_H_

#define _STRUCT_H_

#define MAX_LEN_WORD 32
#define EMPTY -1

typedef struct
{
    char name[MAX_LEN_WORD];
} value_s;

typedef struct hash_s
{
    int hash_index;
    char name1[MAX_LEN_WORD];
    value_s hash_value;
    struct hash_s *next;
} hash_s;

// ДДП _BINARY_SEARCH_TREE_
typedef struct bin_search_s
{
    char data[MAX_LEN_WORD];
    struct bin_search_s *left;
    struct bin_search_s *right;
    struct bin_search_s *parent;
} bin_search_s;

//АВЛ
typedef struct node_t
{
    char value[MAX_LEN_WORD]; // значение в вершине
    unsigned int height;      // высота дерева в данной вершине
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;

    // конструктор вершины (то есть функция, которая создает вершину
    // со значением k)
    // node(int k) { key = k; left = right = 0; height = 1; }
    // node_t node = {value, height, left, right}
} node_t;

typedef struct
{

    double time_hash_find_start;
    double time_hash_find_end;

    double time_hash_add_start;
    double time_hash_add_end;

    double time_bst_find_start;
    double time_bst_find_end;
    double time_avl_find_start;
    double time_avl_find_end;

    double time_bst_add_start;
    double time_bst_add_end;

    double time_file_add_start;
    double time_file_add_end;

    double time_avl_add_start;
    double time_avl_add_end;

    double time_balance_tree_start;
    double time_balance_tree_end;

} time_s;

typedef struct
{
    int count_hash_find;
    int count_bst_find;
    int count_avl_find;
} count_s;

#endif