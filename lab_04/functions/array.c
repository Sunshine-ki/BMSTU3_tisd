#include <string.h>

#include "array.h"
#include "colors.h"

#define ERROR -1
#define OK 0

int push_array(array_stack_s *array_stack, char *word)
{
    // printf(" %d ", array_stack->size);

    if (array_stack->size + 1 > LAST)
    {
        red();
        // printf("%d", array_stack->size);
        printf("При поппытке записи слова в массив произошел stack overflow");
        white();
        return ERROR;
    }
    strcpy(array_stack->word[array_stack->size], word);
    array_stack->size++;

    return OK;
}

int push_array_file(array_stack_s *array_stack, char *word)
{
    // printf(" %d ", array_stack->size);
    strcpy(array_stack->word[array_stack->size], word);
    array_stack->size++;

    return OK;
}

int pop_array(array_stack_s *array_stack)
{
    if (array_stack->size == 0)
    {

        // array_stack->size--;
        return -1;
    }
    array_stack->size--;

    return OK;
}

void print_stack_array(array_stack_s array_stack)
{
    // printf("%ld ", array_stack.size);
    if (!array_stack.size)
    {
        printf("Массив пуст!\n");
        return;
    }
    for (int i = array_stack.size - 1; i >= 0; i--)
    {
        printf("%20s\n", array_stack.word[i]);
    }
}