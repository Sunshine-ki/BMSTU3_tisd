#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "instructions.h"
#include "struct.h"
#include "hash.h"

#define MAX_COUNT_COLLISIONS 10

int main(void)
{
    char word[MAX_LEN_WORD];
    int answer = -1;

    FILE *f = fopen("text/text.txt", "r");
    // hash_s hash_table[MAX_LEN_HASH_TABLE];
    hash_s **hash_table;
    hash_table = (hash_s **)malloc(sizeof(hash_s *) * 10);
    hash_table[0] = add_list("Alice");
    printf("%s", hash_table[0]->hash_value.name);
    printf("%d", hash_table[0]->hash_index);

    // empty_hash_index(hash_table);

    // printf("Count = %d\n", input_hash_table(f, hash_table));

    // while (answer)
    // {
    //     instruction();
    //     answer = scanf_answer();

    //     switch (answer)
    //     {
    //     case 0:
    //         break;
    //     case 1:
    //         //
    //         break;
    //     case 2:
    //         output_hash_table(stdout, hash_table);
    //         break;
    //     case 3:
    //         //
    //         break;
    //     case 4:
    //         add_element_hash_table(stdin, hash_table);
    //         break;
    //     case 5:
    //         del_element_hash_table(stdin, hash_table);
    //         break;
    //     case 6:
    //         // Поиск
    //         green();
    //         printf("Введите слово, которое нужно найти: ");
    //         white();
    //         scanf("%s", word);
    //         value_s data = find_hash(word, hash_table);
    //         if (!strcmp(data.name, ""))
    //             printf("\nНет данного слова.\n");
    //         else
    //             printf("Информация: %s.\n", data.name);
    //         break;
    //     case 7:
    //         //
    //         break;
    //     case 8:
    //         //
    //         break;
    //     case 9:
    //         //
    //         break;
    //     default:
    //         printf("\33[31m");
    //         printf("\t\t\t\t\t\t\t\t\t Нет данного действия.\n");
    //         printf("\e[0m");
    //         // answer = 0;
    //         break;
    //     }
    // }

    red();
    printf("\nЗавершение программы!\n");
    white();

    fclose(f);
    return 0;
}