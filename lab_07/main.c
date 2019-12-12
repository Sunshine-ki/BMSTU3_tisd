/*
Вариант 13.
В системе двусторонних дорог за проезд 
каждой дороги взимается некоторая пошлина.
Найти путь из города A в город B с
минимальной величиной S+P, где S - сумма
длин дорог пути, а P - сумма пошлин
проезжаемых дорог
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "instructions.h"
#include "define.h"
#include "colors.h"

#include "graph.h"
#include "parser.h"

#define OK 0

int main()
{
    char array_station[LEN][MAX_LEN_STATION];
    int station_start, station_end;
    int matrix[LEN][LEN]; // матрица смежности
    int path[LEN][LEN];   // матрица путей
    int dist[LEN][LEN];   // матрица расстояний
    int rc;

    FILE *f = fopen(FILE_NAME, "r");

    int count = input_array_station(f, array_station);

    parser_matrix(f, array_station, matrix);
    // print_matrix(array_station, matrix, count);

    // task();
    print_station(array_station, count);

    floid(count, matrix, path, dist);

    yellow();
    printf("\nДля выхода нажмите Ctrl + D\n");
    printf("S - сумма длин дорог пути\
    \nP - сумма пошлин проезжаемых дорог");
    white();

    while (1)
    {
        green();
        printf("\n\nВведите начальную и конечную вершину: (По индексу) ");
        white();
        rc = scanf("%d %d", &station_start, &station_end);
        if (rc == EOF)
        {
            green();
            printf("\nУспешное завершение программы!\n");
            white();
            break;
        }
        else if (rc != 2)
        {
            red();
            printf("\nНекорректный ввод!\nЗавершение программы!\n");
            white();
            break;
        }

        if (station_start < 0 || station_end < 0 //
            || station_start >= count || station_end >= count)
        {
            red();
            printf("\nНекорректный ввод станции!\n");
            white();
            print_station(array_station, count);
            continue;
        }
        show_path(station_start, station_end, path, dist, array_station);
    }

    fclose(f);
    return 0;
}
