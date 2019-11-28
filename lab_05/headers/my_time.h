#ifndef _MY_TIME_H_

#define _MY_TIME_H_

#include "struct.h"

#define EPS 1e-5
#define NUMBER 100

#define random(a, b) (double)(rand() % ((b - a) * NUMBER)) / NUMBER + a

#define max(a, b) a > b ? a : b

double min(double a, double b, double c);

void insert_queue(time_s *t, queue_s *queue_list1, queue_s *queue_list2, //
                  request_s *request, array_s *queue_array1, array_s *queue_array2);

void service_queue(time_s *t, queue_s *queue_list1, queue_s *queue_list2, int *i, //
                   request_s *request, array_s *queue_array1, array_s *queue_array2, int *flag);

void generic_time(time_s *t);

void sleep_time(time_s *t);

#endif