#ifndef _ARRAY_H_

#define _ARRAY_H_

void init_array(array_s *queue);

void insert_array(array_s *queue, int a);

#define isempty_array(q) q->first > q->last ? 1 : 0

int remove_array(array_s *queue);

void print_array(array_s *queue);

#endif