#ifndef STRUCT_H

#define STRUCT_H

#define LAST 51000
#define MAX_COUNT_WORD 51000
#define FLAG 0

#define MAX_LEN_WORD 16
#define MAX_LEN_ARRAY_FREE 5000

#define OUT_OF_MEMORY -4
#define STACK_OVERFLOW -2
#define STACK_UNDERFLOW -3

#include <stdio.h>

typedef struct stack_s
{
    char word[MAX_LEN_WORD];
    struct stack_s *next;
} stack_s;

typedef struct
{
    stack_s *array[MAX_LEN_ARRAY_FREE];
    int len;
} free_struct;

typedef struct
{
    char word[MAX_COUNT_WORD][MAX_LEN_WORD];
    int size;
} array_stack_s;

#endif

// first_p; // Нижняя граница.
// last_p;  // Верхняя граница.