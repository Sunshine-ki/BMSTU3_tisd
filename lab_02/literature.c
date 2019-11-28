#include <stdlib.h>
#include <string.h>

#include "headers/literature.h"

void shuffle_table(literature array_struct[LEN_STRUCT], int n)
{
    literature temp;
    int index_1, index_2;

    for (int i = 0; i <= n * n; i++)
    {
        index_1 = rand() % (n + 1);
        index_2 = rand() % (n + 1);
        temp = array_struct[index_1];
        array_struct[index_1] = array_struct[index_2];
        array_struct[index_2] = temp;
    }

    for (int i = 0; i <= n; i++)
        array_struct[i].row = i;
}

void del_literature(literature array_struct[LEN_STRUCT], int *n)
{
    int answer = -1;
    char answer_char[MAX_LEN_ANSWER];
    literature temp;

    printf("\33[33m");
    printf("Введите индекс: ");
    printf("\e[0m");
    scanf("%s", answer_char);
    answer = atoi(answer_char);
    if (answer < 0)
        answer = 0;
    while (!answer)
    {
        if (strcmp(answer_char, "0") == 0)
            break;
        printf("\33[31m");
        printf("\nВаш ответ мне не понятен.");
        printf("\33[33m");
        printf("\nВведите индекс: ");
        printf("\e[0m");
        scanf("%s", answer_char);
        answer = atoi(answer_char);
        if (answer < 0)
            answer = 0;
    }
    if (answer > *n)
    {
        printf("\nСлишком большой индекс.\nВсего %d элементов", *n + 1);
        return;
    }
    printf("%d", answer);

    for (int i = answer; i < *n; i++)
    {
        temp = array_struct[i + 1];
        array_struct[i] = array_struct[i + 1];
        array_struct[i + 1] = temp;
    }
    (*n)--;
    for (int i = 0; i <= *n; i++)
        array_struct[i].row = i;
}

