#include "headers/sort.h"
#include "headers/io.h"
#include "headers/literature.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void buble_sort_table(literature array_struct[LEN_STRUCT], int n)
{
    literature temp;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j < n; j++)
        {
            if (array_struct[j].number_pages > array_struct[j + 1].number_pages)
            {
                temp = array_struct[j];
                array_struct[j] = array_struct[j + 1];
                array_struct[j + 1] = temp;
            }
        }
}

void qs_table(literature array_struct[LEN_STRUCT], int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = array_struct[(left + right) / 2].number_pages;
        do
        {
            while (array_struct[left].number_pages < middle)
                left++;
            while (array_struct[right].number_pages > middle)
                right--;
            if (left <= right)
            {
                literature tmp = array_struct[left];
                array_struct[left] = array_struct[right];
                array_struct[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs_table(array_struct, first, right);
        qs_table(array_struct, left, last);
    }
}

void sort_table(literature array_struct[LEN_STRUCT], int n)
{
    int answer = -1;
    char answer_char[MAX_LEN_ANSWER];

    printf("Выберите сортировку: \n(1 - QuickSort)\n(2 -  Bubble_sort)\n");
    scanf("%s", answer_char);
    answer = atoi(answer_char);
    if (answer > 2 || answer < 1)
        answer = 0;
    while (!answer)
    {
        printf("\33[31m");
        printf("\nВаш ответ мне не понятен.");
        printf("\33[33m");
        printf("\nВыберите сортировку: ");
        printf("\e[0m");

        scanf("%s", answer_char);
        answer = atoi(answer_char);
        if (answer > 2 || answer < 1)
            answer = 0;
    }

    if (answer == 1)
        qs_table(array_struct, 0, n);
    else
        buble_sort_table(array_struct, n);

    for (int i = 0; i <= n; i++)
        array_struct[i].row = i;
}

void sort_key(key_struct array_struct_key[LEN_STRUCT], int n)
{
    int answer = -1;
    char answer_char[MAX_LEN_ANSWER];

    printf("Выберите сортировку: \n(1 - QuickSort)\n(2 -  Bubble_sort)\n");
    scanf("%s", answer_char);
    answer = atoi(answer_char);
    if (answer > 2 || answer < 1)
        answer = 0;
    while (!answer)
    {
        printf("\33[31m");
        printf("\nВаш ответ мне не понятен.");
        printf("\33[33m");
        printf("\nВыберите сортировку: ");
        printf("\e[0m");

        scanf("%s", answer_char);
        answer = atoi(answer_char);
        if (answer > 2 || answer < 1)
            answer = 0;
    }

    if (answer == 1)
        qs_sort_key(array_struct_key, 0, n);
    else
        buble_sort_key(array_struct_key, n);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qs_sort_key(key_struct array_key[LEN_STRUCT], int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = array_key[(left + right) / 2].count;
        do
        {
            while (array_key[left].count < middle)
                left++;
            while (array_key[right].count > middle)
                right--;
            if (left <= right)
            {
                swap(&array_key[left].count, &array_key[right].count);
                swap(&array_key[left].key, &array_key[right].key);
                left++;
                right--;
            }
        } while (left <= right);
        qs_sort_key(array_key, first, right);
        qs_sort_key(array_key, left, last);
    }
}

void buble_sort_key(key_struct array_key[LEN_STRUCT], int n)
{
    int temp;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j < n; j++)
        {
            if (array_key[j].count > array_key[j + 1].count)
            {
                swap(&array_key[j].count, &array_key[j + 1].count);
                swap(&array_key[j].key, &array_key[j + 1].key);
            }
        }
}

void sorting_results(literature array_struct[LEN_STRUCT], key_struct array_key[LEN_STRUCT], int n)
{
    literature array_struct_copy[LEN_STRUCT];
    key_struct array_key_copy[LEN_STRUCT];
    float array_time[4] = {0}; // 0 - qs_table 1 - bs_table 2 - qs_key 3 - bs_key
    clock_t t1, t2;

    cpy_array_struct(array_struct_copy, array_struct, n);
    creature_array_key(array_struct_copy, array_key_copy, n);
    // print_strict(array_struct_copy, n);

    // qs_table
    t1 = clock();
    qs_table(array_struct_copy, 0, n);
    t2 = clock();
    array_time[0] = (t2 - t1) / (CLOCKS_PER_SEC * 1.0);
    cpy_array_struct(array_struct_copy, array_struct, n);

    // buble_sort_table
    t1 = clock();
    buble_sort_table(array_struct_copy, n);
    t2 = clock();
    array_time[1] = (t2 - t1) / (CLOCKS_PER_SEC * 1.0);
    cpy_array_struct(array_struct_copy, array_struct, n);

    // qs_key
    t1 = clock();
    qs_sort_key(array_key_copy, 0, n);
    t2 = clock();
    array_time[2] = (t2 - t1) / (CLOCKS_PER_SEC * 1.0);
    creature_array_key(array_struct_copy, array_key_copy, n);

    // buble_sort_key
    t1 = clock();
    buble_sort_key(array_key_copy, n);
    t2 = clock();
    array_time[3] = (t2 - t1) / (CLOCKS_PER_SEC * 1.0);
    // cpy_array_struct(array_struct_copy, array_struct, n);

    printf("\33[92m\t  Результат:\n\
    \n      QuickSort     Bubble_sort\n\
    \ntable |%-10f|%10f\n\
    \nkey   |%-10f|%10f\e[0m",
           array_time[0], array_time[1], array_time[2], array_time[3]);

    printf("\n\n\33[33mРазница по времени (QuickSort_table / QuickSort_key): %.2f", array_time[0] / array_time[2]); // 0 - qs_table 1 - bs_table 2 - qs_key 3 - bs_key
    printf("\n\nРазница по времени (Bubble_sort_table / Bubble_sort_key): %.2f\e[0m", array_time[1] / array_time[3]);
    // shuffle_table();
}
