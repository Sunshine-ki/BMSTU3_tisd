#ifndef _LIST_H_

#define _LIST_H_

void init_list(queue_s *q);

void insert_list(queue_s *q, int num);

#define isempty_list(q) q->last ? 0 : 1

void print_list(queue_s *q);

int count_elements(queue_s *q);

int remove_list(queue_s *q);

list_s *addelem(list_s *lst, int number);

list_s *init(int a);

#endif