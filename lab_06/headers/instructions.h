#ifndef INSTRUCTION_H

#define INSTRUCTION_H

#include <stdio.h>

#include "colors.h"

#define MAX_LEN_ANSWER 32

int scanf_answer()
{
    char answer_char[MAX_LEN_ANSWER];

    scanf("%s", answer_char);

    int answer = atoi(answer_char);
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

    white();
    return answer;
}

void instruction()
{
    blue();
    printf("\n\t\t\t\t\t\t\t\t\t\tМеню:\n\
    \t\t\t\t\t\t\t1. Вывести сбалансированное двоичное дерево или двоичном дереве поиска.\n\
    \t\t\t\t\t\t\t2. Вывести хеш-таблицу.\n\
    \t\t\t\t\t\t\t3. Обход дерева ???   .\n\
    \t\t\t\t\t\t\t4. Включение элемента в дерево .\n\
    \t\t\t\t\t\t\t5. Исключение элемента из дерева. .\n\
    \t\t\t\t\t\t\t6. Поиск узла в дереве.\n\
    \t\t\t\t\t\t\t7. Отсортировать .\n\
    \t\t\t\t\t\t\t8. Сравнить эффективность алгоритмов сортировки и посика.(в зависимости от высоты дерева и степени его ветвления.)\n\
    \t\t\t\t\t\t\t9. Сравнить эффективность поиска (в сбалансированном двоичном дереве, в двоичном дереве поиска и в хеш-таблице.\n\
    \t\t\t\t\t\t\t0. Выход.\n");
    green();
    printf("\t\t\t\t\t\t\t\t\tВыберите действие: ");
    white();
}

#endif