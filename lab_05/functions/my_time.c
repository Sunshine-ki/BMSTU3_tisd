#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "my_time.h"
#include "colors.h"
#include "list.h"
#include "array.h"

#define EPS 1e-5
#define MAX 1e5

#define TIME_IN_QUEUE_1 random(1, 5)
#define TIME_IN_QUEUE_2 random(0, 3)

#define TIME_SERVICE_1 random(0, 4)
#define TIME_SERVICE_2 random(0, 1)

// queue_s *queue_list1; // 1 - 5 е.в.
// queue_s *queue_list2; // 0 - 3 е.в.
void generic_time(time_s *t)
{
    double temp;

    if (t->t_list_queue1 < EPS)
    {
        temp = TIME_IN_QUEUE_1;
        t->t_list_queue1 = temp;
        t->t_modeling_1 += temp;
    }

    if (t->t_list_queue2 < EPS)
    {
        temp = TIME_IN_QUEUE_2;
        t->t_list_queue2 = temp;
        t->t_modeling_2 += temp;
    }
}

double min(double a, double b, double c)
{
    double min = a;

    if (a < EPS)
        a = MAX;
    if (b < EPS)
        b = MAX;
    if (c < EPS)
        c = MAX;

    if (b - min < EPS)
    {
        min = b;
    }
    if (c - min < EPS)
    {
        min = c;
    }
    return min;
}

void sleep_time(time_s *t)
{
    double mini = min(t->t_list_queue1, t->t_list_queue2, t->t_service_unit);
    // printf("mini: %f \n", mini);

    if (t->t_list_queue1 > EPS)
        t->t_list_queue1 -= mini;

    if (t->t_list_queue2 > EPS)
        t->t_list_queue2 -= mini;

    if (t->t_service_unit > EPS)
        t->t_service_unit -= mini;
}

void insert_queue(time_s *t, queue_s *queue_list1, queue_s *queue_list2, //
                  request_s *request, array_s *queue_array1, array_s *queue_array2)
{
    int a = 0;

    if (t->t_list_queue1 < EPS)
    {
        if (!count_elements(queue_list1))
        {
            init_list(queue_list1);
            init_array(queue_array1);
        }

        // a = random(10, 100);
        insert_list(queue_list1, a);
        insert_array(queue_array1, a);

        request->in_1 += 1;
        // request->new_q1 = TRUE;

        // red();
        // printf("COUNT %d ", count_elements(queue_list1));
        // printf("Я добавил элемент в 1 очередь\n");
        // white();
    }
    if (t->t_list_queue2 < EPS)
    {
        if (!count_elements(queue_list2))
        {
            init_list(queue_list2);
            init_array(queue_array2);
        }

        // a = random(10, 100);
        insert_list(queue_list2, a);
        insert_array(queue_array2, a);

        request->in_2 += 1;
        // request->new_q2 = TRUE;

        // yellow();
        // printf("COUNT %d ", count_elements(queue_list2));
        // printf("Я добавил элемент в 2 очередь\n");
        // white();
    }
}

void service_queue(time_s *t, queue_s *queue_list1, queue_s *queue_list2, int *i, //
                   request_s *request, array_s *queue_array1, array_s *queue_array2, int *flag)
{
    int a;
    double temp;

    if (t->t_service_unit < EPS) // Service empty.
    {
        if (count_elements(queue_list1))
        {
            temp = TIME_SERVICE_1;
            t->t_service_unit = temp;
            // t->t_modeling_1 += temp;
            t->t_waiting1 += remove_list(queue_list1);
            remove_array(queue_array1);
            (*i)++;
            *flag = TRUE;
            t->t_service_1 += temp;
            (request->out_1)++;

            // red();
            // printf("Я удалил элемент из 1 очереди\n");
            // white();
        }
        else if (count_elements(queue_list2))
        {
            temp = TIME_SERVICE_2;
            t->t_service_unit = temp;
            // t->t_modeling_2 += temp;
            t->t_waiting2 += remove_list(queue_list2);
            remove_array(queue_array2);
            t->t_service_2 += temp;
            (request->out_2)++;

            // yellow();
            // printf("Я удалил элемент из 2 очереди\n");
            // white();
        }
        else
        {
            request->new_q1 = TRUE;
            // if (request->new_q1)
            // t->delay += t->t_list_queue1;
            // if (request->new_q2)
            // t->delay += t->t_list_queue2;
        }
    }
}