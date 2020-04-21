#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/instruction.h"
#include "headers/literature.h"
#include "headers/const.h"
#include "headers/io.h"
#include "headers/sort.h"

int main(const int argc, const char **const argv)
{
    setbuf(stdout, NULL);
    int answer = -1;
    char answer_char[MAX_LEN_ANSWER];

    literature array_struct[LEN_STRUCT] = {0};
    key_struct array_key[LEN_STRUCT];

    FILE *f = fopen(argv[NAME_FILE], "r");
    int n = read_file_in_struct(f, array_struct);
    fclose(f);
    creature_array_key(array_struct, array_key, n);

    while (answer)
    {
        instruction();

        scanf("%s", answer_char);
        answer = atoi(answer_char);
        while (!answer)
        {
            if (strcmp(answer_char, "0") == 0)
                break;

            printf("\33[31m");
            printf("\n\t\t\t\t\t\t\t\t\tВаш ответ мне не понятен.");
            printf("\33[33m");
            printf("\n\t\t\t\t\t\t\t\t\tВыберите действие:");
            printf("\e[0m");

            scanf("%s", answer_char);
            answer = atoi(answer_char);
        }

        switch (answer)
        {
        case 0:
            break;
        case 1:
            print_strict(array_struct, n);
            break;
        case 2:
            print_array(array_key, n);
            break;
        case 3:
            find_literature(array_struct, n);
            break;
        case 4:
            add_literature(array_struct, &n);
            creature_array_key(array_struct, array_key, n);
            break;
        case 5:
            print_strict(array_struct, n);
            del_literature(array_struct, &n);
            creature_array_key(array_struct, array_key, n);
            break;
        case 6:
            sort_table(array_struct, n);
            print_strict(array_struct, n);
            // creature_array_key(array_struct, array_key, n);
            break;
        case 7:
            sort_key(array_key, n);
            print_array(array_key, n);
            print_literature_key(array_struct, array_key, n);
            break;
        case 8:
            sorting_results(array_struct, array_key, n);
            break;
        case 9:
            shuffle_table(array_struct, n);
            creature_array_key(array_struct, array_key, n);
            printf("\33[5m");
            printf("\n\t\t\t\t\t\t\t\t\t Таблица перемешена!\n");
            printf("\e[0m");
            break;
        default:
            printf("\33[31m");
            printf("\t\t\t\t\t\t\t\t\t Нет данного действия.\n");
            printf("\e[0m");

            // answer = 0;
            break;
        }
    }

    printf("\nЗавершение программы!\n");
    return OK;
}