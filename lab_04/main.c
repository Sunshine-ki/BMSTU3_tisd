/*
Элементами стека являются слова.
ФРАГМЕНТАЦИЯ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"
#include "struct.h"
#include "colors.h"
#include "instruction.h"
#include "array.h"

#define ERROR_INPUT -1
#define ERROR_BUFFER -2
#define MAX_LEN_ANSWER 32

#define OK 0

int main(void)
{
    setbuf(stdout, NULL);

    int answer = -1;
    char answer_char[MAX_LEN_ANSWER];
    free_struct array_address = {0, 0};
    stack_s *stack_list = NULL;
    char new_word[MAX_LEN_WORD];
    FILE *f = NULL;
    char str[100];
    float t1, t2;
    float array_time[2] = {0};

    array_stack_s array_stack;
    array_stack.size = 0;

    // for (int i = 0; i < 12; i++)
    // {
    //     printf(" arr.size = %ld, i = %d\n", array_stack.size, i);
    //     push_array(&array_stack, "alala");
    // }
    // printf("\n  %ld", array_stack.size);

    // size_t flag;
    // printf("Реализация стека в виде списка или массива? список - 1 / массив 2\n");
    // if (scanf("%ld", &flag) != 1 || (flag != 0 && flag != 1))
    // {
    //     red();
    //     printf("Ваш ответ мне не понятен.\n Завершение программы.\n");
    //     white();
    //     return ERROR_INPUT;
    // }

    while (answer)
    {
        instruction();
        scanf("%s", answer_char);
        answer = atoi(answer_char);
        while (!answer)
        {
            if (strcmp(answer_char, "0") == 0)
                break;

            red();
            printf("\n\t\t\t\t\t\t\t\t\tВаш ответ мне не понятен.");
            green();
            printf("\n\t\t\t\t\t\t\t\t\tВыберите действие:");
            white();

            scanf("%s", answer_char);
            answer = atoi(answer_char);
        }

        switch (answer)
        {
        case 0:
            break;
        case 1:
            green();
            // printf("Введите cловa: (По окончанию ввода введите stop)\n");

            // while (strcmp(new_word, "stop") != OK)
            // {
            //     if (push(&stack_list, new_word) != OK)
            //     {
            //         printf("Ошибка!");
            //     }
            //     scanf("%s", new_word);
            // }
            // printf("Слова успешно записаны!");

            printf("Введите cлово: \n");
            scanf("%s", new_word);
            push_array(&array_stack, new_word);
            push(&stack_list, new_word);
            del_adress(stack_list, &array_address);
            white();
            break;
        case 2:
            add_adress(&stack_list, &array_address);
            // red();
            printf("%s", pop(&stack_list) == STACK_UNDERFLOW ? //
                             "\33[31mПри попытке удаления слова из списка произошел stack underflow"
                                                             : "\33[32mСлово успешно удалено из списка!");
            white();

            if (pop_array(&array_stack) == -1)
            {
                red();
                printf("\nПри попытке удаления слова из массива произошел stack underflow");
            }
            else
            {
                green();
                printf("\nСлово успешно удалено из массива!");
            }
            white();
            break;
        case 3:
            yellow();
            printf("СПИСОК:\n");
            print_stack(stack_list);
            printf("\nМАССИВ:\n\n");
            print_stack_array(array_stack);
            white();
            break;
        case 4:
            print_array_free_p(array_address);
            break;
        case 5:
            if (!stack_list)
            {
                red();
                printf("Список пуст!\n");
                white();
                break;
            }
            print_reverse(stack_list);
            break;
        case 6:
            if (!stack_list)
            {
                red();
                printf("Список пуст!\n");
                white();
                break;
            }
            destruct(stack_list);
            stack_list = NULL;
            printf("Очищено!\n");
            break;
        case 7:
            if (array_stack.size == 0)
            {
                red();
                printf("Массив пуст!\n");
                white();
            }
            else
            {
                printf("Массив очищен!\n");
                array_stack.size = 0;
            }
            break;
        case 8:
            printf("Выберите кол-во слов: 1 - 500 / 2 - 5000 / 3 - 10000 / 4 - 50000\n");
            scanf("%s", answer_char);
            answer = atoi(answer_char);
            while (!answer)
            {
                if (strcmp(answer_char, "0") == 0)
                    break;

                red();
                printf("\n\t\t\t\t\t\t\t\t\tВаш ответ мне не понятен.");
                green();
                printf("\n\t\t\t\t\t\t\t\t\tВыберите действие:");
                white();

                scanf("%s", answer_char);
                answer = atoi(answer_char);
            }
            switch (answer)
            {
            case 1:
                f = fopen("file/500.txt", "r");
                break;
            case 2:
                f = fopen("file/5000.txt", "r");
                break;
            case 3:
                f = fopen("file/10000.txt", "r");
                break;
            case 4:
                f = fopen("file/50000.txt", "r");
                break;
            default:
                red();
                printf("\n\t\t\t\t\t\t\t\t\tВаш ответ мне не понятен.");
                white();
                break;
            }

            t1 = clock();
            while (!feof(f))
            {
                strcpy(str, "\0");
                fscanf(f, "%s", str);
                if (push(&stack_list, str) != OK)
                {
                    printf("Ошибка!");
                }
            }
            while (pop(&stack_list) != STACK_UNDERFLOW)
            {
                ;
            }
            t2 = clock();
            array_time[0] = (t2 - t1) / (CLOCKS_PER_SEC * 1.0);

            if (FLAG)
            {
                red();
                // printf("%d", array_stack->size);
                printf("При поппытке записи слова в массив произошел stack overflow");
                white();
                break;
            }

            fseek(f, 0, 0);
            t1 = clock();
            while (!feof(f))
            {
                strcpy(str, "\0");
                fscanf(f, "%s", str);
                if (push_array(&array_stack, str) != OK)
                {
                    printf("Ошибка!");
                    break;
                }
            }
            while (pop_array(&array_stack) != -1)
            {
                ;
            }
            t2 = clock();
            array_time[1] = (t2 - t1) / (CLOCKS_PER_SEC * 1.0);

            printf("Время push и pop при реализация стека в виде списка: %f", array_time[0]);
            printf("\nВремя push и pop при реализация стека в виде массива: %f", array_time[1]);

            // printf("Время push и pop при реализация стека в виде списка: %f", array_time[0]);

            // printf("\nВремя push и pop при реализация стека в виде массива: %f", array_time[1]);

            break;
        // case 19:
        //     for (int i = 0; i < 535; i++)
        //     {
        //         push(&stack_list, "aaa");
        //         // print_stack(stack_list);
        //         // print_array_free_p(array_address);
        //         pop(&stack_list);
        //     }
        //     print_stack(stack_list);
        //     print_array_free_p(array_address);
        //     break;
        default:
            red();
            printf("\t\t\t\t\t\t\t\t\t Нет данного действия.\n");
            white();
            break;
        }
    }
    if (f)
        fclose(f);
    destruct(stack_list);
    printf("\n");
    return OK;
}