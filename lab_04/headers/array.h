#ifndef ARRAY_H

#define ARRAY_H

#include "struct.h"

int push_array(array_stack_s *array_stack, char *word);

int pop_array(array_stack_s *array_stack);

void print_stack_array(array_stack_s array_stack);

int push_array_file(array_stack_s *array_stack, char *word);

#endif