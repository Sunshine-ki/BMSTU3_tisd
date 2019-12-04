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
    // char name[MAX_LEN_WORD];
    value_s hash_value;
    struct hash_s *next;
} hash_s;

typedef struct node_t
{
    char *value;         // значение в вершине
    unsigned int height; // высота дерева в данной вершине
    struct node_t *left;
    struct node_t *right;
    // конструктор вершины (то есть функция, которая создает вершину
    // со значением k)
    // node(int k) { key = k; left = right = 0; height = 1; }
    // node_t node = {value, height, left, right}
} node_t;

#endif