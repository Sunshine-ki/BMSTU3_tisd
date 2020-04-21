#include <stdio.h>

#include "headers/io.h"

void creature_array_key(literature array_struct[LEN_STRUCT], key_struct array_key[LEN_STRUCT], int n)
{
    for (int i = 0; i <= n; i++)
    {
        array_key[i].key = i;
        array_key[i].count = array_struct[i].number_pages;
    }
}

void print_array(key_struct array_key[LEN_STRUCT], int n)
{
    printf("    i    ID   Поле\n\n");
    for (int i = 0; i <= n; i++)
        printf("|%5d|%5d |%5d|\n", i, array_key[i].key, array_key[i].count);
}

int read_file_in_struct(FILE *f, literature array_struct[LEN_STRUCT])
{
    int i;
    char temp[MAX];

    for (i = 0;; i++)
    {
        array_struct[i].row = i;
        fscanf(f, "%s %s %s %d %d", array_struct[i].surname, array_struct[i].title, array_struct[i].publishing_house, &array_struct[i].number_pages, &array_struct[i].type);
        if (array_struct[i].type == 0)
        {
            fscanf(f, "%s %d %d %d", array_struct[i].type_literature.technical_type.industry, &array_struct[i].type_literature.technical_type.domestic,
                   &array_struct[i].type_literature.technical_type.transferable, &array_struct[i].type_literature.technical_type.year_publication);
        }
        else if (array_struct[i].type == 1)
        {
            fscanf(f, "%d", &array_struct[i].type_literature.fiction_type);
        }
        else if (array_struct[i].type == 2)
        {
            fscanf(f, "%d", &array_struct[i].type_literature.childrens_type);
        }
        // array_struct[i].number_pages = atoi(temp);

        if (feof(f))
            break;
    }
    return i;
}

int print_strict(literature array_struct[LEN_STRUCT], int n)
{
    printf("|%-3s |%-15s |%-60s |%-60s |%-15s|%-25s", "row", "surname", "title", "publishing_house", "number pages", "type literature");
    printf("\n\n");
    for (int i = 0; i <= n; i++)
    {
        printf("|%-3d |%-15s |%-60s |%-60s |%-15d|", array_struct[i].row, array_struct[i].surname, array_struct[i].title, array_struct[i].publishing_house, array_struct[i].number_pages);

        switch (array_struct[i].type)
        {
        case 0:
            printf("%15s", " Техническая");
            printf(" %10s", array_struct[i].type_literature.technical_type.industry);
            if (array_struct[i].type_literature.technical_type.domestic)
                printf(" %5s", "отечественная");
            if (array_struct[i].type_literature.technical_type.transferable)
                printf(" %5s", "переводная");
            printf(" %d ", array_struct[i].type_literature.technical_type.year_publication);
            break;
        case 1:
            printf("%15s", " Художественная");

            if (array_struct[i].type_literature.fiction_type == 0)
                printf("%10s", " роман");
            else if (array_struct[i].type_literature.fiction_type == 1)
                printf("%10s", " пьеса");
            else if (array_struct[i].type_literature.fiction_type == 2)
                printf("%10s", " стихи ");
            break;
        case 2:
            printf("%15s", "Детская");
            if (array_struct[i].type_literature.childrens_type == 0)
                printf("%10s", " сказка");
            else if (array_struct[i].type_literature.childrens_type == 1)
                printf("%10s", " стихи");
            break;
        }

        puts("");
    }
}

void cpy_array_struct(literature array_struct_copy[LEN_STRUCT], literature array_struct[LEN_STRUCT], int n)
{
    for (int i = 0; i <= n; i++)
    {
        array_struct_copy[i].row = array_struct[i].row;
        strcpy(array_struct_copy[i].surname, array_struct[i].surname);
        strcpy(array_struct_copy[i].title, array_struct[i].title);
        strcpy(array_struct_copy[i].publishing_house, array_struct[i].publishing_house);
        array_struct_copy[i].number_pages = array_struct[i].number_pages;
        array_struct_copy[i].type = array_struct[i].type;

        if (array_struct[i].type == 0)
        {
            strcpy(array_struct_copy[i].type_literature.technical_type.industry, array_struct[i].type_literature.technical_type.industry);
            array_struct_copy[i].type_literature.technical_type.domestic = array_struct[i].type_literature.technical_type.domestic;
            array_struct_copy[i].type_literature.technical_type.transferable = array_struct[i].type_literature.technical_type.transferable;
            array_struct_copy[i].type_literature.technical_type.year_publication = array_struct[i].type_literature.technical_type.year_publication;
        }
        else if (array_struct[i].type == 1)
        {
            array_struct_copy[i].type_literature.fiction_type = array_struct[i].type_literature.fiction_type;
        }
        else if (array_struct[i].type == 2)
        {
            array_struct_copy[i].type_literature.childrens_type = array_struct[i].type_literature.childrens_type;
        }
    }
}