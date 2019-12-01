#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "instructions.h"
#include "struct.h"
#include "hash.h"

int main(void)
{
    int answer = -1;

    FILE *f = fopen("text/text.txt", "r");
    hash_s hash_table[MAX_LEN_HASH_TABLE] = {0};

    for (int i = 0; i < MAX_LEN_HASH_TABLE; i++)
        hash_table[i].hash_index = EMPTY;

    printf("Count = %d\n", input_hash_table(f, hash_table));

    char word[MAX_LEN_WORD];

    // Поиск
    // green();
    // printf("Введите слово, которое нужно найти: ");
    // white();
    // scanf("%s", word);
    // value_s data = find_hash(word, hash_table);
    // printf("%s", data.name);

    output_hash_table(stdout, hash_table);

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
    //         //
    //         break;
    //     case 3:
    //         //
    //         break;
    //     case 4:
    //         //
    //         break;
    //     case 5:
    //         //
    //         break;
    //     case 6:
    //         //
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