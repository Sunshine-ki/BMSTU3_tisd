#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instructions.h"

// "\t\t\t\t\t\t\t▍1. %140s▍", "Вывести сбалансированное двоичное дерево или двоичном дереве поиска.\n"\   
    // "\t\t\t\t\t\t\t▍2. %140s▍", "Вывести хеш-таблицу.\n"\
    // "\t\t\t\t\t\t\t▍3. %140s▍","Обход дерева.\n"\
    // "\t\t\t\t\t\t\t▍4. %140s▍","Включение элемента в дерево .\n"\
    // "\t\t\t\t\t\t\t▍5. %140s▍","Исключение элемента из дерева. .\n"\
    // "\t\t\t\t\t\t\t▍6. %140s▍","Поиск узла в дереве.\n"\
    // "\t\t\t\t\t\t\t▍7. %140s▍","Отсортировать .\n"\
    // "\t\t\t\t\t\t\t▍8. %140s▍","Сравнить эффективность алгоритмов сортировки и посика.(в зависимости от высоты дерева и степени его ветвления.)\n"\
    // "\t\t\t\t\t\t\t▍9. %140s▍","Сравнить эффективность поиска (в сбалансированном двоичном дереве, в двоичном дереве поиска и в хеш-таблице.\n"\
    // "\t\t\t\t\t\t\t▍0. %140s▍","Выход.\n");

void instruction()
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