#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "list.h"

#define OK 0
#define TRUE 1
#define FALSE 0

#define ERROR_INPUT -1

int push(stack_s **stack_list, char new_word[MAX_LEN_WORD])
{
    stack_s *temp = (stack_s *)malloc(sizeof(stack_s));
    if (temp == NULL)
        return STACK_OVERFLOW;
    temp->next = *stack_list;
    strcpy(temp->word, new_word);
    *stack_list = temp;
    return OK;
}

int pop(stack_s **stack_list)
{
    if (*stack_list == NULL)
        return STACK_UNDERFLOW;

    stack_s *out = *stack_list;
    *stack_list = (*stack_list)->next;
    free(out);
    return OK;
}

void add_adress(stack_s **stack_list, free_struct *array_address)
{
    if (*stack_list == NULL)
        return;
    for (int i = 0; i < array_address->len; i++)
    {
        if (*stack_list == array_address->array[i])
            return;
    }
    array_address->array[array_address->len] = *stack_list;
    (array_address->len)++;
}

void del_adress(stack_s *stack_list, free_struct *array_address)
{
    stack_s *temp;

    for (int i = 0; i < array_address->len; i++)
    {
        // printf("\nstack_list : %p \n array_address->array[i] : %p\n", stack_list, array_address->array[i]);

        if (stack_list == array_address->array[i])
        {
            // printf("\nВершину нужно удалить!!!\n");
            for (int j = i; j < array_address->len; j++)
            {
                temp = array_address->array[j];
                array_address->array[j] = array_address->array[j + 1];
                array_address->array[j + 1] = temp;
            }
            (array_address->len)--;
        }
    }
}

void destruct(stack_s *stack_list)
{
    if (!stack_list)
        return;
    stack_s *temp = stack_list;
    stack_s *p = stack_list->next;

    while (TRUE)
    {
        free(temp);
        temp = p;
        if (temp == NULL)
            break;
        p = temp->next;
    }
}

void print_reverse(stack_s *stack_list)
{
    stack_s *temp = stack_list;
    while (temp)
    {
        printf("%s ", temp->word);
        temp = temp->next;
    }
}

void print_stack(stack_s *stack_list)
{
    stack_s *temp = stack_list;
    if (!temp)
    {
        printf("\nСписок пуст!\n");
        return;
    }
    printf("\n%16s   %10s\n\n", "stack:", "address");
    while (temp)
    {
        printf("%16s | %10p\n", temp->word, temp);
        temp = temp->next;
    }
}

void print_array_free_p(free_struct array_free)
{
    printf("Mассив свободных областей ");
    printf("%s", array_free.len ? ":\n" : "пуст");
    for (int i = 0; i < array_free.len; i++)
        printf("%5p\n", array_free.array[i]);
}