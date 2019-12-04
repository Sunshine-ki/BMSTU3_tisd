#include <string.h>
#include <stdlib.h>

#include "hash.h"
#include "colors.h"

void empty_hash_index(hash_s hash_table[MAX_LEN_HASH_TABLE])
{
    for (int i = 0; i < MAX_LEN_HASH_TABLE; i++)
        hash_table[i].hash_index = EMPTY;
}

int hash_function(char word[MAX_LEN_WORD])
{
    int sum = 0;

    for (int i = 0; word[i]; i++)
    {
        sum += word[i];
    }

    return sum % REMAINDER_DIVISION;
}

hash_s *add_list(char word[MAX_LEN_WORD])
{
    hash_s *temp = (hash_s *)malloc(sizeof(hash_s));

    strcpy(temp->hash_value.name, word);
    temp->hash_index = hash_function(word);
    temp->next = NULL;

    return temp;
}

void del_element_hash_table(FILE *f, hash_s hash_table[MAX_LEN_HASH_TABLE])
{
    char word[MAX_LEN_WORD]; // Слово, которое введет пользователь.

    green();
    printf("Введите слово, которое хотите удалить: ");
    white();
    fscanf(f, "%s", word);

    int h = hash_function(word);

    if (!strcmp(hash_table[h].hash_value.name, word))
    {
        free(hash_table[h]);
        hash_table[h] = *hash_table[h].next;
        // if (hash_table[h].next)
        // {
        //     hash_s *temp = hash_table[h].next;

        //     hash_table[h].hash_index = temp->hash_index;
        //     strcpy(hash_table[h].hash_value.name, temp->hash_value.name);
        //     hash_table[h].next = temp->next;
        // }
        else
        {
            hash_table[h].hash_index = EMPTY;
            strcpy(hash_table[h].hash_value.name, "");
        }

        green();
        printf("Слово удалено!\n");
        white();
        return;
    }

    // Если по данному хешу уже есть слово
    if (hash_table[h].next)
    {
        for (hash_s *t2, *t = hash_table[h].next; t; t = t->next)
        {
            if (!strcmp(t->hash_value.name, word))
            {
                printf("t = %s t2 = %s\n", t->hash_value.name, t2->hash_value.name);
                // data = t->hash_value;
                // hash_table[h].hash_index = t->hash_index;
                // strcpy(hash_table[h].hash_value.name, t->hash_value.name);
                // hash_table[h].next = t->next;
                break;
            }
            t2 = t;
        }

        green();
        printf("Слово удалено!\n");
        white();
        return;
    }

    red();
    printf("Данного слова нет.");
    white();
}

void add_element_hash_table(FILE *f, hash_s hash_table[MAX_LEN_HASH_TABLE])
{
    char word[MAX_LEN_WORD]; // Слово, которое введет пользователь.
    hash_s *i;

    green();
    printf("Введите слово, которое хотите добавить: ");
    white();
    fscanf(f, "%s", word);
    int h = hash_function(word);

    // Если по данному хешу уже есть слово
    if (hash_table[h].hash_index != EMPTY)
    {
        if (!hash_table[h].next)
            hash_table[h].next = add_list(word);
        else
        {
            for (i = hash_table[h].next; i->next; i = i->next)
                ;
            i->next = add_list(word);
        }
    }
    else
    {
        // По данному хешу записываем индекс. (Что-бы потом знать, что по данному хешу есть слово.)
        hash_table[h].hash_index = h;
        // Записываем слово по данному хешу.
        strcpy(hash_table[h].hash_value.name, word);
    }

    green();
    printf("Слово успешно добавлено!\n");
    white();
}

int input_hash_table(FILE *f, hash_s hash_table[MAX_LEN_HASH_TABLE])
{
    char word[MAX_LEN_WORD]; // Слово.
    int count = 0;           // Кол-во слов.
    int h;                   // Значение хеш-функции каждого слова.

    hash_s *i;

    // Итерируемся, пока не конец файла и записываем слово в word.
    while (!feof(f) && fscanf(f, "%s", word))
    {
        // Узнаём хеш слова. (Которое только что считали).
        h = hash_function(word);

        // Если по данному хешу уже есть слово
        if (hash_table[h].hash_index != EMPTY)
        {
            if (!hash_table[h].next)
                hash_table[h].next = add_list(word);
            else
            {
                for (i = hash_table[h].next; i->next; i = i->next)
                    ;
                i->next = add_list(word);
            }
        }
        else
        {
            // По данному хешу записываем индекс. (Что-бы потом знать, что по данному хешу есть слово.)
            hash_table[h].hash_index = h;
            // Записываем слово по данному хешу.
            strcpy(hash_table[h].hash_value.name, word);
        }

        // Считаем кол-во слов.
        count++;
    }

    // Возвращаем кол-во слов.
    return count;
}

value_s find_hash(char word[MAX_LEN_WORD], hash_s hash_table[MAX_LEN_HASH_TABLE])
{
    int h = hash_function(word);

    value_s data = {0};

    if (!strcmp(hash_table[h].hash_value.name, word))
        data = hash_table[h].hash_value;

    // Если по данному хешу уже есть слово

    for (hash_s *t = hash_table[h].next; t; t = t->next)
    {
        if (!strcmp(t->hash_value.name, word))
        {
            data = t->hash_value;
            break;
        }
    }

    return data;
}

int output_hash_table(FILE *f, hash_s hash_table[MAX_LEN_HASH_TABLE])
{
    char word[MAX_LEN_WORD];
    // hash_s *h;
    // hash_s *temp;

    // Итерируемся по всему массиву.
    for (int i = 0; i < MAX_LEN_HASH_TABLE; i++)
    {
        // Если есть слово, то выводим слово.
        if (hash_table[i].hash_index != EMPTY)
        {
            green();
            // fprintf(f, "%d %d %s ", i, hash_table[i].hash_index, hash_table[i].name);
            fprintf(f, "%d %s ", hash_table[i].hash_index, hash_table[i].hash_value.name);
            if (hash_table[i].next)
            {
                for (hash_s *t = hash_table[i].next; t; t = t->next)
                    fprintf(f, " %s ", t->hash_value.name);
            }
            puts("");
            white();
        }
    }
}