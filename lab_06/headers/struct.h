#ifndef _STRUCT_H_

#define _STRUCT_H_

#define MAX_LEN_WORD 32
#define EMPTY -1

typedef struct
{
    char name[MAX_LEN_WORD];
} value_s;

// hash table
typedef struct
{
    int hash_index;
    value_s hash_value;
    struct hash_s *next;
} hash_s;

#endif