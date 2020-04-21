#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "array.h"
#include "colors.h"

void init_array(array_s *queue)
{
    queue->first = 1;
    queue->last = 0;
}

void insert_array(array_s *queue, int a)
{
    if (queue->last < MAX_LEN_ARRAY)
    {
        queue->last++;
        queue->arr[queue->last] = a;
    }
    else
    {
        red();
        printf("Очередь (для массива) полна!\n");
        white();
    }
}

int remove_array(array_s *queue)
{
    if (isempty_array(queue))
    {
        red();
        printf("Очередь (для массива) пуста!\n");
        white();
        return 0;
    }
    int a = queue->arr[queue->first];
    for (int i = queue->first; i < queue->last; i++)
        queue->arr[i] = queue->arr[i + 1];
    queue->last--;
    return a;
}

void print_array(array_s *queue)
{
    if (isempty_array(queue))
    {
        red();
        printf("Очередь (для массива) пуста !\n");
        white();
        return;
    }
    for (int i = queue->first; i <= queue->last; i++)
        printf("%d ", queue->arr[i]);
    return;
}