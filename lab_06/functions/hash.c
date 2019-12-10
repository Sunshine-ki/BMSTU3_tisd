#include <string.h>
#include <stdlib.h>

#include "hash.h"
#include "colors.h"

int is_simple(int a)
{
    for (int i = a - 1; i > 1; i--)
        if (a % i == 0)
            return FALSE;

    return TRUE;
}

int find_simple(int a)
{
    for (int i = a;; i++)
    {
        if (is_simple(i))
            return i;
    }
}

int is_empty_hash_table(hash_s **hash_table, int count)
{
    // Итерируемся по всему массиву.
    for (int i = 0; i < count; i++)
        if (hash_table[i])
            return FALSE;

    return TRUE;
}

int hash_function(char word[MAX_LEN_WORD]) //, int redmainder_division)
{
    int sum = 0;

    for (int i = 0; word[i]; i++)
    {
        sum += word[i];
    }

    return sum % REMAINDER_DIVISION;
}

int add_element_hash_table(FILE *f, hash_s **hash_table, char word[MAX_LEN_WORD], int *collision)
{
    // Узнаем хeш слова.
    int h = hash_function(word);
    int count = 1;

    hash_s *temp = hash_table[h];

    // Если по данному хешу уже есть слово.
    if (hash_table[h])
    {
        // printf("!%d\n", strcmp(temp->hash_value.name, word));
        if (strcmp(temp->hash_value.name, word) == 0)
            return 0;

        while (temp->next)
        {
            temp = temp->next;
            count++;
            // printf("!%d\n", strcmp(temp->hash_value.name, word));
            if (strcmp(temp->hash_value.name, word) == 0)
                return 2;

            // printf("Collision%d %d\n", count, *collision);
            if (count == COLLISION - 1)
            {
                (*collision)++;
            }
            if (*collision > 3)
            {
                red();
                // printf("Коллизия!(Hash = %d)\n", h);
                white();
                return 0;
            }
        }
        temp->next = add_list(word);
    }
    else
        hash_table[h] = add_list(word);

    return 1;
}

void del_element_hash_table(hash_s **hash_table, char word[MAX_LEN_WORD])
{
    // Узнаем хeш слова.
    int h = hash_function(word);

    hash_s *out;

    if (!hash_table[h])
    {
        red();
        printf("Нет данного слова!");
        white();
        return;
    }

    if (!strcmp(word, hash_table[h]->hash_value.name))
    {
        out = hash_table[h];
        hash_table[h] = hash_table[h]->next;
        free(out);
        return;
    }

    hash_s *temp = hash_table[h];
    while (temp->next)
    {
        out = temp->next;
        if (!strcmp(word, out->hash_value.name))
        {
            temp->next = out->next;
            free(out);
            break;
        }
        temp = temp->next;
    }
}

int find_hash_test(hash_s *hash_table, char word[MAX_LEN_WORD], count_s *count_h)
{
    while (hash_table)
    {
        if (!strcmp(word, hash_table->hash_value.name))
        {
            count_h->count_hash_find++;
            return TRUE;
        }
        hash_table = hash_table->next;
    }

    return FALSE;
}

int find_hash(hash_s **hash_table, char word[MAX_LEN_WORD], count_s *count_h)
{
    int h = hash_function(word);

    while (hash_table[h])
    {
        if (!strcmp(word, hash_table[h]->hash_value.name))
        {
            return TRUE;
        }
        else
        {
            (count_h->count_hash_find)++;
        }

        hash_table[h] = hash_table[h]->next;
    }

    return FALSE;
}

int input_hash_table(FILE *f, hash_s **hash_table, int *collision)
{
    char word[MAX_LEN_WORD]; // Слово.
    int count = 0;           // Кол-во слов.

    // Итерируемся, пока не конец файла и записываем слово в word.
    while (!feof(f) && fscanf(f, "%s", word))
    {
        // Добавляем элемент и считаем кол-во слов.
        count += add_element_hash_table(f, hash_table, word, collision);
    }

    return count; // Возвращаем кол-во слов.
}

int output_hash_table(FILE *f, hash_s **hash_table, int count)
{
    char word[MAX_LEN_WORD];

    hash_s *temp;

    printf("%4s %25s\n\n", "HASH", "VALUES");

    // Итерируемся по всему массиву.
    for (int i = 0; i < count; i++)
    {
        // Если есть слово, то выводим слово.
        if (hash_table[i])
        {
            printf("%4d ", hash_table[i]->hash_index);
            temp = hash_table[i];
            // printf("%d ", temp->hash_index);
            while (temp)
            {
                printf(" -> %8s", temp->hash_value.name);
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
    strcpy(temp->name1, word);
    temp->hash_index = hash_function(word);
    temp->next = NULL;

    return temp;
}

void destruct_hash_table(hash_s **hash_table, int count)
{
    for (int i = 0; i < count; i++)
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

hash_s **create_hash_table(FILE *f, int *count)
{
    char word[MAX_LEN_WORD];

    while (!feof(f) && fscanf(f, "%s", word))
        (*count)++; // Cчитаем кол-во слов.

    return (hash_s **)malloc(sizeof(hash_s *) * (*count));
}