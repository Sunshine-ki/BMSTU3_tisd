#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "instructions.h"
#include "struct.h"
#include "hash.h"

#define MAX_COUNT_COLLISIONS 10
#define LEN_HASH_TABLE 10

#define MODE_BALANCED_TREE 1
#define MODE_DDP 2
#define MODE_HASH_TABLE 3

int main(void)
{
    char word[MAX_LEN_WORD];
    int answer = -1;

    green();
    printf("Выберите с чем желаете работать:\n\
    \n1 - Сбалансированное дерево\
    \n2 - Двоичное дерево поиска (ДДП)\
    \n3 - Хеш-таблица\n");
    white();

    int mode = scanf_answer();
    if (mode > 3 || mode < 1)
    {
        red();
        printf("Нет данного действия");
        white();
    }

    FILE *f = fopen("text/text2.txt", "r");
    hash_s **hash_table = create_hash_table();

    while (answer)
    {
        instruction();
        answer = scanf_answer();

        switch (answer)
        {
        case 0:
            break;
        case 1:

            switch (mode)
            {
            case MODE_HASH_TABLE:
                output_hash_table(stdout, hash_table);
                break;
            case MODE_DDP:
                // ...
                break;
            case MODE_BALANCED_TREE:
                // ...
                break;
            }
            break;
        case 2:
            green();
            printf("Введите слово, которое хотели бы добавить: ");
            white();
            scanf("%s", word);
            add_element_hash_table(stdin, hash_table, word);
            break;
        case 3:
            green();
            printf("Введите слово, которое хотели бы удалить: ");
            white();
            scanf("%s", word);

            switch (mode)
            {
            case MODE_HASH_TABLE:
                del_element_hash_table(hash_table, word);
                break;
            case MODE_DDP:
                // ...
                break;
            case MODE_BALANCED_TREE:
                // ...
                break;
            }
            break;
        case 4:
            green();
            printf("Введите слово, которое нужно найти: ");
            white();
            scanf("%s", word);

            value_s data = {0};

            switch (mode)
            {
            case MODE_HASH_TABLE:
                data = find_hash(hash_table, word);
                break;
            case MODE_DDP:
                // data = ...;
                break;
            case MODE_BALANCED_TREE:
                // data = ...;
                break;
            }

            if (!strcmp(data.name, ""))
            {
                red();
                printf("\nНет данного элемента.\n");
                white();
            }
            else
            {
                green();
                printf("Информация: %s.\n", data.name);
                white();
            }
            break;
        case 5:

            switch (mode)
            {
            case MODE_HASH_TABLE:
                input_hash_table(f, hash_table);
                break;
            case MODE_DDP:
                // ...
                break;
            case MODE_BALANCED_TREE:
                // ...
                break;
            }
            break;
        default:
            printf("\33[31m");
            printf("\t\t\t\t\t\t\t\t\t Нет данного действия.\n");
            printf("\e[0m");
            break;
        }
    }

    green();
    printf("Завершение программы!\n");
    white();

    destruct_hash_table(hash_table);
    free(hash_table);

    fclose(f);
    return 0;
}