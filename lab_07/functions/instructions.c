#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instructions.h"

int instruction()
{
    blue();
    printf("\n\t\t\t\t\t\t\t\t\t\tМеню:\n\
    \t\t\t\t\t\t\t▍▸ 1. %-30s\n\
    \t\t\t\t\t\t\t▍▹ 2. %-30s\n\
    \t\t\t\t\t\t\t▍▸ 3. %-30s\n\
    \t\t\t\t\t\t\t▍▹ 4. %-30s\n\
    \t\t\t\t\t\t\t▍▹ 0. %-30s\n",
           "Заполнить из файла. ? нужно ли...?",
           "Найти путь",
           "Вывести граф",
           " ... ",
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