#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "list.h"
#include "colors.h"

void init_list(queue_s *q)
{
    q->first = 0;
    q->last = 0;
}

void insert_list(queue_s *q, int num)
{
    if ((q->last == 0) && (q->first == 0))
    {
        q->last = init(num);
        q->first = q->last;
    }
    else
    {
        q->last = addelem(q->last, num);
    }
}

list_s *addelem(list_s *lst, int number)
{
    list_s *temp, *p;
    temp = (list_s *)malloc(sizeof(list_s));
    p = lst->ptr;
    lst->ptr = temp;

    temp->data = number;
    temp->ptr = p;
    return temp;
}

list_s *init(int a)
{
    list_s *lst = (list_s *)malloc(sizeof(list_s));
    lst->data = a;
    lst->ptr = NULL;
    return (lst);
}

void print_list(queue_s *q)
{

    if (isempty_list(q))
    {
        printf("Очередь пуста !\n");
        return;
    }
    for (list_s *i = q->first; i; i = i->ptr)
        printf("%d ", i->data);
    puts("");
    return;
}

int count_elements(queue_s *q)
{
    int count = 0;

    if (isempty_list(q))
        return count;
    for (list_s *i = q->first; i; i = i->ptr)
        count++;

    return count;
}

int remove_list(queue_s *q)
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

    return (num);
}