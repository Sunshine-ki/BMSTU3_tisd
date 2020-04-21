
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "struct.h"
#include "hash.h"
#include "colors.h"

#define FILE_OPEN_HASH "text/collision.txt"

#define OK 0

int main()
{
    FILE *f = fopen(FILE_OPEN_HASH, "r");
    int size_hash_table;
    int collision = 0;

    green();
    printf("Введите размерность таблицы: ");
    scanf("%d", &size_hash_table);
    white();

    fclose(f);
    puts("");
    return OK;
}

//
//
//
//
//
//
//
//
//
//
//
//
// int input_hash_table(FILE *f, hash_s **hash_table, int *collision)
// {
//     char word[MAX_LEN_WORD]; // Слово.
//     int count = 0;           // Кол-во слов.

//     // Итерируемся, пока не конец файла и записываем слово в word.
//     while (!feof(f) && fscanf(f, "%s", word))
//     {
//         // Добавляем элемент и считаем кол-во слов.
//         count += add_element_hash_table(f, hash_table, word, collision);
//     }

//     return count; // Возвращаем кол-во слов.
// }

// int hash_function(char word[MAX_LEN_WORD], int redmainder_division) //, int redmainder_division)
// {
//     int sum = 0;

//     for (int i = 0; word[i]; i++)
//     {
//         sum += word[i];
//     }

//     return sum % REMAINDER_DIVISION;
// }