void add_literature(literature array_struct[LEN_STRUCT], int *n)
{
    int answer = -1;
    char answer_char[MAX_LEN_ANSWER];

    (*n)++;
    array_struct[*n].row = *n;

    printf("Введите имя автора (без пробелов): ");
    scanf("%s", answer_char);
    strcpy(array_struct[*n].surname, answer_char);
    strcpy(answer_char, EMPTY_STRING);

    printf("Введите название книги (без пробелов): ");
    scanf("%s", answer_char);
    strcpy(array_struct[*n].title, answer_char);
    strcpy(answer_char, EMPTY_STRING);

    printf("Введите издательство (без пробелов): ");
    scanf("%s", answer_char);
    strcpy(array_struct[*n].publishing_house, answer_char);
    strcpy(answer_char, EMPTY_STRING);

    printf("Введите количество страниц: ");
    scanf("%s", answer_char);
    answer = atoi(answer_char);
    if (answer < 0)
        answer = 0;
    while (!answer)
    {
        printf("\33[31m");
        printf("\nВаш ответ мне не понятен.");
        printf("\33[33m");
        printf("\nВведите количество страниц: ");
        printf("\e[0m");

        scanf("%s", answer_char);
        answer = atoi(answer_char);
        if (answer < 0)
            answer = 0;
    }
    array_struct[*n].number_pages = answer;

    printf("Введите вид литературы: \n(1 - Техническая)\n(2 - Художественная)\n(3 - Детская)\n");
    scanf("%s", answer_char);
    answer = atoi(answer_char);
    if (answer > 3 || answer < 1)
        answer = 0;
    while (!answer)
    {
        printf("\33[31m");
        printf("\nВаш ответ мне не понятен.");
        printf("\33[33m");
        printf("\nВведите вид литературы: ");
        printf("\e[0m");

        scanf("%s", answer_char);
        answer = atoi(answer_char);
        if (answer > 3 || answer < 1)
            answer = 0;
    }
    answer--;
    array_struct[*n].type = answer;

    if (array_struct[*n].type == 0)
    {
        printf("\nВведите отрасль: ");
        scanf("%s", answer_char);
        strcpy(array_struct[*n].type_literature.technical_type.industry, answer_char);
        strcpy(answer_char, EMPTY_STRING);

        printf("Отечественная ? (да / нет) ");
        scanf("%s", answer_char);
        while (strcmp(answer_char, "да") && strcmp(answer_char, "нет"))
        {
            strcpy(answer_char, EMPTY_STRING);
            printf("\33[31m");
            printf("\nВаш ответ мне не понятен.");
            printf("\33[33m");
            printf("\nОтечественная ? (да / нет) ");
            scanf("%s", answer_char);
        }
        array_struct[*n].type_literature.technical_type.domestic = strcmp(answer_char, "да") ? 0 : 1;
        strcpy(answer_char, EMPTY_STRING);

        printf("Переводная ? (да / нет) ");
        scanf("%s", answer_char);
        while (strcmp(answer_char, "да") && strcmp(answer_char, "нет"))
        {
            strcpy(answer_char, EMPTY_STRING);
            printf("\33[31m");
            printf("\nВаш ответ мне не понятен.");
            printf("\33[33m");
            printf("\nПереводная ? (да / нет) ");
            scanf("%s", answer_char);
        }
        array_struct[*n].type_literature.technical_type.transferable = strcmp(answer_char, "да") ? 0 : 1;
        strcpy(answer_char, EMPTY_STRING);

        printf("Введите год издания: \n(от 0 до 2019)\n");
        scanf("%s", answer_char);
        answer = atoi(answer_char);
        if (answer > 2019 || answer < 0)
            answer = 0;
        while (!answer)
        {
            printf("\33[31m");
            printf("\nВаш ответ мне не понятен.");
            printf("\33[33m");
            printf("Введите год издания: \n(от 0 до 2019)\n");
            printf("\e[0m");

            scanf("%s", answer_char);
            answer = atoi(answer_char);
            if (answer > 2019 || answer < 0)
                answer = 0;
        }

        strcpy(answer_char, EMPTY_STRING);
        array_struct[*n].type_literature.technical_type.year_publication = answer;
    }
    else if (array_struct[*n].type == 1)
    {
        printf("Введите тип литературы: \n(1 - роман)\n(2 - пьеса)\n(3 - стихи)\n");
        scanf("%s", answer_char);
        answer = atoi(answer_char);
        if (answer > 3 || answer < 1)
            answer = 0;
        while (!answer)
        {
            printf("\33[31m");
            printf("\nВаш ответ мне не понятен.");
            printf("\33[33m");
            printf("\nВведите тип литературы: ");
            printf("\e[0m");

            scanf("%s", answer_char);
            answer = atoi(answer_char);
            if (answer > 3 || answer < 1)
                answer = 0;
        }
        answer--;
        array_struct[*n].type_literature.fiction_type = answer;
        // strcpy(answer_char, EMPTY_STRING);
        // fscanf(f, "%d", &array_struct[*n].type_literature.fiction_type);
    }
    else if (array_struct[*n].type == 2)
    {
        printf("Введите тип литературы: \n(1 - сказка)\n(2 - стихи)\n");
        scanf("%s", answer_char);
        answer = atoi(answer_char);
        if (answer > 2 || answer < 1)
            answer = 0;
        while (!answer)
        {
            printf("\33[31m");
            printf("\nВаш ответ мне не понятен.");
            printf("\33[33m");
            printf("\nВведите тип литературы: ");
            printf("\e[0m");

            scanf("%s", answer_char);
            answer = atoi(answer_char);
            if (answer > 2 || answer < 1)
                answer = 0;
        }
        answer--;
        array_struct[*n].type_literature.childrens_type = answer;
    }
}

