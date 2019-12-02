#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "struct.h"
#include "list.h"
#include "my_time.h"

#define ERROR_BUFFER -2

#define LEN 1000

list_s *remove_list_fragm(queue_s *q)
{
    list_s *temp;
    int num;

    if (isempty_list(q))
    {
        printf("Очередь пуста !\n");
        return 0;
    }

    num = q->first->data;
    temp = q->first;
    q->first = q->first->ptr;
    free(temp);

    return temp;
}

int main(void)
{
    queue_s *queue_list1;

    queue_list1 = (queue_s *)malloc(sizeof(queue_s *));

    init_list(queue_list1);

    list_s *p[1000] = {};

    time_s t = {0};

    for (int i = 0; i < LEN; i++)
    {
        insert_list(queue_list1, 10);
        p[i] = queue_list1->last;
        // printf("%p\n", p[i]);
    }

    puts("");
    for (int i = 0; i < LEN; i++)
    {
        if (count_elements(queue_list1))
        {
            // printf("%p\n", queue_list1->first);
            for (int i = 0; i < LEN; i++)
            {
                if (queue_list1->first == p[i])
                {
                    // printf("%p == %p\n", queue_list1->first, p[i]);
                    p[i] = NULL;
                    break;
                }
            }
            remove_list(queue_list1);
        }
    }

    puts("");
    for (int i = 0; i < LEN; i++)
    {
        if (p[i])
            printf("%p\n", p[i]);
    }

    return 0;
}