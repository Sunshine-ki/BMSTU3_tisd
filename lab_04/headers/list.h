#ifndef CDIO_H

#define CDIO_H

#include "struct.h"

int push(stack_s **stack_list, char word[MAX_LEN_WORD]);

void print_stack(stack_s *stack_list);

void del_adress(stack_s *stack_list, free_struct *array_address);

#define peek(a) a == NULL ? NULL : a->word

int pop(stack_s **stack_list);

void add_adress(stack_s **stack_list, free_struct *array_address);

void print_array_free_p(free_struct array_free);

void print_reverse(stack_s *stack_list);

void destruct(stack_s *stack_list);

#endif

// _________________________________________________ //
// char *peek(stack_s *stack_list);

// char *peek(stack_s *stack_list)
// {
//     return stack_list == NULL ? NULL : stack_list->word;
// }
// _________________________________________________ //