void find_literature(literature array_struct[LEN_STRUCT], int n)
{
    printf("\33[33m");
    printf("\n\t\t\t\t\t\t\t\t\tВыберите отрасль: ");
    printf("\e[0m");
    char answer[MAX_LEN_ANSWER];
    int flag = FALSE;

    scanf("%s", answer);

    for (int i = 0; i <= n; i++)
    {
        if (array_struct[i].type == 0 && strcmp(array_struct[i].type_literature.technical_type.industry, answer) == 0 && array_struct[i].type_literature.technical_type.domestic == 1)
        {
            puts("");
            printf("|%-3d |%-15s |%-60s |%-60s |%-15d|", array_struct[i].row, array_struct[i].surname, array_struct[i].title, array_struct[i].publishing_house, array_struct[i].number_pages);
            printf("%15s", " Техническая");
            printf(" %10s", array_struct[i].type_literature.technical_type.industry);
            if (array_struct[i].type_literature.technical_type.domestic)
                printf(" %5s", "отечественная");
            if (array_struct[i].type_literature.technical_type.transferable)
                printf(" %5s", "переводная");
            printf(" %d ", array_struct[i].type_literature.technical_type.year_publication);
            flag = TRUE;
        }
    }

    if (!flag)
    {
        printf("\33[31m");
        printf("\n\t\t\t\t\t\t\t\t\t НЕТ ДАННОЙ ОТРАСЛИ!\n");
        printf("\e[0m");
    }
}

void print_literature_key(literature array_struct[LEN_STRUCT], key_struct array_key[LEN_STRUCT], int n)
{
    int answer = -1;
    char answer_char[MAX_LEN_ANSWER];

    printf("\nВывести таблицу по отсортированным ключам? (да / нет) ");
    scanf("%s", answer_char);
    while (strcmp(answer_char, "да") && strcmp(answer_char, "нет"))
    {
        strcpy(answer_char, EMPTY_STRING);
        printf("\33[31m");
        printf("\nВаш ответ мне не понятен.");
        printf("\33[33m");
        printf("\nОтечественная ? (да / нет) ");
        scanf("%s", answer_char);
        printf("\e[0m");
    }

    answer = strcmp(answer_char, "да") ? 0 : 1;
    puts("");
    if (answer)
    {
        printf("|%-3s |%-15s |%-60s |%-60s |%-15s|%-25s", "row", "surname", "title", "publishing_house", "number pages", "type literature");
        printf("\n\n");
        for (int i = 0; i <= n; i++)
        {
            printf("|%-3d |%-15s |%-60s |%-60s |%-15d|", array_struct[array_key[i].key].row, array_struct[array_key[i].key].surname,
                   array_struct[array_key[i].key].title, array_struct[array_key[i].key].publishing_house, array_struct[array_key[i].key].number_pages);

            switch (array_struct[array_key[i].key].type)
            {
            case 0:
                printf("%15s", " Техническая");
                printf(" %10s", array_struct[array_key[i].key].type_literature.technical_type.industry);
                if (array_struct[array_key[i].key].type_literature.technical_type.domestic)
                    printf(" %5s", "отечественная");
                if (array_struct[array_key[i].key].type_literature.technical_type.transferable)
                    printf(" %5s", "переводная");
                printf(" %d ", array_struct[array_key[i].key].type_literature.technical_type.year_publication);
                break;
            case 1:
                printf("%15s", " Художественная");

                if (array_struct[array_key[i].key].type_literature.fiction_type == 0)
                    printf("%10s", " роман");
                else if (array_struct[array_key[i].key].type_literature.fiction_type == 1)
                    printf("%10s", " пьеса");
                else if (array_struct[array_key[i].key].type_literature.fiction_type == 2)
                    printf("%10s", " стихи ");
                break;
            case 2:
                printf("%15s", "Детская");
                if (array_struct[array_key[i].key].type_literature.childrens_type == 0)
                    printf("%10s", " сказка");
                else if (array_struct[array_key[i].key].type_literature.childrens_type == 1)
                    printf("%10s", " стихи");
                break;
            }
            puts("");
        }
    }
}
