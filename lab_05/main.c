#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "struct.h"
#include "list.h"
#include "array.h"
#include "my_time.h"
#include "colors.h"

#define ERROR_INPUT -1
#define ERROR_BUFFER -2

int main(void)
{
    srand(time(NULL));

    double time_prog_start = clock();

    array_s *queue_array1 = (array_s *)malloc(sizeof(array_s));
    init_array(queue_array1);

    array_s *queue_array2 = (array_s *)malloc(sizeof(array_s));
    init_array(queue_array2);

    queue_s *queue_list1; // 1 - 5 е.в.
    queue_s *queue_list2; // 0 - 3 е.в.

    queue_list1 = (queue_s *)malloc(sizeof(queue_s *));
    queue_list2 = (queue_s *)malloc(sizeof(queue_s *));

    init_list(queue_list1);
    init_list(queue_list2);

    request_s request = {0};
    time_s t = {0};

    long long int len_q_1, len_q_2;
    float a;
    int flag = TRUE;

    long long int k = 0;

    for (int i = 0; i < 1000;)
    {
        // printf("__________________________\n");
        generic_time(&t);
        // printf("t.Q1 %f, t.Q2 %f, t.service %f ", t.t_list_queue1, t.t_list_queue2, t.t_service_unit);
        sleep_time(&t);
        // printf("\n После: Q1 %f, Q2 %f, service %f \n", t.t_list_queue1, t.t_list_queue2, t.t_service_unit);

        // request.new_q1 = FALSE;
        // request.new_q2 = FALSE;
        insert_queue(&t, queue_list1, queue_list2, &request, queue_array1, queue_array2);

        if (t.t_service_unit < EPS && count_elements(queue_list1) == 0 && count_elements(queue_list2) == 0)
        {
            t.delay += max(t.t_list_queue1, t.t_list_queue2);
            // printf("\n%f %f min =  %f \n", t.t_list_queue1, t.t_list_queue2, min(t.t_list_queue1, t.t_list_queue2, t.t_list_queue2));
        }

        // printf("Очередь 1 (Элементов: %d):\n", count_elements(queue_list1));
        // print_list(queue_list1);

        // printf("Очередь 2 (Элементов: %d):\n", count_elements(queue_list2));
        // print_list(queue_list2);

        service_queue(&t, queue_list1, queue_list2, &i, &request, queue_array1, queue_array2, &flag);
        // printf("I = %d\n", i);
        // printf("__________________________\n");
        // len_q_1 += count_elements(queue_list1);
        // len_q_2 += count_elements(queue_list2);
        request.len_queue1 += count_elements(queue_list1);
        request.len_queue2 += count_elements(queue_list2);
        k++;

        if (i % 100 == 0 && i && flag)
        {
            // printf("I = %d ", i);
            flag = FALSE;
            green();
            printf("______________________________________________\n\n");

            green();
            printf("Текущая длина первой очереди %d\n", count_elements(queue_list1));
            printf("Средняя длина первой очереди %lld\n", request.len_queue1 / k);
            printf("Кол-во вошедших в систему заявок 1-ого типа %d\n", request.in_1);
            printf("Кол-во вышедших из системы заявок 1-ого типа %d\n", request.out_1);

            printf("Cреднее время моделирования заявок 1-ого типа %f\n", t.t_modeling_1 / ((double)request.in_1));
            if (((double)request.out_1) > EPS)
                printf("Cреднее время обслуживания заявок 1-ого типа %f\n", t.t_service_1 / ((double)request.out_1));
            else
                printf("Нет среднего времени обслуживания заявок 1-ого типа\n");
            // printf("Cреднее время пребывания заявок 1-ого типа %f\n", // Cреднее время моделирования - cреднее время обслуживания.
            //    (t.t_modeling_1 / ((double)request.in_1)) - t.t_service_1 / ((double)request.out_1));
            // printf("Cреднее время пребывания заявок 1-ого типа %f\n", request.in_1);

            puts("");

            yellow();
            printf("Текущая длина второй очереди %d\n", count_elements(queue_list2));
            printf("Средняя длина второй очереди %lld\n", request.len_queue2 / k);
            printf("Кол-во вoшедших в систему заявок 2-ого типа %d\n", request.in_2);
            printf("Кол-во вышедших из системы заявок 2-ого типа %d\n", request.out_2);

            printf("Cреднее время моделирования заявок 2-ого типа %f\n", t.t_modeling_2 / ((double)request.in_2));
            if (((double)request.out_2) > EPS)
                printf("Cреднее время обслуживания заявок 1-ого типа %f\n", t.t_service_2 / ((double)request.out_2));
            else
                printf("Нет среднего времени обслуживания заявок 2-ого типа\n");

            // printf("Cреднее время пребывания заявок 2-ого типа %f\n", // Cреднее время моделирования - cреднее время обслуживания.
            //    (t.t_modeling_2 / ((double)request.in_2)) - t.t_service_2 / ((double)request.out_2));

            green();
            printf("______________________________________________\n\n\n");

            // system("sleep 0.3");
            white();
            request.len_queue1 = 0;
            request.len_queue2 = 0;
            k = 0;
        }
    }

    red();
    printf("______________________________________________\n\n");

    // green();
    blue();
    printf("Время моделирования %f\n", t.t_modeling_1 + t.t_service_1 + t.delay);
    // printf("Время моделирования заявок 1-ого типа %f\n", t.t_modeling_1);
    // printf("Время обработки заявок 1-ого типа %f\n", t.t_service_1);

    // printf("Время моделирования заявок 1-ого типа %f\n", t.t_expectation_1 * 1000);
    printf("Кол-во вошедших в систему заявок 1-ого типа %d\n", request.in_1);
    printf("Кол-во вышедших из системы заявок 1-ого типа %d\n", request.out_1); //request.in_1 - count_elements(queue_list1));

    // puts("");

    // yellow();
    printf("Кол-во вошедших в систему заявок 2-ого типа %d\n", request.in_2);
    printf("Кол-во вышедших из системы заявок 2-ого типа %d\n", request.out_2); //request.in_2 - count_elements(queue_list2));

    // blue();
    printf("Время простоя %f\n", t.delay);

    red();
    printf("______________________________________________\n\n\n");
    white();

    // puts("");
    // print_list(queue_list1);
    // puts("");
    // print_array(queue_array1);
    // puts("\n\n");
    // print_list(queue_list2);
    // puts("");
    // print_array(queue_array2);

    // while (queue_list1->first)
    // {
    //     remove_list(queue_list1);
    //     remove_array(queue_array1);
    // }

    // while (queue_list2->first)
    // {
    //     remove_list(queue_list2);
    //     remove_array(queue_array2);
    // }
    // free(queue_list1);
    // free(queue_list2);

    double time_prog_end = clock();

    // printf("Time progs %f\n", time_prog_end - time_prog_start);

    return 0;
}

