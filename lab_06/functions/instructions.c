#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instructions.h"

// обход дерева,
// включение, исключение и поиск узлов,

void instruction_bst()
{
    blue();
    printf("\n\t\t\t\t\t\t\t\t\t\tМеню:\n\
    \t\t\t\t\t\t\t▍▹ 1. %-30s\n\
    \t\t\t\t\t\t\t▍▸ 2. %-30s\n\
    \t\t\t\t\t\t\t▍▹ 3. %-30s\n\
    \t\t\t\t\t\t\t▍▸ 4. %-30s\n\
    \t\t\t\t\t\t\t▍▹ 5. %-30s\n\
    \t\t\t\t\t\t\t▍▸ 0. %-30s\n",
           "Вывести дерево",
           "Добавить эелемент",
           "Удалить элемент",
           "Найти элемент",
           "Заполнить (Из файла)",
           "Выход");
    green();
    printf("\t\t\t\t\t\t\t\t\tВыберите действие: ");
    white();
}

void instruction_hash()
{
    blue();
    printf("\n\t\t\t\t\t\t\t\t\t\tМеню:\n\
    \t\t\t\t\t\t\t▍▹ 1. %-30s\n\
    \t\t\t\t\t\t\t▍▸ 2. %-30s\n\
    \t\t\t\t\t\t\t▍▹ 3. %-30s\n\
    \t\t\t\t\t\t\t▍▸ 4. %-30s\n\
    \t\t\t\t\t\t\t▍▹ 5. %-30s\n\
    \t\t\t\t\t\t\t▍▸ 0. %-30s\n",
           "Вывод",
           "Добавить эелемент",
           "Удалить элемент",
           "Найти элемент",
           "Заполнить (Из файла)",
           "Выход");
    green();
    printf("\t\t\t\t\t\t\t\t\tВыберите действие: ");
    white();
}

int instruction()
{
    blue();
    printf("\n\t\t\t\t\t\t\t\t\t\tМеню:\n\
    \t\t\t\t\t\t\t▍▹ 1. %-30s\n\
    \t\t\t\t\t\t\t▍▹ 2. %-30s\n\
    \t\t\t\t\t\t\t▍▸ 3. %-30s\n\
    \t\t\t\t\t\t\t▍▹ 4. %-30s\n\
    \t\t\t\t\t\t\t▍▸ 5. %-30s\n\
    \t\t\t\t\t\t\t▍▹ 6. %-30s\n\
    \t\t\t\t\t\t\t▍▸ 0. %-30s\n",
           "Вывод хеш-таблицы",
           "Вывод дерева",
           "Добавить элемент",
           "Удалить элемент",
           "Найти элемент",
           "Заполнить (Из файла)",
           "Выход");
    green();
    printf("\t\t\t\t\t\t\t\t\tВыберите действие: ");
    white();
}

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