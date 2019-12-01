#include <string.h>

#include "hash.h"
#include "colors.h"

// typedef struct
// {
//     int hash_index;
//     value_s hash_value;
//     struct hash_s *next;
// } hash_s;

int hash_function(char word[MAX_LEN_WORD])
{
    int hash;

    int sum = 0;

    for (int i = 0; word[i]; i++)
    {
        sum += word[i];
    }

    return sum % REMAINDER_DIVISION;
}

int input_hash_table(FILE *f, hash_s *hash_table[MAX_LEN_HASH_TABLE])
{
    char word[MAX_LEN_WORD];
    int count = 0;
    int h;

    while (!feof(f) && fscanf(f, "%s", word))
    {
        h = hash_function(word);

        if (hash_table[h]->hash_index != EMPTY)
        {
            hash_s *i;

            for (i = hash_table[h]; i->next; i = hash_table[h]->next)
                ;
            // hash_s *temp;

            // strcpy(temp->hash_value.name, word);
            // temp->hash_index = h;
            // i->next = temp;
            // temp->next = NULL;
        }
        else
        {
            hash_table[h]->hash_index = h;
            strcpy(hash_table[h]->hash_value.name, word);
        }
        count++;
    }

    return count;
}

value_s find_hash(char word[MAX_LEN_WORD], hash_s hash_table[MAX_LEN_HASH_TABLE])
{
    value_s data = hash_table[hash_function(word)].hash_value;
    return data;
}

int output_hash_table(FILE *f, hash_s hash_table[MAX_LEN_HASH_TABLE])
{
    char word[MAX_LEN_WORD];
    hash_s *h;

    for (int i = 0; i < MAX_LEN_HASH_TABLE; i++)
    {
        if (hash_table[i].hash_index != EMPTY)
        {
            green();
            fprintf(f, "%d %d %s\n", i, hash_table[i].hash_index, hash_table[i].hash_value.name);
            // if (hash_table[i]->hash_index != EMPTY)
            // {
            //     hash_s *temp;

            //     for (h = hash_table[i]; i->next; i = hash_table[i]->next)
            //         ;
            // }
            // else
            // {
            //     hash_table[h]->hash_index = h;
            //     strcpy(hash_table[h]->hash_value.name, word);
            // }
            white();
        }
    }
}