// ПРИМЕР РАБОТЫ ОЧЕРЕДИ НА ОСНОВНЕ СТРУКУТРЫ СПИСКА //
// queue_s *q;
// int a;

// q = (queue_s *)malloc(sizeof(queue_s *));
// init_list(q);
// print_list(q);
// for (int i = 0; i < 8; i++)
// {
//     printf("Введите элемент очереди: ");
//     scanf("%d", &a);
//     insert_list(q, a);
// }
// printf("\n");
// print_list(q);
// while (q->first)
// {
//     a = remove_list(q);
//     printf("\nУдален элемент %d\n", a);
//     print_list(q);
// }
//____________________________________________________//

// ПРИМЕР РАБОТЫ ОЧЕРЕДИ НА ОСНОВНЕ СТРУКУТРЫ МАССИВА //
// array_s *q;
// int a;

// q = (array_s *)malloc(sizeof(array_s));
// init_array(q);
// print_array(q);
// for (int i = 0; i < 8; i++)
// {
//     printf("Введите элемент очереди: ");
//     scanf("%d", &a);
//     insert_array(q, a);
// }
// printf("\n");
// print_array(q);

// while (q->first <= q->last)
// {
//     a = remove_array(q);
//     printf("\nУдален элемент %d\n", a);
//     print_array(q);
// }
//____________________________________________________//