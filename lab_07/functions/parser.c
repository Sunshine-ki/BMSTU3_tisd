#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "colors.h"

int find_station(char array_station[LEN][MAX_LEN_STATION], char station[MAX_LEN_STATION])
{
    for (int i = 0; i < LEN; i++)
    {
        if (!strcmp(array_station[i], station))
            return i;
    }

    return NOT_FOUND;
}

void parser_matrix(FILE *f, char array_station[LEN][MAX_LEN_STATION], int matrix[LEN][LEN])
{
    char station_first[MAX_LEN_STATION];
    char station_second[MAX_LEN_STATION];
    int length;
    int price;

    int count = 0;

    fseek(f, COUNT_INFO, 0);

    while (!feof(f))
    {
        fscanf(f, "%s -- %s [label=\" %d, %d \"];", station_first, station_second, &length, &price);

        if (!strcmp(station_first, "}") || !strcmp(station_second, "}"))
            break;

        matrix[find_station(array_station, station_first)][find_station(array_station, station_second)] = length + price;
        matrix[find_station(array_station, station_second)][find_station(array_station, station_first)] = length + price;

        // printf("%d = %s -- %d = %s\n", find_station(array_station, station_first), station_first, find_station(array_station, station_second), station_second);
        // printf("%s -- %s [label=\" %d, %d \"];\n", station_first, station_second, length, price);
    }
}

int input_array_station(FILE *f, char array_station[LEN][MAX_LEN_STATION])
{
    char station_first[MAX_LEN_STATION];
    char station_second[MAX_LEN_STATION];
    int length;
    int price;

    int count = 0;

    fseek(f, COUNT_INFO, 0);

    while (!feof(f))
    {
        fscanf(f, "%s -- %s [label=\" %d, %d \"];", station_first, station_second, &length, &price);

        if (!strcmp(station_first, "}") || !strcmp(station_second, "}"))
            break;

        if (find_station(array_station, station_first) == NOT_FOUND)
        {
            // printf("!%s", station_first);
            strcpy(array_station[count], station_first);
            count++;
        }

        if (find_station(array_station, station_second) == NOT_FOUND)
        {
            // printf("!!%s", station_second);
            strcpy(array_station[count], station_second);
            count++;
        }
    }

    return count;
}

void print_station(char array_station[LEN][MAX_LEN_STATION], int n)
{
    green();
    printf("Кол-во станций = %d\n\n", n);
    printf("Имеющиеся станции: \n\n");
    for (int i = 0; i < n; i++)
        printf("%2d : %s\n", i, array_station[i]);
    white();
}

int count_station(FILE *f)
{
    char station_first[MAX_LEN_STATION];
    char station_second[MAX_LEN_STATION];
    int price;
    int length;

    int count = 0;

    fseek(f, COUNT_INFO, 0);
    while (!feof(f))
    {
        fscanf(f, "%s -- %s [label=\" %d, %d \"];", station_first, station_second, &length, &price);
        if (!strcmp(station_first, "}") || !strcmp(station_second, "}"))
        {
            break;
        }
        printf("!%s --- %s\n", station_first, station_second);
        count++;
    }

    return count;
}