#ifndef SORT_H

#define SORT_H

#include "const.h"

void sort_table(literature array_struct[LEN_STRUCT], int n);

void buble_sort_table(literature array_struct[LEN_STRUCT], int n);

void qs_table(literature array_struct[LEN_STRUCT], int first, int last);

void sort_key(key_struct array_struct_key[LEN_STRUCT], int n);

void qs_sort_key(key_struct array_key[LEN_STRUCT], int first, int last);

void buble_sort_key(key_struct array_key[LEN_STRUCT], int n);

void sorting_results(literature array_struct[LEN_STRUCT], key_struct array_key[LEN_STRUCT], int n);

void swap(int *a, int *b);

#endif

// void qs(int *array, int first, int last)
// {
//     if (first < last)
//     {
//         int left = first, right = last, middle = array[(left + right) / 2];
//         do
//         {
//             while (array[left] < middle)
//                 left++;
//             while (array[right] > middle)
//                 right--;
//             if (left <= right)
//             {
//                 int tmp = array[left];
//                 array[left] = array[right];
//                 array[right] = tmp;
//                 left++;
//                 right--;
//             }
//         } while (left <= right);
//         qs(array, first, right);
//         qs(array, left, last);
//     }
// }