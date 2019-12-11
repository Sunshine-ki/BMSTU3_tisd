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

int main(void)
{
    int matrix[LEN][LEN];
    int matrix_p[LEN][LEN] = {0}; // Матрица путей
    char array_station[LEN][MAX_LEN_STATION];

    FILE *f = fopen(FILE_NAME, "r");

    int count = input_array_station(f, array_station);
    reset_function(matrix, count);
    reset_function(matrix_p, count);

    print_station(array_station, count);

    parser_matrix(f, array_station, matrix);

    //___________________

    // for (int u = 0; u < count; ++u)
    //     for (int v = 0; v < count; ++v)
    //         if (matrix[u][v] || u == v)
    //         {
    //             matrix_p[u][v] = v;
    //             // dist[u][v] = matrix[u][v];
    //         }
    //         else
    //         {
    //             matrix_p[u][v] = LEN;
    //             // dist[u][v] = INFINITY;
    //         }
    //__________________

    // print_matrix(array_station, matrix, count);

    print_matrix(array_station, matrix, count);
    printf("Матрица путей: \n");
    print_matrix(array_station, matrix_p, count);

    min_way_matrix(matrix, matrix_p, count);

    print_matrix(array_station, matrix, count);
    printf("\n\nМатрица путей: \n");
    print_matrix(array_station, matrix_p, count);

    // printf("Из %s в %s Путь: \n", array_station[4], array_station[0]);
    // print_way(array_station, matrix_p, count, 0, 3);

    // strcpy(array_station[0], "Alice");
    // printf("!%s\n", array_station[0]);
    // min_way_matrix(matrix, matrix_p, 4);

    // printf("Матрица:\n\n");
    // print_matrix(matrix, LEN);
    // printf("Матрица путей:\n\n");
    // print_matrix(matrix_p, LEN);
    // printf("\nПуть из 1 в 4 :\n");
    // print_way(matrix_p, LEN, 0, 3);

    fclose(f);
    printf("\n");
    return OK;
}

// char in_station[MAX_LEN_STATION];
// char out_station[MAX_LEN_STATION];

// green();
// printf("Откуда: ");
// white();
// scanf("%s", in_station);

// green();
// printf("Куда: ");
// white();
// scanf("%s", out_station);

// green();
// printf("Самый быстрый и бюджетный путь:\n");

// system("xdg-open graph/graph.png");

// while (answer)
// {
//     instruction();
//     answer = scanf_answer();

//     switch (answer)
//     {
//     case 0:
//         /* code */
//         break;
//     case 1:
//         /* Найти путь*/
//         break;
//     case 2:
//         /* Вывести граф */
//         break;
//     case 3:
//         /* Вывести граф */
//         break;
//     case 4:
//         system("xdg-open graph.png");
//         /* Вывести граф */
//         break;

//     default:
//         red();
//         printf("\t\t\t\t\t\t\t\t\tНет данного действия!\n");
//         white();
//         break;
//     }
// }
