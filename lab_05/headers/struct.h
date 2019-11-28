#ifndef _STRUCT_H_

#define _STRUCT_H_

#define MAX_LEN_ARRAY 2000

#define TRUE 1
#define FALSE 0

typedef struct list_s
{
    int data;
    struct list_s *ptr;
} list_s;

typedef struct
{
    list_s *first, *last;
} queue_s;

typedef struct
{
    int arr[MAX_LEN_ARRAY];
    int first, last;
} array_s;

typedef struct
{
    double t_list_queue1;
    double t_list_queue2;
    double t_service_unit;
    double t_expectation_1; // Время ожидания 1.
    double t_expectation_2; // Время ожидания 2.
    double t_modeling_1;    // Время моделирования заявок 1-ого типа.
    double t_modeling_2;    // Время моделирования заявок 2-ого типа.
    double t_service_1;     // Время обслуживания заявок первого типа.
    double t_service_2;     // Время обслуживания заявок второго типа.
    // double t_expectation1;  // Времени пребывания заявок 1 типа в очереди.
    // double t_expectation2;  // Времени пребывания заявок 2 типа в очереди.
    double delay; // Прсотой.

} time_s;

typedef struct
{
    int in_1;
    int in_2;
    int out_1;
    int out_2;
    long long int len_queue1;
    long long int len_queue2;
    int new_q1;
    int new_q2;
} request_s;

#endif