#include <string.h>
#include <stdlib.h>

#include "hash.h"
#include "colors.h"

int hash_function(char word[MAX_LEN_WORD])
{
    int sum = 0;

    for (int i = 0; word[i]; i++)
    {
        sum += word[i];
    }

    return sum % REMAINDER_DIVISION;
}

void add_element_hash_table(FILE *f, hash_s **hash_table, char word[MAX_LEN_WORD])
{
    // Узнаем хeш слова.
    int h = hash_function(word);

    hash_s *temp = hash_table[h];

    // Если по данному хешу уже есть слово.
    if (hash_table[h])
    {
        while (temp->next)
            temp = temp->next;
        temp->next = add_list(word);
    }
    else
        hash_table[h] = add_list(word);
}

void del_element_hash_table(hash_s **hash_table, char word[MAX_LEN_WORD])
{
    // Узнаем хeш слова.
    int h = hash_function(word);

    hash_s *out;

    while (hash_table[h])
    {
        if (!strcmp(word, hash_table[h]->hash_value.name))
        {
            out = hash_table[h];
            hash_table[h] = hash_table[h]->next;
            break;
        }
        hash_table[h] = hash_table[h]->next;
    }
}

value_s find_hash(hash_s **hash_table, char word[MAX_LEN_WORD])
{
    value_s data = {0};

    // Узнаем хeш слова.
    int h = hash_function(word);

    hash_s *temp = hash_table[h];

    while (temp)
    {
        if (!strcmp(word, temp->hash_value.name))
        {
            data = temp->hash_value;
            break;
        }
        temp = temp->next;
    }

    return data;
}

int input_hash_table(FILE *f, hash_s **hash_table)
{
    char word[MAX_LEN_WORD]; // Слово.
    int count = 0;           // Кол-во слов.

    // Итерируемся, пока не конец файла и записываем слово в word.
    while (!feof(f) && fscanf(f, "%s", word))
    {
        add_element_hash_table(f, hash_table, word); // Добавляем элемент
        count++;                                     // Считаем кол-во слов.
    }

    return count; // Возвращаем кол-во слов.
}

int output_hash_table(FILE *f, hash_s **hash_table)
{
    char word[MAX_LEN_WORD];

    hash_s *temp;

    printf("Table:\n");

    // Итерируемся по всему массиву.
    for (int i = 0; i < MAX_LEN_HASH_TABLE; i++)
    {
        // Если есть слово, то выводим слово.
        if (hash_table[i])
        {
            temp = hash_table[i];
            // printf("%d ", temp->hash_index);
            while (temp)
            {
                printf("%d %s ", temp->hash_index, temp->hash_value.name);
                temp = temp->next;
            }
            puts("");
        }
    }
}

hash_s *add_list(char word[MAX_LEN_WORD])
{
    hash_s *temp = (hash_s *)malloc(sizeof(hash_s));

    strcpy(temp->hash_value.name, word);
    temp->hash_index = hash_function(word);
    temp->next = NULL;

    return temp;
}

void destruct_hash_table(hash_s **hash_table)
{
    for (int i = 0; i < MAX_LEN_HASH_TABLE; i++)
    {
        if (hash_table[i])
            while (hash_table[i])
            {
                // printf("delete %d %s", hash_table[i]->hash_index, hash_table[i]->hash_value.name);
                free(hash_table[i]);
                hash_table[i] = hash_table[i]->next;
            }
    }
}

hash_s **create_hash_table()
{
    return (hash_s **)malloc(sizeof(hash_s *) * MAX_LEN_HASH_TABLE);
}